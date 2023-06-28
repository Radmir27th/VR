// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/VRHAnimNotify.h"


void UVRHAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{

	OnSwithFinished.Broadcast();
	Super::Notify(MeshComp, Animation);
}
