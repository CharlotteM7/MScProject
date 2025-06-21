
#include "ACipherPuzzleActor.h"
#include "Components/Overlay.h"
#include "Components/OverlaySlot.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AACipherPuzzleActor::AACipherPuzzleActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AACipherPuzzleActor::BeginPlay()
{
    Super::BeginPlay();

}

void AACipherPuzzleActor::ActivatePuzzle()
{

    if (bIsSolved || bPuzzleUIActive)
    {
        UE_LOG(LogTemp, Warning, TEXT("ActivatePuzzle skipped: already solved or UI already active"));
        return;
    }

    bPuzzleUIActive = true; // Mark as active once passed the gate


    if (!CipherWidgetInstance)
    {
        CipherWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), CipherWidgetClass);
        if (!CipherWidgetInstance)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to create CipherWidgetInstance!"));
            return;
        }
    }

    if (CipherWidgetInstance->IsInViewport()) return;


    // Set puzzle actor on the widget
    if (UFunction* SetOwnerFunc = CipherWidgetInstance->FindFunction(FName("PuzzleActor")))
    {
        struct FSetOwnerParams { AActor* PuzzleRef; };
        FSetOwnerParams Params;
        Params.PuzzleRef = this;
        CipherWidgetInstance->ProcessEvent(SetOwnerFunc, &Params);
    }

    // Set encoded message
    if (UFunction* SetEncodedFunc = CipherWidgetInstance->FindFunction(FName("EncryptedMessage")))
    {
        struct FEncodedParams { FText Message; };
        FEncodedParams Params;
        Params.Message = FText::FromString(EncodedMessage);
        CipherWidgetInstance->ProcessEvent(SetEncodedFunc, &Params);
    }

    // Create container with notebook
    UUserWidget* ContainerWidget = CreateWidget<UUserWidget>(GetWorld(), NotebookContainerClass);
    if (!ContainerWidget) return;

    UOverlay* OverlayPanel = Cast<UOverlay>(ContainerWidget->WidgetTree->FindWidget(FName("Overlay")));
    if (!OverlayPanel) return;

    if (UOverlaySlot* OverlaySlot = Cast<UOverlaySlot>(OverlayPanel->AddChild(CipherWidgetInstance)))
    {
        OverlaySlot->SetHorizontalAlignment(HAlign_Fill);
        OverlaySlot->SetVerticalAlignment(VAlign_Fill);
    }

    ActiveContainerWidget = ContainerWidget;
    ActiveContainerWidget->AddToViewport();
    UE_LOG(LogTemp, Warning, TEXT("Notebook container created: %s"), *ContainerWidget->GetName());

    if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
    {
        PC->bShowMouseCursor = true;
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(CipherWidgetInstance->TakeWidget());
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        PC->SetInputMode(InputMode);
    }
}




void AACipherPuzzleActor::SubmitSolution(const FString& PlayerInput)
{
    if (!CipherWidgetInstance) return;

    UE_LOG(LogTemp, Warning, TEXT("SubmitSolution called"));
    UE_LOG(LogTemp, Warning, TEXT("Player input: %s | Correct: %s"), *PlayerInput, *CorrectSolution);

    FText Feedback;

    if (PlayerInput.Equals(CorrectSolution, ESearchCase::IgnoreCase))
    {
        bIsSolved = true;
        Feedback = FText::FromString("Correct!");

        // Destroy puzzle actor target (e.g. door)
        if (ActorToDestroy)
        {
            ActorToDestroy->Destroy();
        }

        // Cleanup notebook container
        if (ActiveContainerWidget && ActiveContainerWidget->IsInViewport())
        {
            UE_LOG(LogTemp, Warning, TEXT("Removing container: %s"), *ActiveContainerWidget->GetName());
            ActiveContainerWidget->RemoveFromParent();
            ActiveContainerWidget = nullptr;
        }

        // Restore input
        if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
        {
            PC->bShowMouseCursor = false;
            FInputModeGameOnly InputMode;
            PC->SetInputMode(InputMode);
        }

        OnSolved.Broadcast();
    }
    else
    {
        Feedback = FText::FromString("Try again.");
    }

    // Show feedback in UI
    if (UFunction* FeedbackFunc = CipherWidgetInstance->FindFunction(FName("ShowFeedbackMessage")))
    {
        struct FFeedbackParams { FText Feedback; };
        FFeedbackParams Params;
        Params.Feedback = Feedback;
        CipherWidgetInstance->ProcessEvent(FeedbackFunc, &Params);
    }
}




void AACipherPuzzleActor::ExitPuzzle()
{
    // Remove notebook container
    if (ActiveContainerWidget && ActiveContainerWidget->IsInViewport())
    {
        UE_LOG(LogTemp, Warning, TEXT("Exiting puzzle. Removing container: %s"), *ActiveContainerWidget->GetName());
        ActiveContainerWidget->RemoveFromParent();
        ActiveContainerWidget = nullptr;
    }

    // Remove puzzle widget if still around
    if (CipherWidgetInstance && CipherWidgetInstance->IsInViewport())
    {
        CipherWidgetInstance->RemoveFromParent();
        CipherWidgetInstance = nullptr;
    }

    // Restore input and mappings
    if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
    {
        PC->bShowMouseCursor = false;
        PC->SetInputMode(FInputModeGameOnly());

        if (ULocalPlayer* LP = PC->GetLocalPlayer())
        {
            if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LP))
            {
                Subsystem->AddMappingContext(DefaultMappingContext, 0);
            }
        }
    }

    bPuzzleUIActive = false;


}
