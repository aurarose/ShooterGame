// MY_CUSTOM_CODE
// Ability switches the positions of the user and the target when activated

#include "ShooterGame.h"
#include "ShooterAbility_Switcharoo.h"


AShooterAbility_Switcharoo::AShooterAbility_Switcharoo(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

/** Called when the ability is activated */
void AShooterAbility_Switcharoo::Activate()
{
	AShooterAbility::Activate();
	
	// Do a trace from our actor
	// get the camera transform
	AActor* HitActor = Raycast().GetActor();
	if (HitActor)
	{
		FVector HitLocation = HitActor->GetActorLocation();
		FVector MyLocation = GetOwner()->GetActorLocation();
		FRotator HitRotation = HitActor->GetActorRotation();
		FRotator MyRotation = GetOwner()->GetActorRotation();
		HitActor->SetActorLocation(MyLocation);
		GetOwner()->SetActorLocation(HitLocation);
		HitActor->SetActorRotation(MyRotation);
		GetOwner()->SetActorRotation(HitRotation);
		
	}
}

/** Determines whether the abilty can be activated */
bool AShooterAbility_Switcharoo::CanActivate()
{ 
	AActor* HitActor = Raycast().GetActor();
	AShooterCharacter* Character = Cast<AShooterCharacter>(HitActor);
	if (AShooterAbility::CanActivate() && HitActor && Character)
	{
		return true;
	}
	return false;
}

FHitResult AShooterAbility_Switcharoo::Raycast()
{
	AActor* Actor = GetOwner();

	FVector CameraLoc;
	FRotator CameraRot;
	Actor->GetActorEyesViewPoint(CameraLoc, CameraRot);

	const FVector StartTrace = CameraLoc;
	const FVector EndTrace = StartTrace + (CameraRot.Vector()) * Range;

	FCollisionQueryParams TraceParams(FName(TEXT("WeaponTrace")), true, Instigator);
	TraceParams.bTraceAsyncScene = true;
	TraceParams.bReturnPhysicalMaterial = true;

	FHitResult Hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, COLLISION_WEAPON, TraceParams);
	return Hit;
}
