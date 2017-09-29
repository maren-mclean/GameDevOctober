// Fill out your copyright notice in the Description page of Project Settings.

#include "HeroComponent.h"


// Sets default values for this component's properties
UHeroComponent::UHeroComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Empty ability methods, to be overwritten by child objects for specific definitions.
void UHeroComponent::CastQAbility() { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, "Q casted"); }
void UHeroComponent::CastWAbility() { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "W casted"); }
void UHeroComponent::CastEAbility() { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "E casted"); }
void UHeroComponent::CastRAbility() { GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "R casted"); }

// Called when the game starts
void UHeroComponent::BeginPlay()
{
	Super::BeginPlay();
	AActor* act = GetOwner();
	// ...
	
}


// Called every frame
void UHeroComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//this->GetOwner()->GetActorLocation().toString()

	// ...
}

