// Fill out your copyright notice in the Description page of Project Settings.


#include "VRHHUD.h"
#include "Blueprint/UserWidget.h"

AVRHHUD::AVRHHUD()
{
}

void AVRHHUD::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), UserWidget);
	if (PlayerHUDWidget)
	{
		PlayerHUDWidget->AddToViewport();
	}

}
