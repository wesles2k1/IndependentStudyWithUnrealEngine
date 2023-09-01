// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearningWithCPPGameMode.h"
#include "LearningWithCPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearningWithCPPGameMode::ALearningWithCPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
