// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveManager.h"
#include "Objective.h"

// Sets default values for this component's properties
UObjectiveManager::UObjectiveManager()
{
	
	PrimaryComponentTick.bCanEverTick = false;
}


const FObjective& UObjectiveManager::GetCurrentObjective() const
{
    return Objectives.IsValidIndex(CurrentObjectiveIndex)
        ? Objectives[CurrentObjectiveIndex]
        : Objectives.Last();
}

void UObjectiveManager::NotifyClueFound(FName ClueID)
{
    FObjective& Obj = Objectives[CurrentObjectiveIndex];
    if (!Obj.bIsComplete && Obj.RequiredClueID == ClueID)
    {
        Obj.bClueFound = true;                     
        OnObjectiveUpdated.Broadcast(CurrentObjectiveIndex);
    }
}


void UObjectiveManager::NotifyPuzzleSolved(int32 Index)
{
    // Validate the incoming Index, not the current one
    if (!Objectives.IsValidIndex(Index))
        return;

    FObjective& Obj = Objectives[Index];
    if (!Obj.bIsComplete)
    {
        // Mark it done
        Obj.bIsComplete = true;

        // Advance the current pointer
        CurrentObjectiveIndex = FMath::Clamp(Index + 1, 0, Objectives.Num() - 1);

        // Broadcast so the notebook pulls in the next NotesBefore/After
        OnObjectiveUpdated.Broadcast(CurrentObjectiveIndex);
    }
}

