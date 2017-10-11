// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Containers/Array.h"
#include "StatusEffectHelper.h"
#include "Components/SphereComponent.h"


// Sets default values
AProjectileActor::AProjectileActor() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// This is our RootComponent
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Projectile"));
}


AProjectileActor::AProjectileActor(float fHitboxSize, float fRange, float fVelocity, FVector vDirection, FRotator rRotation, TArray<StatusEffectHelper> lEffectList)
{
	AProjectileActor();

	this->HitboxSize = fHitboxSize;
	this->Range = fRange;
	this->Velocity = fVelocity;
	this->Direction = vDirection.GetSafeNormal();
	this->EffectList = lEffectList;
	this->CurrentDistance = 0.0f;

	FHitResult _result = FHitResult();
	RootComponent->K2_SetWorldRotation(rRotation, false, _result, false);
}

// Called when the game starts or when spawned
void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if we are over our max range
	if (this->CurrentDistance >= this->Range)
	{
		return; // Definitely should add logic to delete self.
	}

	
	// Move by Velocity amount and keep track of current distance
	
	float DistanceToMove = this->Velocity * DeltaTime;

	// Check to make sure we are not overstepping our bounds 
	if ((this->CurrentDistance + DistanceToMove) > this->Range)
	{
		DistanceToMove = this->Range - this->CurrentDistance;
	}
	FVector MovementVector = this->Direction * DistanceToMove;
	FHitResult* HitResult = new FHitResult();
	RootComponent->MoveComponent(MovementVector, RootComponent->GetComponentQuat(), true, HitResult, EMoveComponentFlags::MOVECOMP_NoFlags, ETeleportType::None);
	CurrentDistance += DistanceToMove;

}

