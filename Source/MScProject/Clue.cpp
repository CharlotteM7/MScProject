// Clue.cpp
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

    if (bUIActive || !ClueWidgetClass) return;

    // Show widget & switch to UI input
    if (!ClueWidgetInstance)
    {
        ClueWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), ClueWidgetClass);
        if (!ClueWidgetInstance) return;
    }

    if (UFunction* SetOwnerFunc = ClueWidgetInstance->FindFunction(FName("ClueRef")))
    {
        struct FSetClueParams { AActor* Clue; };
        FSetClueParams Params;
        Params.Clue = this;
        ClueWidgetInstance->ProcessEvent(SetOwnerFunc, &Params);
    }

    ClueWidgetInstance->AddToViewport();
    bUIActive = true;

    if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
    {
        PC->bShowMouseCursor = true;
        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(ClueWidgetInstance->TakeWidget());
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
        PC->SetInputMode(InputMode);
    }

    // **Broadcast the event** so anyone listening (e.g. ObjectiveManager) can react
    OnClueFound.Broadcast(ClueID);
}

void AClue::ExitClue()
{
  
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