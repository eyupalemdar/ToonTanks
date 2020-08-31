// © 2020-2021 AlemdarLabs All Rights Are Reserved

#include "PawnBase.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	RootComponent = CapsuleComp;
	
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectilePawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Pawn Point"));
	ProjectilePawnPoint->SetupAttachment(TurretMesh);
}

/// <summary>
/// Update TurretMesh rotation to face towards the LookAtTarget passed in from Child Classes
/// </summary>
/// <param name="LookAtTarget"></param>
void APawnBase::RotateTurret(FVector LookAtTarget)
{
	// Only use X and Y coordinate of LookAtTarget, For Height just use Turret's Z value
	FVector LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	FVector StartLocation = TurretMesh->GetComponentLocation();

	FRotator TurretRotation = FVector(LookAtTargetCleaned - StartLocation).Rotation();
	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire()
{
	// Get Projectile Location && Rotation -> Spawn Projectile class at Location firing towards Rotation
	UE_LOG(LogTemp, Warning, TEXT("Fire!!!!"));
}

void APawnBase::HandleDestruction()
{
	// -- Universal Functionality --
	// Play Death effects particle, sound and camera shake

	// -- Then Do Child Overrides --
	// -- PawnTurret - Inform Game Mode Turret Died -> the Destroy() itself
	// -- PawnTank - Inform Game Mode Tank died -> Then Hide() all components && stop movement input 
}