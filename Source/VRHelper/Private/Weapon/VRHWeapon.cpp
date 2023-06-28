// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/VRHWeapon.h"

// Sets default values
AVRHWeapon::AVRHWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("StaticMesh");
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AVRHWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}



