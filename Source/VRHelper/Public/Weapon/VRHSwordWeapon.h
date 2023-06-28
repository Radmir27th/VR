// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/VRHWeapon.h"
#include "VRHSwordWeapon.generated.h"

/**
 * 
 */
UCLASS()
class VRHELPER_API AVRHSwordWeapon : public AVRHWeapon
{
	GENERATED_BODY()
protected:
		void BeginPlay() override;
public:
		void StartAttack(float Duration) override;
		void StopAttack() override;
		void OnRightClick();

public:
	void InnerStartAttack();
	

public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attachment);
		FName SocketShowWeapon;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attachment);
		FName SocketHideWeapon;

		FTimerHandle DurationTimerHandle;
		FTimerHandle AttackTimerHandle;
	
};
