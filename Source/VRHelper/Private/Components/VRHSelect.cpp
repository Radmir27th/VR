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
		
	}

	
}

void UVRHSelect::HightLightComponent(const FHitResult& HitResult)
{
}

void UVRHSelect::OnSelectCall(AActor* Actor, USceneComponent* Component, bool bIsPressed)
{
	if (bIsPressed) 
	{
		for (auto& Tag : SelectHighLightTags)
		{
			if (Component->ComponentHasTag(Tag.Key))
			{
				OnPressedSelect.Broadcast(Component, Actor);
			}
		}
		return;
	}

	OnReleasedSelect.Broadcast(Component, Actor);

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

