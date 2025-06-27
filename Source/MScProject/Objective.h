#pragma once

#include "CoreMinimal.h"
#include "Objective.generated.h"

USTRUCT(BlueprintType)
struct MSCPROJECT_API FObjective
{
	GENERATED_BODY()

	/** A short title shown in the notebook UI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	/** What the player needs to do */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ToSolveDescription;

	/** Optional ID of the clue they need to collect first */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName RequiredClueID;

	/** Optional ID of the puzzle Actor to solve */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName PuzzleActorTag;

	/** Notes shown before you’ve found the clue/started the puzzle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> NotesBefore;

	/** Notes shown once you’ve solved this objective */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> NotesAfter;

	/** Whether it’s been completed */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsComplete = false;
};
