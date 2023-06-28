// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Components/VRHCharacterMovementComponent.h"
#include "VRHBaseCharacter.generated.h"


class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;
class USpringArmComponent;
class UVRHWeaponComponent;
UCLASS()
class VRHELPER_API AVRHBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRHBaseCharacter(const FObjectInitializer& ObjInit);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UVRHWeaponComponent *WeaponComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent *CameraComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TMap<FName, UInputAction*> InputActions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputMappingContext* MappingContext;

	virtual void Move(const FInputActionValue& Value) {};
	virtual void Turn(const FInputActionValue& Value) {};
	virtual void JumpF(const FInputActionValue& Value) {};
	virtual void Select(const FInputActionValue& Value) {};
	virtual void ReleasedSelect(const FInputActionValue& Value) {};
	virtual void Grab(const FInputActionValue& Value) {};
	virtual void Shift(const FInputActionValue& Value) {};
	virtual void WeaponAppear(const FInputActionValue& Value) {};

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
