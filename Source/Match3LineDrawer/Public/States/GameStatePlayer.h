// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Structs/Player/PlayerInformation.h"
#include "Interfaces/States/PlayerStateInterface.h"
#include "GameStatePlayer.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API AGameStatePlayer : public APlayerState, public IPlayerStateInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Stats")
	FPlayerInformation CurrentStatus;

	// Inherited via IPlayerStateInterface
	virtual int32 GetCurrentColorIndex() const override;
	virtual void SetCurrentColorIndex(class IGameFieldElementInterface* ElementInterface);
};
