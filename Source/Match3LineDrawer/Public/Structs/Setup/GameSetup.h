// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Structs/Colors/ColorDefinition.h"
#include "Structs/ScoreMultiplier/ScoreMultiplierList.h"
#include "GameSetup.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FGameSetup
{
	GENERATED_BODY()

public:
	FGameSetup();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Player")
	int32 MovesToClear;

	UPROPERTY(EditDefaultsOnly, Category = "Colors")
	FColorDefinition Colors;
		
	UPROPERTY(VisibleAnywhere)
	int32 PointsPerTile;

	UPROPERTY(VisibleAnywhere)
	FScoreMultiplierList Multiplier;
};

