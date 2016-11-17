// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::MoveTank(float Speed)
{
	if (!Tank) { return; }
	float Distance = GetWorld()->DeltaTimeSeconds * Speed * MovementSpeed;
	Tank->AddRelativeLocation(Tank->GetForwardVector() * Distance);
}

void ATank::RotateTank(float Speed)
{
	if (!Tank) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * RotationSpeed * Speed;
	Tank->AddRelativeRotation(FRotator(0, Rotation, 0));
}

void ATank::SetTankChildActor(UChildActorComponent* TankFromBP)
{
	if (!TankFromBP) { return; }
	Tank = TankFromBP;
}

void ATank::SetTurretChildActor(UChildActorComponent* TurretFromBP)
{
	if (!TurretFromBP) { return; }
	Turret = TurretFromBP;
}

void ATank::SetBarrelChildActor(UChildActorComponent* BarrelFromBP)
{
	if (!BarrelFromBP) { return; }
	Barrel = BarrelFromBP;
}


// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
	InputComponent->BindAxis("Rotate_Barrel", this, &ATank::RotateBarrel);

	InputComponent->BindAxis("Rotate_Tank", this, &ATank::RotateTank);
	InputComponent->BindAxis("Move_Tank", this, &ATank::MoveTank);
}

void ATank::RotateTurret(float Speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * RotationSpeed * Speed;

	Turret->AddRelativeRotation(FRotator(0.f, Rotation, 0.f));

}

void ATank::RotateBarrel(float Speed)
{
	if (!Barrel) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * RotationSpeed * Speed;

	Barrel->AddRelativeRotation(FRotator(Rotation, 0.f, 0.f));
}

