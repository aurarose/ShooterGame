// MY_CUSTOM_CODE

#include "ShooterGame.h"
#include "ShooterPickup_GameplayEffect.h"

// Sets default values
AShooterPickup_GameplayEffect::AShooterPickup_GameplayEffect(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

bool AShooterPickup_GameplayEffect::CanBePickedUp(AShooterCharacter* TestPawn) const
{

	return true;
}

void AShooterPickup_GameplayEffect::GivePickupTo(class AShooterCharacter* Pawn)
{
	UShooterGameplayEffect* NewEffect = NewObject<UShooterGameplayEffect>(Pawn, Effect);
	NewEffect->RegisterComponent();
}
// MY_CUSTOM_CODE
