// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GameDevOctoberGameMode.h"
#include "GameDevOctoberPlayerController.h"
#include "GameDevOctoberCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameDevOctoberGameMode::AGameDevOctoberGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGameDevOctoberPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}