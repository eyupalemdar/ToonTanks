// © 2020-2021 AlemdarLabs All Rights Are Reserved

#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnTurret::APawnTurret()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		FireRateTimerHandle,
		this,
		&APawnTurret::CheckFireCondition,
		FireRate,
		true // don't fire and the stop, continue to loop the iteration
	);
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APawnTurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APawnTurret::CheckFireCondition()
{
	// If Player == null || is dead than BAIL!!

	// If Player is in range then FIRE!!

	UE_LOG(LogTemp, Warning, TEXT("Fire condition is checked"))
}
