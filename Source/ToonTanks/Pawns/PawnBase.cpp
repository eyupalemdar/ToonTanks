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

void APawnBase::RotateTurretFunction(FVector LookAtTarget)
{
	// Update TurretMesh rotation to face towards the LookAtTarget passed in from Child Classes
}

void APawnBase::Fire()
{
	// Get Projectile Location && Rotation -> Spawn Projectile class at Location firing towards Rotation
}

void APawnBase::HandleDestruction()
{
	// -- Universal Functionality --
	// Play Death effects particle, sound and camera shake

	// -- Then Do Child Overrides --
	// -- PawnTurret - Inform Game Mode Turret Died -> the Destroy() itself
	// -- PawnTank - Inform Game Mode Tank died -> Then Hide() all components && stop movement input 
}