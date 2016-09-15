// MY_CUSTOM_CODE
// A base class for an effect which attaches to an actor and lasts a certain amount of time

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
// MY_CUSTOM_CODE
