// MY_CUSTOM_CODE
// An extension of projectile movement which allows for movement towards the player's cursor

#include "ShooterGame.h"
#include "SteeredProjectileMovement.h"

// Sets default values for this component's properties
USteeredProjectileMovement::USteeredProjectileMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

FVector USteeredProjectileMovement::ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const
{
	FVector Acceleration(FVector::ZeroVector);

	Acceleration.Z += GetGravityZ();

	if (bIsHomingProjectile && HomingTargetComponent.IsValid())
	{
		Acceleration += ComputeHomingAcceleration(InVelocity, DeltaTime);
	}

	// Don't do both homing and steering
	else if (bIsSteeredProjectile)
	{
		Acceleration += ComputeSteeringAcceleration(InVelocity, DeltaTime);
	}

	return Acceleration;
}

// Allow the projectile to change direction based on its firer's direction
FVector USteeredProjectileMovement::ComputeSteeringAcceleration(const FVector& InVelocity, float DeltaTime) const
{
	
	// Character's facing vector
	AShooterWeapon* Weapon = Cast<AShooterWeapon>(GetOwner()->GetOwner());
	
	// Check to make sure all owners are still valid
	if (!Weapon || !GetOwner() || !GetOwner()->GetOwner()->GetOwner()) 
	{
		return FVector::ZeroVector;
	}

	FVector GoalDirection = Weapon->GetAdjustedAim();
	// Projectile's current facing vector
	FVector CurDirection = InVelocity.GetSafeNormal();
	
	//GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Red, "CurDirection: " + CurDirection.ToString() + "/n" + "GoalDirection: " + GoalDirection.ToString());
	FVector SteeringAcceleration = (GoalDirection - CurDirection) * SteeringAccelerationMagnitude;
	return SteeringAcceleration;
}

// Called when the game starts
void USteeredProjectileMovement::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void USteeredProjectileMovement::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}
// MY_CUSTOM_CODE
