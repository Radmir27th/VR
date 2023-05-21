// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/VRHBaseCharacter.h"
#include "VRHDesktopCharacter.generated.h"

/**
 * 
 */

class UWidgetComponent;

UCLASS()
class VRHELPER_API AVRHDesktopCharacter : public AVRHBaseCharacter
{
	GENERATED_BODY()

public:
		AVRHDesktopCharacter();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UWidgetComponent *PawnTarget;


protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value) override;
	void Turn(const FInputActionValue& Value) override;
	void JumpF(const FInputActionValue& Value) override;
		

};
