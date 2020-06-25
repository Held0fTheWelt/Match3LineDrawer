// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Structs/ScoreMultiplier/ScoreMultiplierList.h"
#include "GameStateInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IGameStateInterface
{
	GENERATED_BODY()
			
public:
	virtual void SetNewTileScore(int32 ScoreCount) = 0;
	virtual void SetNewTileCountMultiplier(TArray<FScoreMultiplier> ScoreMultiplier) = 0;
	virtual void CountSolvedRow(int32 NumberOfTiles) = 0;
};
