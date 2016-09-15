// MY_CUSTOM_CODE
// Component that allows a 

#include "ShooterGame.h"
#include "ShooterAbilityUser.h"


// Sets default values for this component's properties
UShooterAbilityUser::UShooterAbilityUser(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	
	
	UInputComponent::BindAction("UseAbility", IE_Pressed, this, &UShooterAbilityUser::OnUseAbility);
	// ...
}

void UShooterAbilityUser::InitializeAbility()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AbilityRef = GetWorld()->SpawnActor<AShooterAbility>(Ability, SpawnInfo);
	AbilityRef -> SetOwner(GetOwner());
}

void UShooterAbilityUser::BeginPlay()
{
	Super::PostInitProperties();
	InitializeAbility();
	
}

void UShooterAbilityUser::OnUseAbility() 
{
	if (AbilityRef->CanActivate()) 
	{
		UShooterAbilityUser::AbilityRef->Activate();
	}
}
