// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HeroComponent.h"
#include "LuuxHeroComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAMEDEVOCTOBER_API ULuuxHeroComponent : public UHeroComponent
{
	GENERATED_BODY()
	
	public:
		ULuuxHeroComponent();

		// Casts Buttion_action. To be overriden in child classes defining hero. 
		virtual void CastQAbility() override;
		virtual void CastWAbility() override;
		virtual void CastEAbility() override;
		virtual void CastRAbility() override;
	
	
};
