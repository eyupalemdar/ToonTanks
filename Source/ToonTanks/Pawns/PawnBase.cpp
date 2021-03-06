// © 2020-2021 AlemdarLabs All Rights Are Reserved

#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "ToonTanks/Actors/ProjectileBase.h"
#include "ToonTanks/Components/HealthComponent.h"
#include "Kismet/GameplayStatics.h"

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

	HealtComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
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
	if (ProjectileClass)
	{
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(
			ProjectileClass,
			ProjectilePawnPoint->GetComponentLocation(),
			ProjectilePawnPoint->GetComponentRotation()
		);
		TempProjectile->SetOwner(this);
	}
}

void APawnBase::HandleDestruction()
{
	// -- Universal Functionality --
	// Play Death effects particle, sound and camera shake

	UGameplayStatics::SpawnEmitterAtLocation(
		this,
		DeathParticle, 
		GetActorLocation()
	);

	UGameplayStatics::PlaySoundAtLocation(
		this, 
		DeathSound, 
		GetActorLocation()
	);

	GetWorld()->GetFirstPlayerController()->ClientPlayCameraShake(DeathShake);
}