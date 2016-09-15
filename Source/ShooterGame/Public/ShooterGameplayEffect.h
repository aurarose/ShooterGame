// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ShooterGameplayEffect.generated.h"


UCLASS(Abstract, Blueprintable)
class SHOOTERGAME_API UShooterGameplayEffect : public UActorComponent
{
	GENERATED_UCLASS_BODY()

public:	
	void Refresh(){TimeCreated = GetWorld()->GetTimeSeconds();}

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
protected:
	float TimeCreated;

	/** how long the effect lasts */
	UPROPERTY(EditDefaultsOnly, Category = Duration)
	float EffectDuration;
};
