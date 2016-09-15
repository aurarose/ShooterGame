// MY_CUSTOM_CODE
// An effect which causes the owner to burst in flames periodically

#pragma once

#include "ShooterGameplayEffect.h"
#include "ShooterGameplayEffect_Explosive.generated.h"


UCLASS( Blueprintable)
class SHOOTERGAME_API UShooterGameplayEffect_Explosive : public UShooterGameplayEffect
{
	GENERATED_UCLASS_BODY()

public:	
	// Called when the game starts
	virtual void BeginPlay() override;
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
protected:
	/** how much damage the explosions do */
	UPROPERTY(EditDefaultsOnly, Category = Explosion)
	int32 ExplosionDamage;
	/** type of damage */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	TSubclassOf<UDamageType> DamageType;
	/** how big of a radius the explosions do damage in */
	UPROPERTY(EditDefaultsOnly, Category = Explosion)
	float ExplosionRadius;
	/** how many seconds between explosions*/
	UPROPERTY(EditDefaultsOnly, Category = Explosion)
	float ExplosionInterval;
	/** effects for explosion */
	UPROPERTY(EditDefaultsOnly, Category = Effects)
	TSubclassOf<class AShooterExplosionEffect> ExplosionTemplate;
private:
	float LastExploded;
	void Explode();
		
	
};
// MY_CUSTOM_CODE
