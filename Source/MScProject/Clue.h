// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Clue.generated.h"

UCLASS()
class MSCPROJECT_API AClue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClue();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Clue")
	FName ClueID;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UFUNCTION()
    void OnOverlapBegin(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);

    /** Collision component to detect player */
    UPROPERTY(VisibleAnywhere, Category = "Clue")
    class UBoxComponent* CollisionVolume;

};
