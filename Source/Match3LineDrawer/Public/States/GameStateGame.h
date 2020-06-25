// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Interfaces/States/GameStateInterface.h"
#include "Structs/Score/GameScore.h"
#include "GameStateGame.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API AGameStateGame : public AGameStateBase, public IGameStateInterface
{
	GENERATED_BODY()
	
public:
	AGameStateGame();

private:
	UPROPERTY(VisibleAnywhere, Category = "Score")
	FGameScore GameScore;	

	int32 TileCount;

	// Inherited via IGameStateInterface
	virtual void SetNewTileCount(int32 Count);
};
