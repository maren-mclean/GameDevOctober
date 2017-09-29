// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameDevOctoberCharacter.generated.h"

UCLASS(Blueprintable)
class AGameDevOctoberCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AGameDevOctoberCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Sets the CurrentHeroComponent subobject to a new subobject **/
	void SetCurrentHeroComponent(TSubclassOf<class UHeroComponent> NewCompClass);

	/** Returns CurrentHeroComponent subobject **/
	FORCEINLINE class UHeroComponent* GetCurrentHeroComponent() { return CurrentHeroComponent;  }
	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns CursorToWorld subobject **/
	FORCEINLINE class UDecalComponent* GetCursorToWorld() { return CursorToWorld; }

private:
	/** Current hero **/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HeroComponent", meta = (AllowPrivateAccess = "true"))
	class UHeroComponent* CurrentHeroComponent;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** A decal that projects to the cursor location. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UDecalComponent* CursorToWorld;


};

