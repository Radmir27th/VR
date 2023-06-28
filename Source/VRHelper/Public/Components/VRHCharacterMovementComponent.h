// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "VRHCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class VRHELPER_API UVRHCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, Category = Velositi, meta = (ClampMin = 1, ClampMax = 10))
		float SpeedModifier = 1;
	virtual float GetMaxSpeed() const;
	
};
