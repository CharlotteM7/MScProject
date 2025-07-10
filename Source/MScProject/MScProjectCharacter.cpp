// Copyright Epic Games, Inc. All Rights Reserved.

#include "MScProjectCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "Clue.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AMScProjectCharacter

void AMScProjectCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (MenuWidgetClass)
	{
		// create & show menu
		MenuWidgetRef = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
		if (MenuWidgetRef)
		{
			MenuWidgetRef->AddToViewport();

			// lock controls to UI
			if (APlayerController* PC = Cast<APlayerController>(Controller))
			{
				PC->bShowMouseCursor = true;
				FInputModeUIOnly Im;
				Im.SetWidgetToFocus(MenuWidgetRef->TakeWidget());
				Im.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
				PC->SetInputMode(Im);
			}
			// actually pause the world
			UGameplayStatics::SetGamePaused(GetWorld(), true);
		}
	}
}


AMScProjectCharacter::AMScProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}


//////////////////////////////////////////////////////////////////////////
// Input

void AMScProjectCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AMScProjectCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMScProjectCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMScProjectCharacter::Look);

		// Interacting with objects
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMScProjectCharacter::Interact);

		// Viewing the notebook
		EnhancedInputComponent->BindAction(ViewAction, ETriggerEvent::Started, this, &AMScProjectCharacter::View);

		// Viewing the pause menu
		EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &AMScProjectCharacter::Pause);

	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AMScProjectCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMScProjectCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AMScProjectCharacter::Interact(const FInputActionValue& Value)
{
	
	// Trace in front of the player for interactable actors
	FVector CamLoc;
	FRotator CamRot;
	GetController<APlayerController>()->GetPlayerViewPoint(CamLoc, CamRot);

	FVector Start = CamLoc;
	FVector End = CamLoc + CamRot.Vector() * 1000.f;  // 1,000 units out

	FHitResult Hit;
	FCollisionQueryParams Params(NAME_None, /*bTraceComplex=*/true, this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		AActor* HitActor = Hit.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("Interact trace hit: %s"), HitActor
			? *HitActor->GetName()
			: TEXT("nullptr"));

		if (AACipherPuzzleActor* Puzzle = Cast<AACipherPuzzleActor>(HitActor))
		{
			UE_LOG(LogTemp, Warning, TEXT(" PuzzleActor branch"));
			Puzzle->ActivatePuzzle();
		}
		else if (AClue* Clue = Cast<AClue>(HitActor))
		{
			UE_LOG(LogTemp, Warning, TEXT(" Clue branch"));
			Clue->ActivateClue();
		}
		if (InteractionSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, InteractionSound, GetActorLocation());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Interact trace hit nothing"));
	}


}

void AMScProjectCharacter::View(const FInputActionValue& Value)
{
	if (NotebookWidgetRef && NotebookWidgetRef->IsInViewport())
	{
		NotebookWidgetRef->RemoveFromParent();
		NotebookWidgetRef = nullptr;
	}

	else if (NotebookWidgetClass)
	{
		NotebookWidgetRef = CreateWidget<UUserWidget>(GetWorld(), NotebookWidgetClass);
		if (NotebookWidgetRef)
		{
			NotebookWidgetRef->AddToViewport();
			NotebookWidgetRef->SetAnchorsInViewport(FAnchors(0, 0, 1, 1));
			NotebookWidgetRef->SetAlignmentInViewport(FVector2D(0, 0));
		}
	}
	if (ViewSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ViewSound, GetActorLocation());
	}
}



void AMScProjectCharacter::Pause(const FInputActionValue& Value)
{
	if (!MenuWidgetClass) return;
	const bool bIsPaused = UGameplayStatics::IsGamePaused(GetWorld());
	APlayerController* PC = Cast<APlayerController>(Controller);
	if (!PC) return;

	if (bIsPaused)
	{
		// Resume
		if (MenuWidgetRef && MenuWidgetRef->IsInViewport())
			MenuWidgetRef->RemoveFromParent();
		PC->bShowMouseCursor = false;
		PC->SetInputMode(FInputModeGameOnly());
		UGameplayStatics::SetGamePaused(GetWorld(), false);
	}
	else
	{
		// Pause
		if (!MenuWidgetRef)
			MenuWidgetRef = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
		if (MenuWidgetRef)
		{
			MenuWidgetRef->AddToViewport();
			PC->bShowMouseCursor = true;
			FInputModeUIOnly Im;
			Im.SetWidgetToFocus(MenuWidgetRef->TakeWidget());
			Im.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			PC->SetInputMode(Im);
		}
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}
