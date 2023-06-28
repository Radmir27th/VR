// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Animation/AnimMontage.h"
#include "VRHWeaponComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWeaponSwitch);

class AVRHWeapon;


USTRUCT(BlueprintType)
struct FAttachSockets
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FName AttachAreaName;
	UPROPERTY(EditAnywhere)
	FName AttachHandName;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRHELPER_API UVRHWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVRHWeaponComponent();

public:


	UPROPERTY(EditAnywhere, Category = Weapon)
	TArray<TSubclassOf<AVRHWeapon>> SpawnWeapons;

	UPROPERTY(EditAnywhere, Category = Weapon)
		TArray<FAttachSockets> AttachSocketNames;
	

	UPROPERTY(EditAnywhere, Category = Weapon)
		UAnimMontage* SwitchAnimation;

	UPROPERTY(BlueprintAssignable)
	FOnWeaponSwitch OnWPSwitch;

	UPROPERTY(EditAnywhere, Category = ComboAttack)
		UAnimMontage* FirstAttack;

public:

	int32 CurrentWeaponIndex = 0;
	TArray<AVRHWeapon*> Weapons;

	AVRHWeapon* CurrentWeapon;

	bool bWeaponInHand = false;
	void StartAttack();
	void StopAttack();
	void SpawnWeapon();
	void SwitchWeapon();

	void OnRightClick();

	AVRHWeapon* GetCurrentWeapon() { return CurrentWeapon;  }

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void InitSwitch();
	void SwitchFinished();
		
};
