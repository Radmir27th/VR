// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VRHDesktopCharacter.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "Camera/CameraComponent.h"

AVRHDesktopCharacter::AVRHDesktopCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PawnTarget = CreateDefaultSubobject<UWidgetComponent>("PawnTarget");
	
}

void AVRHDesktopCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVRHDesktopCharacter::Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AVRHDesktopCharacter::Turn);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AVRHDesktopCharacter::JumpF);
		
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

void AVRHDesktopCharacter::TargetLineTace()
{
	auto SocketTransform = CameraComponent->GetSocketTransform("LineStart");
	const FVector TraceStart = SocketTransform.GetLocation();
	const FVector TraceEnd = SocketTransform.GetRotation().GetForwardVector() + TraceEnd * TraceMaxDictance;


	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);

	if (HitResult.bBlockingHit)
	{
		
		/*DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
		DrawDebugSphere(GetWorld(), TraceEnd, 30.0f, 24, FColor::Green, false, 5.0f);*/
	}

}
