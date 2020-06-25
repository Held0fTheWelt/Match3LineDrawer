// @Yves Tanas 2020

#include "Structs/Setup/GameSetup.h"

FGameSetup::FGameSetup()
{
	MovesToClear = 10;
	PointsPerTile = 15;

	Colors = FColorDefinition();
	Multiplier = FScoreMultiplierList();
}