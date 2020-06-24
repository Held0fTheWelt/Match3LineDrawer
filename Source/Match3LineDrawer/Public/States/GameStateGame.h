// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "Structs/Score/GameScore.h"
#include "GameStateGame.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API AGameStateGame : public AGameStateBase
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Score")
	FGameScore GameScore;	
};
