// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterGame.h"
#include "ShooterGameplayEffect.h"


// Sets default values for this component's properties
UShooterGameplayEffect::UShooterGameplayEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
	// ...
}

// Called when the game starts
void UShooterGameplayEffect::BeginPlay()
{
	Super::BeginPlay();
	TimeCreated = GetWorld() -> GetTimeSeconds();

	// ...
	
}

// Called every frame
void UShooterGameplayEffect::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (GetWorld() -> GetTimeSeconds() > TimeCreated + EffectDuration) 
	{
		UActorComponent::DestroyComponent();
	}
	// ...
}

