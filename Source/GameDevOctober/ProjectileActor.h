// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/Array.h"
#include "StatusEffectHelper.h"
#include "ProjectileActor.generated.h"

UCLASS()
class GAMEDEVOCTOBER_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();
	AProjectileActor(float fHitboxSize, float fRange, float fVelocity, FVector vDirection, FRotator rRotation, TArray<StatusEffectHelper> lEffectList);

	float HitboxSize;
	float Range;
	float Velocity;
	float CurrentDistance;
	FVector Direction;
	FRotator Rotation;
	TArray<StatusEffectHelper> EffectList;

	// TODO: FX - unnecessary for current implementation

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "RootComponent", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* SphereComponent;

	
	
};
