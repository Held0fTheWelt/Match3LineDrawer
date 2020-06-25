// @Yves Tanas 2020

#include "Structs/Score/GameScore.h"

FGameScore::FGameScore()
{
	Score = 0;
}

void FGameScore::ResetScore()
{
	Score = 0;
}

void FGameScore::AddScore(int32 ScoreToAdd)
{
	Score += ScoreToAdd;
}

int32 FGameScore::GetScore() const
{
	return Score;
}
