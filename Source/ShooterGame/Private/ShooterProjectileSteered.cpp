// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterProjectileSteered.h"
#include "Weapons/ShooterProjectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "Effects/ShooterExplosionEffect.h"


// Sets default values
AShooterProjectileSteered::AShooterProjectileSteered(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

	//MovementComp = ObjectInitializer.CreateDefaultSubobject<USteeredProjectileMovement>(this, TEXT("ProjectileComp"));
}

// Called when the game starts or when spawned
void AShooterProjectileSteered::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShooterProjectileSteered::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

