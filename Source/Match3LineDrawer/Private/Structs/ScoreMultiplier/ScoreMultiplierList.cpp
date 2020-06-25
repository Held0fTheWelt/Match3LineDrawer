// @Yves Tanas 2020

#include "Structs/ScoreMultiplier/ScoreMultiplierList.h"

FScoreMultiplier::FScoreMultiplier()
{
	Count = 0;
	Multiplier = 0;
}

FScoreMultiplier::FScoreMultiplier(int32 TileCount, int32 TileMultiplier)
{
	Count = TileCount;
	Multiplier = TileMultiplier;
}

FScoreMultiplierList::FScoreMultiplierList()
{
	Multiplier.Empty();
	Multiplier.Add(FScoreMultiplier(0,1));
	Multiplier.Add(FScoreMultiplier(1,1));
	Multiplier.Add(FScoreMultiplier(2,1));
	Multiplier.Add(FScoreMultiplier(3,2));
	Multiplier.Add(FScoreMultiplier(4,2));
	Multiplier.Add(FScoreMultiplier(5,3));
	Multiplier.Add(FScoreMultiplier(6,3));
	Multiplier.Add(FScoreMultiplier(7,4));
	Multiplier.Add(FScoreMultiplier(8,5));
	Multiplier.Add(FScoreMultiplier(9,6));
	Multiplier.Add(FScoreMultiplier(10,7));
	Multiplier.Add(FScoreMultiplier(11,7));
	Multiplier.Add(FScoreMultiplier(12,7));
	Multiplier.Add(FScoreMultiplier(13,10));
	Multiplier.Add(FScoreMultiplier(14,12));
	Multiplier.Add(FScoreMultiplier(15,15));
}

TArray<FScoreMultiplier> FScoreMultiplierList::GetMultiplierList() const
{
	return Multiplier;
}
