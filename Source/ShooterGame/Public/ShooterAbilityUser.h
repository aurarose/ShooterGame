// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "ShooterAbility.h"
#include "ShooterAbilityUser.generated.h"


UCLASS()
class SHOOTERGAME_API UShooterAbilityUser : public UInputComponent
{
	GENERATED_UCLASS_BODY()

	/** spawn inventory, setup initial variables */
	virtual void BeginPlay() override;
public:	
	UPROPERTY(EditDefaultsOnly, Category = Ability)
	TSubclassOf<class AShooterAbility> Ability;
	
	void OnUseAbility();
private:
	AShooterAbility* AbilityRef;

	void InitializeAbility();
		
};
