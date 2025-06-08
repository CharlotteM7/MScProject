// Copyright Epic Games, Inc. All Rights Reserved.

#include "MScProjectGameMode.h"
#include "MScProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMScProjectGameMode::AMScProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
