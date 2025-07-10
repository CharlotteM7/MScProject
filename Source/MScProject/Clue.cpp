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
 
        return;
    }

    bUIActive = true; // Mark as active once passed the gate

    // Always create fresh widget instance
    ClueWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), ClueWidgetClass);
    if (!ClueWidgetInstance)
    {
 
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
  
    }

    ClueWidgetInstance->AddToViewport();



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
  
}

void AClue::ExitClue()
{
    if (!bUIActive) return; // Already inactive

    // Remove widget from viewport
    if (ClueWidgetInstance && ClueWidgetInstance->IsInViewport())
    {

        ClueWidgetInstance->RemoveFromParent();
        ClueWidgetInstance = nullptr; 
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

    bUIActive = false;

}