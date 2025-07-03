// Clue.h
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "EnhancedInputSubsystems.h"
#include "ObjectiveManager.h"
#include "Clue.generated.h"


class UWidgetComponent;
class UUserWidget;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClueFound, FName, FoundClueID);

UCLASS()
class MSCPROJECT_API AClue : public AActor
{
    GENERATED_BODY()

public:
    AClue();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clue")
    FName ClueID;

    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> ClueWidgetClass;

    /** This event fires once when the clue is activated */
    UPROPERTY(BlueprintAssignable, Category = "Clue")
    FOnClueFound OnClueFound;

    UPROPERTY()
    bool bUIActive = false;

    UPROPERTY()
    UUserWidget* ClueWidgetInstance;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    UFUNCTION(BlueprintCallable, Category = "Clue")
    void ActivateClue();

    UFUNCTION(BlueprintCallable, Category = "Clue")
    void ExitClue();
};
