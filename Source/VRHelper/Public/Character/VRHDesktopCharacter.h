// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/VRHBaseCharacter.h"
#include "VRHDesktopCharacter.generated.h"


/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRightClick, bool, isAiming);

UCLASS()
class VRHELPER_API AVRHDesktopCharacter : public AVRHBaseCharacter
{
	GENERATED_BODY()

public:
		AVRHDesktopCharacter(const FObjectInitializer& ObjInit);

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		void OnWPSwitch();

	UFUNCTION(BlueprintCallable, BlueprintPure)
		FHitResult& GetHitResult() { return HitResult; }

	UFUNCTION(BlueprintCallable)
		float GetMovenentDirection();

	UPROPERTY(BlueprintAssignable)
	FOnRightClick OnRightClick;
	
public:


	bool bWantsToRun = false;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bHasWeaponInHand = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsPistolInHand = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsSwordInHand = false;

protected:

	
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value) override;
	void Turn(const FInputActionValue& Value) override;
	void JumpF(const FInputActionValue& Value) override;
	void Select(const FInputActionValue& Value) override;
	void ReleasedSelect(const FInputActionValue& Value) override;
	void Grab(const FInputActionValue& Value) override;
	void Shift(const FInputActionValue& Value) override;
	void WeaponAppear(const FInputActionValue& Value) override;
	



private:
	FHitResult HitResult;
	
	
	UPROPERTY()
	float TraceMaxDictance = 1500;
private:

	void TargetLineTace();

};
