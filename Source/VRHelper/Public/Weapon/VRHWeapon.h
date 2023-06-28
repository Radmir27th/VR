// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VRHWeapon.generated.h"

UENUM(BlueprintType)
enum class WeaponType : uint8
{
	SWORD UMETA(DiplayName = "SWORD"),
	GUN UMETA(DiplayName = "GUN"),

};

UCLASS()
class VRHELPER_API AVRHWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVRHWeapon();

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditAnywhere, Category = WeaponSettings)
		FName WeaponStartSocketName;

	virtual void StartAttack(float Duration) {};
	virtual void StopAttack() {};

	virtual void OnRightClick() {};
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};
