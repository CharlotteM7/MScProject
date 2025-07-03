// Updated Clue.cpp - matching the puzzle system pattern
#include "Clue.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h" 
#include "GameFramework/PlayerController.h"
#include "ObjectiveManager.h"

AClue::AClue()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AClue::ActivateClue()
{
    if (bUIActive || !ClueWidgetClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("ActivateClue skipped: already active or no widget class"));
        return;
    }

    bUIActive = true; // Mark as active once passed the gate

    // Always create fresh widget instance
    ClueWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), ClueWidgetClass);
    if (!ClueWidgetInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create ClueWidgetInstance!"));
        bUIActive = false;
        return;
    }
    // Set clue reference on the widget - using proper clue naming
    if (UFunction* SetOwnerFunc = ClueWidgetInstance->FindFunction(FName("SetClueRef")))
    {
        struct FSetOwnerParams { AActor* ClueRef; };
        FSetOwnerParams Params;
        Params.ClueRef = this;
        ClueWidgetInstance->ProcessEvent(SetOwnerFunc, &Params);
        UE_LOG(LogTemp, Warning, TEXT("Set ClueRef on clue widget"));
    }

    ClueWidgetInstance->AddToViewport();
    UGameplayStatics::SetGamePaused(GetWorld(), true);


    // Switch to UI input mode
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
    {
        PC->bShowMouseCursor = true;
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(ClueWidgetInstance->TakeWidget());
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        PC->SetInputMode(InputMode);
    }

    // Broadcast the event so anyone listening (e.g. ObjectiveManager) can react
    OnClueFound.Broadcast(ClueID);
    UE_LOG(LogTemp, Warning, TEXT("Clue activated: %s"), *ClueID.ToString());

   
    if (ACharacter* PC = UGameplayStatics::GetPlayerCharacter(this, 0))
    {
        if (UObjectiveManager* Mgr = PC->FindComponentByClass<UObjectiveManager>())
        {
            Mgr->NotifyClueFound(ClueID);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("ActivateClue: No ObjectiveManager on player"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("ActivateClue: No PlayerCharacter found"));
    }
}

void AClue::ExitClue()
{
    if (!bUIActive) return; // Already inactive

    // Remove widget from viewport
    if (ClueWidgetInstance && ClueWidgetInstance->IsInViewport())
    {
        UE_LOG(LogTemp, Warning, TEXT("Removing clue widget from viewport"));
        ClueWidgetInstance->RemoveFromParent();
        ClueWidgetInstance = nullptr; // Set to nullptr so it gets recreated next time
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
    UGameplayStatics::SetGamePaused(GetWorld(), false);

    bUIActive = false;
    UE_LOG(LogTemp, Warning, TEXT("Clue exited"));
}