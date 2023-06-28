// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/VRHBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"
#include "Components/VRHWeaponComponent.h"
#include "GameFramework/SpringArmComponent.h"



// Sets default values
AVRHBaseCharacter::AVRHBaseCharacter(const FObjectInitializer& ObjInit) :
	Super(ObjInit.SetDefaultSubobjectClass<UVRHCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("BaseCamera");
	CameraComponent->SetupAttachment(SpringArm);

	WeaponComponent = CreateDefaultSubobject<UVRHWeaponComponent>("WeaponComponent");
	
	
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
		if (InputActions.IsEmpty()) return;
		EnhancedInputComponent->BindAction(InputActions["Move"], ETriggerEvent::Triggered, this, &AVRHBaseCharacter::Move);
		EnhancedInputComponent->BindAction(InputActions["Turn"], ETriggerEvent::Triggered, this, &AVRHBaseCharacter::Turn);
		EnhancedInputComponent->BindAction(InputActions["Jump"], ETriggerEvent::Started, this, &AVRHBaseCharacter::JumpF);
		EnhancedInputComponent->BindAction(InputActions["LeftClick"], ETriggerEvent::Started, this, &AVRHBaseCharacter::Select);
		/*EnhancedInputComponent->BindAction(InputActions["LeftClick"], ETriggerEvent::Completed, this, &AVRHBaseCharacter::ReleasedSelect);*/
		EnhancedInputComponent->BindAction(InputActions["RightClick"], ETriggerEvent::Triggered, this, &AVRHBaseCharacter::Grab);
		EnhancedInputComponent->BindAction(InputActions["RightClick"], ETriggerEvent::Completed, this, &AVRHBaseCharacter::Grab);
		EnhancedInputComponent->BindAction(InputActions["Shift"], ETriggerEvent::Started, this, &AVRHBaseCharacter::Shift);
		EnhancedInputComponent->BindAction(InputActions["Shift"], ETriggerEvent::Completed, this, &AVRHBaseCharacter::Shift);
		EnhancedInputComponent->BindAction(InputActions["One"], ETriggerEvent::Started, this, &AVRHBaseCharacter::WeaponAppear);
	

	}

}

