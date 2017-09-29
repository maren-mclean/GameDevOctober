// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GameDevOctoberPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameDevOctoberCharacter.h"
#include "HeroComponent.h"

AGameDevOctoberPlayerController::AGameDevOctoberPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AGameDevOctoberPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AGameDevOctoberPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Bind Actions to current Hero Abilities
	InputComponent->BindAction("Q_action", IE_Pressed, this, &AGameDevOctoberPlayerController::CastHeroQAbility);
	InputComponent->BindAction("W_action", IE_Pressed, this, &AGameDevOctoberPlayerController::CastHeroWAbility);
	InputComponent->BindAction("E_action", IE_Pressed, this, &AGameDevOctoberPlayerController::CastHeroEAbility);
	InputComponent->BindAction("R_action", IE_Pressed, this, &AGameDevOctoberPlayerController::CastHeroRAbility);


	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AGameDevOctoberPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AGameDevOctoberPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGameDevOctoberPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AGameDevOctoberPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AGameDevOctoberPlayerController::OnResetVR);
}

void AGameDevOctoberPlayerController::CastHeroQAbility() {
	UHeroComponent* CurrentHeroComponent = GetHeroComponent();
	CurrentHeroComponent->CastQAbility();
}

void AGameDevOctoberPlayerController::CastHeroWAbility() {
	UHeroComponent* CurrentHeroComponent = GetHeroComponent();
	CurrentHeroComponent->CastWAbility();
}

void AGameDevOctoberPlayerController::CastHeroEAbility() {
	UHeroComponent* CurrentHeroComponent = GetHeroComponent();
	CurrentHeroComponent->CastEAbility();
}

void AGameDevOctoberPlayerController::CastHeroRAbility() {
	UHeroComponent* CurrentHeroComponent = GetHeroComponent();
	CurrentHeroComponent->CastRAbility();
}

void AGameDevOctoberPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AGameDevOctoberPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AGameDevOctoberCharacter* MyPawn = Cast<AGameDevOctoberCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UNavigationSystem::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AGameDevOctoberPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AGameDevOctoberPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AGameDevOctoberPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AGameDevOctoberPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}
