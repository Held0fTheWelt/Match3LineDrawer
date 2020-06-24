// @Yves Tanas 2020


#include "Com/Communicator.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/GameField/GameFieldInterface.h"
#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"
#include "Interfaces/Controller/PlayerControllerInterface.h"
#include "Interfaces/States/PlayerStateInterface.h"

#pragma region
void Communicator::BroadcastLevelLoad(const class UWorld* World, FGameSetup& GameSetup)
{
	SpreadColorSet(World, GameSetup.Colors);
}
#pragma endregion

void Communicator::ResetAllElements(const UWorld* World)
{
	ResetPlayerController(World);

	ResetPlayerState(World);

	ResetGameFieldComponents(World);
}