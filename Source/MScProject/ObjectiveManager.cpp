// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveManager.h"

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
    if (!Objectives.IsValidIndex(CurrentObjectiveIndex)) return;

    FObjective& Obj = Objectives[CurrentObjectiveIndex];
    if (!Obj.bIsComplete && Obj.RequiredClueID == ClueID)
    {
        Obj.NotesAfter.Add(FText::FromString(TEXT("You’ve found the clue — head back to the door.")));
        OnObjectiveUpdated.Broadcast(CurrentObjectiveIndex);
    }
}

void UObjectiveManager::NotifyPuzzleSolved(int32 Index)
{
    if (!Objectives.IsValidIndex(CurrentObjectiveIndex)) return;

    FObjective& Obj = Objectives[CurrentObjectiveIndex];
    if (Index == CurrentObjectiveIndex)
    {
        Obj.bIsComplete = true;
        CurrentObjectiveIndex++;
        OnObjectiveUpdated.Broadcast(CurrentObjectiveIndex);
    }
}
