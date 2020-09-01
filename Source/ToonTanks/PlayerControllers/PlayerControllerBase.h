// © 2020-2021 AlemdarLabs All Rights Are Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	void SetPlayerEnabledState(bool SetPlayerEnabled);
};
