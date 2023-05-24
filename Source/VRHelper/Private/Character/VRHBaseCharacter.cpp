// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VRHBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"


// Sets default values
AVRHBaseCharacter::AVRHBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("BaseCamera");
	CameraComponent->SetupAttachment(GetRootComponent());

	
}

// Called when the game starts or when spawned
void AVRHBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MappingContext, 0);
		}
	}
	
}

// Called every frame
void AVRHBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRHBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked< UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AVRHBaseCharacter::Move);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AVRHBaseCharacter::Turn);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AVRHBaseCharacter::JumpF);
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Started, this, &AVRHBaseCharacter::Select);
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Completed, this, &AVRHBaseCharacter::ReleasedSelect);
		EnhancedInputComponent->BindAction(GrabAction, ETriggerEvent::Started, this, &AVRHBaseCharacter::Grab);
	

	}

}

