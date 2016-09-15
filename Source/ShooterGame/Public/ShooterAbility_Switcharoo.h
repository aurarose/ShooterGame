// MY_CUSTOM_CODE
// Ability switches the positions of the user and the target when activated

#pragma once

#include "ShooterAbility.h"
#include "GameFramework/Actor.h"
#include "ShooterAbility_Switcharoo.generated.h"

UCLASS()
class SHOOTERGAME_API AShooterAbility_Switcharoo : public AShooterAbility
{
	GENERATED_UCLASS_BODY()
public:
	/** Called when the ability is activated */
	virtual void Activate() override;
	/** Determines whether the abilty can be activated */
	virtual bool CanActivate() override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float Range;

	FHitResult Raycast();
};

// MY_CUSTOM_CODE
