// MY_CUSTOM_CODE
// An extension of projectile movement which allows for movement towards the player's cursor

#pragma once

#include "GameFramework/ProjectileMovementComponent.h"
#include "SteeredProjectileMovement.generated.h"


UCLASS( ClassGroup=Movement, meta=(BlueprintSpawnableComponent) )
class SHOOTERGAME_API USteeredProjectileMovement : public UProjectileMovementComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Steering)
	float SteeringAccelerationMagnitude;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Steering)
	uint32 bIsSteeredProjectile : 1;

	// Sets default values for this component's properties
	USteeredProjectileMovement();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
protected:
	/** Compute the acceleration that will be applied. Overrides ProjectileMovementComponent */
	virtual FVector ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const;

	/** Allow the projectile to track towards its homing target. */
	virtual FVector ComputeSteeringAcceleration(const FVector& InVelocity, float DeltaTime) const;
};
// MY_CUSTOM_CODE
