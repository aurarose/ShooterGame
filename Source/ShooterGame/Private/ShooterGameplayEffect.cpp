// MY_CUSTOM_CODE
// A base class for an effect which attaches to an actor and lasts a certain amount of time

#include "ShooterGame.h"
#include "ShooterGameplayEffect.h"

// Sets default values for this component's properties
UShooterGameplayEffect::UShooterGameplayEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

// Called when the game starts
void UShooterGameplayEffect::BeginPlay()
{
	Super::BeginPlay();
	TimeCreated = GetWorld() -> GetTimeSeconds();
}

// Called every frame
void UShooterGameplayEffect::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	if (GetWorld() -> GetTimeSeconds() > TimeCreated + EffectDuration) 
	{
		UActorComponent::DestroyComponent();
	}
}
// MY_CUSTOM_CODE
