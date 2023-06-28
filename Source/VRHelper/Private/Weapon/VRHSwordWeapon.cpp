// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/VRHSwordWeapon.h"
#include "TimerManager.h"

void AVRHSwordWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void AVRHSwordWeapon::StartAttack(float Duration)
{
	GetWorldTimerManager().SetTimer(DurationTimerHandle, this, &AVRHSwordWeapon::StopAttack, Duration, false, Duration / 30);
	GetWorldTimerManager().SetTimer(AttackTimerHandle, this, &AVRHSwordWeapon::InnerStartAttack, float(1.0 / (Duration * 2)), true);
}



void AVRHSwordWeapon::InnerStartAttack()
{
	FHitResult HitResult;
	const FTransform SocketTransform = SkeletalMeshComponent->GetSocketTransform(WeaponStartSocketName);
	const FVector LineStart = SocketTransform.GetLocation();
	const FVector LineEnd = LineStart + (SocketTransform.GetRotation().GetForwardVector() * 200);
	GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, LineStart, ECollisionChannel::ECC_Visibility);
	/*DrawDebugLine(GetWorld(), LineStart, LineEnd, FColor::Red, false, 1.0, 0U, 5.0);*/
}

void AVRHSwordWeapon::StopAttack()
{
	UE_LOG(LogTemp, Error, TEXT("Attack Stoped"));
	GetWorldTimerManager().ClearTimer(AttackTimerHandle);
	GetWorldTimerManager().ClearTimer(DurationTimerHandle);
}

void AVRHSwordWeapon::OnRightClick()
{
}

