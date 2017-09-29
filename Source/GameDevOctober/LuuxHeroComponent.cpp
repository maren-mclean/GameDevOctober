// Fill out your copyright notice in the Description page of Project Settings.

#include "LuuxHeroComponent.h"

// Sets default values for this component's properties
ULuuxHeroComponent::ULuuxHeroComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// This object's Q ability
void ULuuxHeroComponent::CastQAbility() { 
	//TODO: Spawn colliding projectile
	AActor* Char = GetOwner();
	USceneComponent* RootComp = Char->GetRootComponent();
	FVector CompLocation = RootComp->GetComponentLocation();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, "Luux Q casted: " + CompLocation.ToString());
}

// This object's W ability
void ULuuxHeroComponent::CastWAbility() {
	//TODO: Spawn ephemeral projectile
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Luux W casted"); 
}

// This object's E ability
void ULuuxHeroComponent::CastEAbility() {
	//TODO: Jump in target direction a max distance
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Luux E casted"); 
}

// This object's R ability
void ULuuxHeroComponent::CastRAbility() {
	//TODO: Spawn cast-time projectile
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Luux R casted"); 
}