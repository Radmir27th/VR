// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/VRHBaseCharacter.h"
#include "VRHDesktopCharacter.generated.h"

/**
 * 
 */


UCLASS()
class VRHELPER_API AVRHDesktopCharacter : public AVRHBaseCharacter
{
	GENERATED_BODY()

public:
		AVRHDesktopCharacter();

public:
	
	


	UFUNCTION(BlueprintCallable)
	FHitResult& GetHitResult()  
	{ 
		return HitResult; 
	}

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

	void Move(const FInputActionValue& Value) override;
	void Turn(const FInputActionValue& Value) override;
	void JumpF(const FInputActionValue& Value) override;
	virtual void Select(const FInputActionValue& Value) override;
	void Released(const FInputActionValue& Value);

private:
	FHitResult HitResult;

	UPROPERTY()
	float TraceMaxDictance = 1500;
private:

	void TargetLineTace();

};
