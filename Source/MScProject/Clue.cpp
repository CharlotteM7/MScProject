// Clue.cpp
#include "Clue.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

AClue::AClue()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AClue::ActivateClue()
{

   
        UE_LOG(LogTemp, Warning, TEXT("ActivateClue() called on %s; WidgetClass is %s"),
            *GetName(),
            ClueWidgetClass
            ? *ClueWidgetClass->GetName()
            : TEXT("NULL"));

        if (bUIActive || !ClueWidgetClass)
        {
            UE_LOG(LogTemp, Warning, TEXT(" early-return; bUIActive=%d, widgetClass=%s"),
                bUIActive,
                ClueWidgetClass
                ? TEXT("valid")
                : TEXT("NULL"));
            return;
        }
   


    if (bUIActive || !ClueWidgetClass) return;

    // Show widget & switch to UI input
    if (!ClueWidgetInstance)
    {
        ClueWidgetInstance = CreateWidget<UUserWidget>(GetWorld(), ClueWidgetClass);
        if (!ClueWidgetInstance) return;
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
