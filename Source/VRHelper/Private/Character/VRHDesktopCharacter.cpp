// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VRHDesktopCharacter.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/VRHSelect.h"
#include "Components/VRHWeaponComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Weapon/VRHPistolWeapon.h"
#include "Weapon/VRHSwordWeapon.h"
#include "Components/VRHGrab.h"


AVRHDesktopCharacter::AVRHDesktopCharacter(const FObjectInitializer& ObjInit) : 
	Super(ObjInit.SetDefaultSubobjectClass<UVRHCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

}

float AVRHDesktopCharacter::GetMovenentDirection()
{
	const auto VelocityNormal = GetVelocity().GetSafeNormal();
	const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
	const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
	return FMath::RadiansToDegrees(AngleBetween) * FMath::Sign(CrossProduct.Z);
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
	WeaponComponent->StartAttack();
	//if (bHasWeaponInHand/* && Weapon*/)
	//{
	//	return;
	//}
	//if (HitResult.bBlockingHit)
	//{
	//	if (auto VRHComponent = Cast<UVRHSelect>(HitResult.GetActor()->FindComponentByClass<UVRHBaseComponent>()))
	//	{
	//		VRHComponent->OnSelectCall(HitResult.GetActor(), HitResult.GetComponent(), true);
	//	}
	//}

}

void AVRHDesktopCharacter::ReleasedSelect(const FInputActionValue& Value)
{




	/*if (HitResult.bBlockingHit) 
	{
		if (auto VRHComponent = Cast<UVRHSelect>(HitResult.GetActor()->FindComponentByClass<UVRHBaseComponent>()))
		{
			VRHComponent->OnSelectCall(HitResult.GetActor(), HitResult.GetComponent(), false);
		}
	}*/
}

void AVRHDesktopCharacter::Grab(const FInputActionValue& Value)
{
	WeaponComponent->OnRightClick();

	if (Value.Get<bool>()) 
	{
		if (auto Weapon = Cast<AVRHSwordWeapon>(WeaponComponent->GetCurrentWeapon()))
		{
			bIsSwordInHand = true;
			bIsPistolInHand = false;
		}
		else
		{
			bIsSwordInHand = false;
			bIsPistolInHand = true;
			SpringArm->TargetArmLength = 100;
			SpringArm->TargetOffset.Set(0, 90, 0);
			
		}
	}
	else
	{
		bIsSwordInHand = false;
		bIsPistolInHand = false;
		SpringArm->TargetOffset.Set(0, 0, 0);
		SpringArm->TargetArmLength = 300;
		
	}
	OnRightClick.Broadcast(Value.Get<bool>());

	/*if (!HitResult.bBlockingHit) return;

	if (auto Component = HitResult.GetActor()->FindComponentByClass<UVRHGrab>())
	{
		if (!Component->GetGragState()) 
		{
			if (Component->AttachSocketName != FName("None"))
			{
				Component->AttachToComponent(GetMesh());
				Component->SetGrabState();
				bHasWeaponInHand = true;
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
		
	}*/
}

void AVRHDesktopCharacter::Shift(const FInputActionValue& Value)
{
	bWantsToRun = Value.Get<bool>();
}

void AVRHDesktopCharacter::WeaponAppear(const FInputActionValue& Value)
{
	WeaponComponent->SwitchWeapon();
	WeaponComponent->OnWPSwitch.Broadcast();
}





void AVRHDesktopCharacter::TargetLineTace()
{
	auto SocketTransform = CameraComponent->GetSocketTransform("LineStart");
	const FVector TraceStart = SocketTransform.GetLocation();
	const FVector Derection = SocketTransform.GetRotation().GetForwardVector();
	const FVector TraceEnd = TraceStart + Derection * TraceMaxDictance;
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
	
	

}
