// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnhancedInputSubsystems.h"
#include "ACipherPuzzleActor.generated.h"

class UWidgetComponent;
class UUserWidget;

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

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY()
	UUserWidget* CipherWidgetInstance;

	UPROPERTY()
	bool bIsSolved;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



public:	
	UFUNCTION(BlueprintCallable, Category = "Cipher")
	void ActivatePuzzle();

	UFUNCTION(BlueprintCallable, Category = "Cipher")
	void SubmitSolution(const FString& PlayerInput);
	
	UFUNCTION(BlueprintCallable, Category = "Cipher")
	void ExitPuzzle();

	UFUNCTION(BlueprintImplementableEvent, Category = "Cipher")
	void OnPuzzleSolved();

};
