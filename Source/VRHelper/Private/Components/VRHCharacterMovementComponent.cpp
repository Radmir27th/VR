// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/VRHCharacterMovementComponent.h"
#include "Character/VRHDesktopCharacter.h"


float UVRHCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const auto Character = Cast<AVRHDesktopCharacter>(GetOwner());
	const float EndSpeed = Character->bWantsToRun ? MaxSpeed * SpeedModifier : MaxSpeed * 0.5;
	return EndSpeed;
}

