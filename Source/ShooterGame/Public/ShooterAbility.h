// MY_CUSTOM_CODE
// Base class for abilities
#pragma once

#include "ShooterAbility.generated.h"

UCLASS(Abstract, Blueprintable)
class AShooterAbility : public AActor
{
	GENERATED_UCLASS_BODY()
	
	/** perform initial setup */
	virtual void PostInitializeComponents () override;

	virtual void Destroyed() override;

	/** Called when the ability is activated */
	virtual void Activate();
	/** Determines whether the abilty can be activated */
	virtual bool CanActivate();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Cooldown)
	float CooldownTime;
	float TimeLastActivated;
};
// MY_CUSTOM_CODE
