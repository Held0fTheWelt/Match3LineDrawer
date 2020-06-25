// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Structs/Setup/GameSetup.h"
#include "GameModeGame.generated.h"

UCLASS(minimalapi)
class AGameModeGame : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameModeGame();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	FGameSetup GameSetup;
	
protected:
	virtual void BeginPlay() override;

private:
	class IGameStateInterface* StateInterface;
};



