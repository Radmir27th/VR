// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "VRHHUD.generated.h"

/**
 * 
 */

class UUserWidget;

UCLASS()
class VRHELPER_API AVRHHUD : public AHUD
{
	GENERATED_BODY()

public:
	AVRHHUD();
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TSubclassOf<UUserWidget> UserWidget;

	virtual void BeginPlay() override;
	
};
