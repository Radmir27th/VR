// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VRHDesktopCharacter.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/VRHSelect.h"

AVRHDesktopCharacter::AVRHDesktopCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	
}

void AVRHDesktopCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVRHDesktopCharacter::Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AVRHDesktopCharacter::Turn);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AVRHDesktopCharacter::JumpF);
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Started, this, &AVRHDesktopCharacter::Select);
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Completed, this, &AVRHDesktopCharacter::Released);
		
	}
	
}

void AVRHDesktopCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TargetLineTace();
}

void AVRHDesktopCharacter::Move(const FInputActionValue& Value)
{
	FVector CurrentValue = Value.Get<FVector>();
	AddMovementInput(GetActorForwardVector(), CurrentValue.Y);
	AddMovementInput(GetActorRightVector(), CurrentValue.X);

}

void AVRHDesktopCharacter::Turn(const FInputActionValue& Value)
{
	AddControllerYawInput(Value.Get<FVector2d>().X);
	AddControllerPitchInput(Value.Get<FVector2d>().Y);
}

void AVRHDesktopCharacter::JumpF(const FInputActionValue& Value)
{
	AVRHDesktopCharacter::Jump();
}

void AVRHDesktopCharacter::Select(const FInputActionValue& Value)
{
	if (Value.Get<bool>()) 
	{
		if (HitResult.bBlockingHit)
		{
			auto Component = HitResult.GetActor()->FindComponentByClass<UVRHSelect>();
			if (auto VRHComponent = Cast<UVRHSelect>(Component))
			{
				VRHComponent->OnPressedSelect.Broadcast(VRHComponent, HitResult.GetActor());
			}
		}
	}

}

void AVRHDesktopCharacter::Released(const FInputActionValue& Value)
{
	if (HitResult.bBlockingHit)
	{
		auto Component = HitResult.GetActor()->FindComponentByClass<UVRHSelect>();
		if (auto VRHComponent = Cast<UVRHSelect>(Component))
		{
			VRHComponent->OnReleasedSelect.Broadcast(VRHComponent, HitResult.GetActor());
		}
	}
}

void AVRHDesktopCharacter::TargetLineTace()
{
	auto SocketTransform = CameraComponent->GetSocketTransform("LineStart");
	const FVector TraceStart = SocketTransform.GetLocation();
	const FVector Derection = SocketTransform.GetRotation().GetForwardVector();
	const FVector TraceEnd = TraceStart + Derection * TraceMaxDictance;


	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

	

}
