// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>

// Sets default values
ASCharacter::ASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void ASCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASCharacter::MoveFoward(float value)
{
	AddMovementInput(GetActorForwardVector(),value);
}

void ASCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

// Called every frame
void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveFoward",this,&ASCharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);

	PlayerInputComponent->BindAxis("YawMovement", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("PitchMovement", this, &APawn::AddControllerPitchInput);
}

