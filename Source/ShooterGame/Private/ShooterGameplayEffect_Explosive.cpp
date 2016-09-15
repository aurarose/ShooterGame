// MY_CUSTOM_CODE
// An effect which causes the owner to burst in flames periodically

#include "ShooterGame.h"
#include "ShooterGameplayEffect_Explosive.h"


// Sets default values for this component's properties
UShooterGameplayEffect_Explosive::UShooterGameplayEffect_Explosive(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

// Called when the game starts
void UShooterGameplayEffect_Explosive::BeginPlay()
{
	Super::BeginPlay();
	LastExploded = GetWorld()->GetTimeSeconds();
}

// Called every frame
void UShooterGameplayEffect_Explosive::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	float TimeNow = GetWorld()->GetTimeSeconds();
	float TimeForBoom = LastExploded + ExplosionInterval;

	if(TimeNow > TimeForBoom)
	{
		Explode();
		LastExploded = TimeNow;
	}
}

void UShooterGameplayEffect_Explosive::Explode()
{
	// From Shooter Projectile
	AActor* Owner = GetOwner();
	APawn* Instigator = Cast<APawn>(Owner);
	TWeakObjectPtr<AController> Controller = Instigator ? Instigator->Controller : NULL;

	if (ExplosionDamage > 0 && ExplosionRadius > 0)
	{
		UGameplayStatics::ApplyRadialDamage(this, ExplosionDamage, Owner->GetActorLocation(), ExplosionRadius, DamageType, TArray<AActor*>(), Owner, Controller.Get());
	}

	if (ExplosionTemplate)
	{
		FTransform const SpawnTransform(Owner->GetActorRotation(), Owner->GetActorLocation());
		AShooterExplosionEffect* const EffectActor = GetWorld()->SpawnActorDeferred<AShooterExplosionEffect>(ExplosionTemplate, SpawnTransform);
		if (EffectActor)
		{
			//EffectActor->SurfaceHit = Impact;
			UGameplayStatics::FinishSpawningActor(EffectActor, SpawnTransform);
		}
	}
	//
}
// MY_CUSTOM_CODE
