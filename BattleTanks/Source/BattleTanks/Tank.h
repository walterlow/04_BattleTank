// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent* TankFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent* TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent* BarrelFromBP);

private:
	UChildActorComponent* Tank = nullptr;

	void MoveTank(float Speed);
	void RotateTank(float Speed);

	void RotateTurret(float Speed);
	UChildActorComponent* Turret = nullptr;

	void RotateBarrel(float Speed);
	UChildActorComponent* Barrel = nullptr;


	UPROPERTY(EditAnywhere)
	float RotationSpeed = 120.f;

	UPROPERTY(EditAnywhere)
	float MovementSpeed = 120.f;
};
