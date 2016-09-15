// MY_CUSTOM_CODE
// Base class for abilities

#include "ShooterGame.h"
#include "ShooterAbility.h"

AShooterAbility::AShooterAbility(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void AShooterAbility::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	TimeLastActivated = -1.f * CooldownTime;
}

void AShooterAbility::Destroyed()
{
	Super::Destroyed();
}

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

bool AShooterAbility::CanActivate()
{
	return GetWorld()->GetTimeSeconds() > TimeLastActivated + CooldownTime;
}
