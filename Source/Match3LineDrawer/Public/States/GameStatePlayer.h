// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Structs/Player/PlayerInformation.h"
#include "GameStatePlayer.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API AGameStatePlayer : public APlayerState
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Stats")
	FPlayerInformation CurrentStatus;
};
