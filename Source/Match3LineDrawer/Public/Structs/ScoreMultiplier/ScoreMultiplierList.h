// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "ScoreMultiplierList.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FScoreMultiplier
{
	GENERATED_BODY()

public:
	FScoreMultiplier();
	FScoreMultiplier(int32 TileCount, int32 TileMultiplier);

public:
	UPROPERTY(VisibleAnywhere)
	int32 Count;
	UPROPERTY(VisibleAnywhere)
	int32 Multiplier;

};

USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FScoreMultiplierList
{
	GENERATED_BODY()

public:
	FScoreMultiplierList();

private:
	UPROPERTY(VisibleAnywhere)
	TArray<FScoreMultiplier> Multiplier;
public:

	TArray<FScoreMultiplier> GetMultiplierList() const;
};

