// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/VRHPistolWeapon.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"

void AVRHPistolWeapon::StartAttack(float Duration)
{
	
	UE_LOG(LogTemp, Error, TEXT("The onwer is %s"), *GetOwner()->GetName());
	auto Player = Cast<ACharacter>(GetOwner());
	if (!Player) return;



	auto Controller = Player->GetController<APlayerController>();
	if (!Controller) return;

	

	FVector Location;
	FRotator Rotation;
	Controller->GetPlayerViewPoint(Location, Rotation);

	FHitResult HitResult;
	const FTransform SocketTrans = SkeletalMeshComponent->GetSocketTransform(WeaponStartSocketName);
	const FVector LineStart = Location;//SocketTrans.GetLocation();
	const FVector LineEnd = LineStart + Rotation.Vector() * MaxDistanceTrace;//SocketTrans.GetRotation().GetForwardVector() ;
	GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, LineEnd, ECollisionChannel::ECC_Visibility);
	DrawDebugLine(GetWorld(), SocketTrans.GetLocation(), LineEnd, FColor::Red, false, 5, 0U, 5.0);

	


	if (!PistolAnim) return;
	SkeletalMeshComponent->PlayAnimation(PistolAnim, false);

	if (!PistolAttackSound) return;	
	UGameplayStatics::PlaySoundAtLocation(GetWorld(), PistolAttackSound, LineStart);
	

}

void AVRHPistolWeapon::StopAttack()
{
}

void AVRHPistolWeapon::OnRightClick()
{

}
