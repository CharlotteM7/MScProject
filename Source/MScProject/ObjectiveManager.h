// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objective.h"
#include "Components/ActorComponent.h"
#include "ObjectiveManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectiveUpdated, int32, NewObjectiveIndex);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MSCPROJECT_API UObjectiveManager : public UActorComponent
{
	GENERATED_BODY()

public: 
	UObjectiveManager();

	/** List of all objectives in order */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FObjective> Objectives;

	/** Index of the current active objective */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentObjectiveIndex = 0;

	/** Fired whenever we advance or update notes */
	UPROPERTY(BlueprintAssignable)
	FOnObjectiveUpdated OnObjectiveUpdated;

	/** Call this when player picks up a clue */
	UFUNCTION(BlueprintCallable)
	void NotifyClueFound(FName ClueID);

	/** Call this when a puzzle actor broadcasts “solved” */
	UFUNCTION(BlueprintCallable)
	void NotifyPuzzleSolved(int32 Index);

	/** Returns the active objective struct */
	UFUNCTION(BlueprintPure, Category = "Objectives")
	const FObjective& GetCurrentObjective() const;

		
};
