// Fill out your copyright notice in the Description page of Project Settings.

#include "StatusEffectHelper.h"

StatusEffectHelper::StatusEffectHelper(FString SEffectSource, FString SEffectType, float fDuration, float fIntensity)
{
	this->EffectSource = SEffectSource;
	this->EffectSource = SEffectType;
	this->duration = fDuration;
	this->intensity = fIntensity;

}

StatusEffectHelper::StatusEffectHelper(FString SEffectSource, FString SEffectType, float fDuration)
{
	StatusEffectHelper::StatusEffectHelper(SEffectSource, SEffectSource, fDuration, 0.0f);
}

StatusEffectHelper::~StatusEffectHelper()
{
}
