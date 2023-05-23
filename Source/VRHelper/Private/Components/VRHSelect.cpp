// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/VRHSelect.h"



// Sets default values for this component's properties
UVRHSelect::UVRHSelect()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UVRHSelect::SelectComponent(const FHitResult& HitResult)
{

	if (HitResult.bBlockingHit)
	{
		for (auto& Tag : SelectHighLightTags)
		{
			if (HitResult.GetComponent()->ComponentHasTag(Tag.Key))
			{
				OnPressedSelect.Broadcast(HitResult.GetComponent(), HitResult.GetActor());
			}
		}
	}

	
}

void UVRHSelect::HightLightComponent(const FHitResult& HitResult)
{
}

// Called when the game starts
void UVRHSelect::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UVRHSelect::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

