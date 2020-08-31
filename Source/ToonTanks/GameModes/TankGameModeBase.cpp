// © 2020-2021 AlemdarLabs All Rights Are Reserved

#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	// Get references and game win/lose conditions 

	// Call HandleGameStart() to initialize the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::HandleGameStart()
{
	// initialize the start countdown, turret activation, pawn check etc.

	// Call Blueprint version GameStart() 
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	// See if the Player has destroyed all the turrets, show in result
	// if Turret destroyed player, show lose result.

	// Call Blueprint version GameOver(bool)
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	// Check what type of Actor died. If Turrent, tally. If Player -> go to lose condition
	UE_LOG(LogTemp, Warning, TEXT("A Pawn died"));
}
