// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/VRHGrab.h"

// Sets default values for this component's properties
UVRHGrab::UVRHGrab()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


void UVRHGrab::AttachToComponent(USceneComponent* Component)
{
	if (!Component) return;

	FAttachmentTransformRules AttachmenRules(EAttachmentRule::SnapToTarget, false);
	GetOwner()->AttachToComponent(Component, AttachmenRules, AttachSocketName);
}

// Called when the game starts
void UVRHGrab::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UVRHGrab::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

