// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "VRHBaseCharacter.generated.h"


class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UEnhancedInputComponent;

UCLASS()
class VRHELPER_API AVRHBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRHBaseCharacter();
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent *CameraComponent;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* TurnAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* SelectAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
		UInputMappingContext* MappingContext;

	virtual void Move(const FInputActionValue& Value) {};
	virtual void Turn(const FInputActionValue& Value) {};
	virtual void JumpF(const FInputActionValue& Value) {};
	virtual void Select(const FInputActionValue& Value) {};
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
