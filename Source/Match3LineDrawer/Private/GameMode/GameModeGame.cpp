// @Yves Tanas 2020

#include "GameModeGame.h"

#include "Com/Communicator.h"
#include "Engine/World.h"
#include "GamePlayerController.h"
#include "GameFramework/PlayerController.h"
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
	
}
