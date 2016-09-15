// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShooterProjectile.h"
#include "SteeredProjectileMovement.h"
#include "ShooterProjectileSteered.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterProjectileSteered : public AShooterProjectile
{
	GENERATED_BODY()
	
public:
	AShooterProjectileSteered(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	
	
};
