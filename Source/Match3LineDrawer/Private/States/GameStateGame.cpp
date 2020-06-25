// @Yves Tanas 2020


#include "GameStateGame.h"

AGameStateGame::AGameStateGame()
{
	TileScore = 0;
}

void AGameStateGame::SetNewTileScore(int32 ScoreCount)
{
	TileScore = ScoreCount;
}

void AGameStateGame::SetNewTileCountMultiplier(TArray<FScoreMultiplier> ScoreMultiplier)
{
	Multiplier = ScoreMultiplier;
}

void AGameStateGame::CountSolvedRow(int32 NumberOfTiles)
{
	if (NumberOfTiles < 3)
	{
		UE_LOG(LogTemp, Warning, TEXT("GameState only found %d Tiles. This shouldn't happen!"), NumberOfTiles);
		return;
	}

	int32 ScoreToAdd = 0;
	for (int32 i = 0; i < NumberOfTiles; i++)
	{
		if (i >= Multiplier.Num())
		{
			ScoreToAdd += (TileScore * Multiplier[Multiplier.Num()-1].Multiplier);
		}
		else
		{
			ScoreToAdd += (TileScore * Multiplier[i].Multiplier);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Adding Score: %d"), ScoreToAdd);

	GameScore.AddScore(ScoreToAdd);

	UE_LOG(LogTemp, Warning, TEXT("New Score: %d"), GameScore.GetScore());
}

