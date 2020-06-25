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

	int32 TileScore;
	TArray<FScoreMultiplier> Multiplier;
	// Inherited via IGameStateInterface
	virtual void SetNewTileScore(int32 ScoreCount);

	// Inherited via IGameStateInterface
	virtual void SetNewTileCountMultiplier(TArray<FScoreMultiplier> ScoreMultiplier) override;
	virtual void CountSolvedRow(int32 NumberOfTiles) override;
};
