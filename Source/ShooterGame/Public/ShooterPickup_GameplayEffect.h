// MY_CUSTOM_CODE

#pragma once

#include "ShooterPickup.h"
#include "ShooterGameplayEffect.h"
#include "ShooterPickup_GameplayEffect.generated.h"

class AShooterCharacter;
class AShooterWeapon;

// A pickup object that causes the player to emit explosions when near enemies
UCLASS(Abstract, Blueprintable)
class AShooterPickup_GameplayEffect : public AShooterPickup
{
	GENERATED_UCLASS_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameplayEffect)
	TSubclassOf<class UShooterGameplayEffect> Effect;
	/** check if pawn can use this pickup */
	virtual bool CanBePickedUp(AShooterCharacter* TestPawn) const override;

protected:
	/** give pickup */
	virtual void GivePickupTo(AShooterCharacter* Pawn) override;
};
// MY_CUSTOM_CODE
