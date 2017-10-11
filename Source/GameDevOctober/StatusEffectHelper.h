// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GAMEDEVOCTOBER_API StatusEffectHelper
{
public:
	// Creates a Status Effect Helper object
	StatusEffectHelper(FString EffectSource, FString EffectType, float duration, float intensity);
	StatusEffectHelper(FString EffectSource, FString EffectType, float duration);

	// Deconstructor
	~StatusEffectHelper();

	// Unique ID to express the origin of the buff or effect
	FString EffectSource;

	// ID of the status effect type, ie Snare, Stun, Knockup, MovementSpeed, AttackDamage, etc. 
	FString EffectType;

	// Length of the effect
	float duration;

	// Intensity of the effect, if it is a buff/debuff
	float intensity;
};
