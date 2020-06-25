// @Yves Tanas 2020

#include "GameModeGame.h"

#include "Com/Communicator.h"
#include "Engine/World.h"
#include "GamePlayerController.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/GameStateBase.h"
#include "Interfaces/States/GameStateInterface.h"
#include "Kismet/GameplayStatics.h"

AGameModeGame::AGameModeGame()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGamePlayerController::StaticClass();

}

void AGameModeGame::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();

	Communicator::SetupMouse(World);

	Communicator::BroadcastLevelLoad(World, GameSetup);

	AGameStateBase* GameStateBase = GetGameState<AGameStateBase>();

	if (GameStateBase == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find GameStateBase ! This shouldn't happen !"));
		return;
	}

	StateInterface = Cast<IGameStateInterface>(GameStateBase);

	if (StateInterface == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not cast GameStateBase to GameStateInterface ! This shouldn't happen !"));
	}	

	StateInterface->SetNewTileCount(GameSetup.PointsPerTile);
}
