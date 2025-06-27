// Fill out your copyright notice in the Description page of Project Settings.


#include "Clue.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "ObjectiveManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AClue::AClue()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create & configure collision volume
    CollisionVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionVolume"));
    CollisionVolume->InitBoxExtent(FVector(50.f));
    CollisionVolume->SetCollisionProfileName(TEXT("Trigger"));
    RootComponent = CollisionVolume;

    // Bind overlap event
    CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AClue::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AClue::BeginPlay()
{
	Super::BeginPlay();
	
}

void AClue::OnOverlapBegin(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    // Only proceed if it’s the player character
    if (ACharacter* PC = Cast<ACharacter>(OtherActor))
    {
        // Find their ObjectiveManager component
        if (UObjectiveManager* ObjMgr = PC->FindComponentByClass<UObjectiveManager>())
        {
            // Tell it we’ve found this clue
            ObjMgr->NotifyClueFound(ClueID);  // matches Objective.RequiredClueID :contentReference[oaicite:0]{index=0}

            // Optionally destroy or disable the clue so it can’t be re-collected
            Destroy();
        }
    }
}

