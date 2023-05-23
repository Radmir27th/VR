// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VRHSelect.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPressedSelect, UActorComponent*, Component, AActor*, Actor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReleasedSelect, UActorComponent*, Component, AActor*, Actor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRHELPER_API UVRHSelect : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVRHSelect();


	UPROPERTY()
		FColor HighlightColor;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Select)
		TMap<FName, bool> SelectHighLightTags;
	
public:
	

	UPROPERTY(BlueprintAssignable)
		FOnReleasedSelect OnReleasedSelect;
	UPROPERTY(BlueprintAssignable)
		FOnPressedSelect OnPressedSelect;

	void SelectComponent(const FHitResult& HitResult);
	void HightLightComponent(const FHitResult& HitResult);



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
