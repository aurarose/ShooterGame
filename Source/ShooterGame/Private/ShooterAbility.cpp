// MY_CUSTOM_CODE

#include "ShooterGame.h"
#include "ShooterAbility.h"

AShooterAbility::AShooterAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

// Initialize
void AShooterAbility::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	TimeLastActivated = -1.f * CooldownTime;
}

void AShooterAbility::Destroyed()
{
	Super::Destroyed();
}

// If it can activate, set its cooldown
void AShooterAbility::Activate() 
{
	if (CanActivate()) 
	{
		TimeLastActivated = GetWorld()->GetTimeSeconds();
	}
	else 
	{
		return;
	}
		
}

// See if ability can activate
bool AShooterAbility::CanActivate()
{
	return GetWorld()->GetTimeSeconds() > TimeLastActivated + CooldownTime;
}
// MY_CUSTOM_CODE
