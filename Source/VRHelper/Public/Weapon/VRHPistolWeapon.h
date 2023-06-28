// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/VRHWeapon.h"
#include "VRHPistolWeapon.generated.h"

/**
 * 
 */
UCLASS()
class VRHELPER_API AVRHPistolWeapon : public AVRHWeapon
{
	GENERATED_BODY()


public:
	float MaxDistanceTrace = 1500;
public:
	void StartAttack(float Duration) override;
	void StopAttack() override;
	void OnRightClick() override;

public:
	UPROPERTY(EditAnywhere, Category = WeaponSettings)
		UAnimMontage* PistolAnim;
	UPROPERTY(EditAnywhere, Category = WeaponSettings)
		USoundBase* PistolAttackSound;
	
};
