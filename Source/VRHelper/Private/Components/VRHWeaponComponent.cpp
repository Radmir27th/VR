// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/VRHWeaponComponent.h"
#include "Weapon/VRHWeapon.h"
#include "Weapon/VRHSwordWeapon.h"
#include "Character/VRHDesktopCharacter.h"
#include "GameFramework/Character.h"
#include "Animations/VRHAnimNotify.h"

// Sets default values for this component's properties
UVRHWeaponComponent::UVRHWeaponComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UVRHWeaponComponent::StartAttack()
{
	

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	if (!FirstAttack) return;
	Character->PlayAnimMontage(FirstAttack);
	CurrentWeapon->StartAttack(FirstAttack->SequenceLength * 30);	
}

void UVRHWeaponComponent::StopAttack()
{
}

void UVRHWeaponComponent::SpawnWeapon()
{
	if (SpawnWeapons.IsEmpty()) return;

	AVRHDesktopCharacter* Character = Cast<AVRHDesktopCharacter>(GetOwner());
	if (!Character) return;

	FAttachmentTransformRules AttachmentRules(EAttachmentRule::KeepRelative, false);
	int i = 0;
	for (auto& Weapon : SpawnWeapons)
	{
		if (!Weapon) return;
		Weapons.Add(GetWorld()->SpawnActor<AVRHWeapon>(Weapon));
		Weapons[i]->AttachToComponent(Character->GetMesh(), AttachmentRules, AttachSocketNames[i].AttachAreaName);
		Weapons[i]->SetOwner(Character);
		++i;
	}
	CurrentWeapon = Weapons[CurrentWeaponIndex];
	
}

void UVRHWeaponComponent::SwitchWeapon()
{
	/*bWeaponInHand = !bWeaponInHand;*/
	AVRHDesktopCharacter* Character = Cast<AVRHDesktopCharacter>(GetOwner());
	Character->PlayAnimMontage(SwitchAnimation);
}

void UVRHWeaponComponent::OnRightClick()
{
	CurrentWeapon->OnRightClick();
}

void UVRHWeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnWeapon();
	InitSwitch();
	
	
}

void UVRHWeaponComponent::InitSwitch()
{
	if (!SwitchAnimation) return;
	auto Notifies = SwitchAnimation->Notifies;

	for (auto& Notify : Notifies)
	{
		if (auto TmpNotify = Cast<UVRHAnimNotify>(Notify.Notify))
		{
			TmpNotify->OnSwithFinished.AddUObject(this, &UVRHWeaponComponent::SwitchFinished);
			
			break;
		}
	}
}

void UVRHWeaponComponent::SwitchFinished()
{
	AVRHDesktopCharacter* Character = Cast<AVRHDesktopCharacter>(GetOwner());

	if (!Character) return;

	if (auto WeaponType = Cast<AVRHSwordWeapon>(CurrentWeapon))
	{
		auto DynamicMaterial = CurrentWeapon->SkeletalMeshComponent->CreateDynamicMaterialInstance(2,
			CurrentWeapon->SkeletalMeshComponent->GetMaterial(2));
		DynamicMaterial->SetScalarParameterValue("ShowLS", 0);
	}

	FAttachmentTransformRules AttachRules(EAttachmentRule::SnapToTarget, false);
	CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachRules, AttachSocketNames[CurrentWeaponIndex].AttachAreaName);

	CurrentWeaponIndex = ++CurrentWeaponIndex % Weapons.Num();
	CurrentWeapon = Weapons[CurrentWeaponIndex];


	CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachRules, AttachSocketNames[CurrentWeaponIndex].AttachHandName);

	if (auto WeaponType = Cast<AVRHSwordWeapon>(CurrentWeapon))
	{
		auto DynamicMaterial = CurrentWeapon->SkeletalMeshComponent->CreateDynamicMaterialInstance(2, 
			CurrentWeapon->SkeletalMeshComponent->GetMaterial(2));
		DynamicMaterial->SetScalarParameterValue("ShowLS", 1);
	}
	
	
	
}


