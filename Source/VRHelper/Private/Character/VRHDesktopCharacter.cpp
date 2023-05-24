// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VRHDesktopCharacter.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/VRHSelect.h"
#include "Components/VRHGrab.h"


AVRHDesktopCharacter::AVRHDesktopCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	
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
				VRHComponent->SelectComponent(HitResult);
			}
		}
	}

}

void AVRHDesktopCharacter::ReleasedSelect(const FInputActionValue& Value)
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

void AVRHDesktopCharacter::Grab(const FInputActionValue& Value)
{
	if (!HitResult.bBlockingHit) return;

	if (auto Component = HitResult.GetActor()->FindComponentByClass<UVRHGrab>())
	{
		if (!Component->GetGragState()) 
		{
			if (Component->AttachSocketName != FName("None"))
			{
				Component->AttachToComponent(GetMesh());
				Component->SetGrabState();
				return;
			}

			HitResult.GetActor()->AttachToComponent(CameraComponent, FAttachmentTransformRules::KeepWorldTransform, FName("Grab"));
			Component->SetGrabState();
			
		}
		else
		{
			HitResult.GetActor()->DetachAllSceneComponents(CameraComponent, FDetachmentTransformRules::KeepWorldTransform);
			Component->SetGrabState();
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
