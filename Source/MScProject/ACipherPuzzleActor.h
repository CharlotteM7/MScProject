// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "EnhancedInputSubsystems.h"
#include "ACipherPuzzleActor.generated.h"

class UWidgetComponent;
class UUserWidget;
class UWBP_PuzzleNotebookContainer;
class UWBP_CipherPuzzle1;
class UWBP_LetterPuzzle;


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPuzzleSolved);

UCLASS()
class MSCPROJECT_API AACipherPuzzleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AACipherPuzzleActor();

	UPROPERTY(EditAnywhere, Category = "Cipher")
	FString EncodedMessage;

	UPROPERTY(EditAnywhere, Category = "Cipher")
	FString CorrectSolution;

	UPROPERTY(EditAnywhere, Category = "Cipher")
	TSubclassOf<UUserWidget> CipherWidgetClass;

	UPROPERTY(BlueprintAssignable, Category = "Cipher")
	FOnPuzzleSolved OnSolved;

	UPROPERTY(EditAnywhere, Category = "Cipher")
	AActor* ActorToDestroy;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY()
	UUserWidget* CipherWidgetInstance;

	UPROPERTY(EditAnywhere, Category = "Cipher")
	TSubclassOf<UUserWidget> NotebookContainerClass;

	UPROPERTY()
	UUserWidget* ActiveContainerWidget;

	UPROPERTY()
	bool bIsSolved;

	UPROPERTY()
	bool bPuzzleUIActive = false;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	UFUNCTION(BlueprintCallable, Category = "Cipher")
	virtual void ActivatePuzzle();

	UFUNCTION(BlueprintCallable, Category = "Cipher")
	void SubmitSolution(const FString& PlayerInput);
	
	UFUNCTION(BlueprintCallable, Category = "Cipher")
	void ExitPuzzle();


};
