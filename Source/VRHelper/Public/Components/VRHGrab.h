// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VRHGrab.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRHELPER_API UVRHGrab : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVRHGrab();


	bool GetGragState() const { return IsGrabed;}
	void SetGrabState() { IsGrabed = !IsGrabed;  }

	UPROPERTY(EditAnywhere, Category = Attachment)
		FName AttachSocketName;
	


	void AttachToComponent(USceneComponent* Component);
		

private:
	bool IsGrabed = false;



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
