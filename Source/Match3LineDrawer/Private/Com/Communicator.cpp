// @Yves Tanas 2020


#include "Com/Communicator.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/Controller/PlayerControllerInterface.h"
#include "Interfaces/GameField/GameFieldInterface.h"
#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"
#include "Interfaces/GameMode/GameModeInterface.h"
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

bool Communicator::GetGameModeInterface(const UWorld* World, IGameModeInterface*& Interface)
{
	if (Interface == nullptr)
	{
		TArray<AActor*> Actors;

		UGameplayStatics::GetAllActorsWithInterface(World, UGameModeInterface::StaticClass(), Actors);

		for (auto Actor : Actors)
		{
			IGameModeInterface* StateInterface = Cast<IGameModeInterface>(Actor);
			if (StateInterface != nullptr)
			{
				Interface = StateInterface;
				return true;
			}
		}
		return false;
	}
	return true;
}

void Communicator::PlaySoundClip(const UWorld* World, EGameAudioType AudioType, float Pitch)
{
	IGameModeInterface* ModeInterface = nullptr;
	if (!GetGameModeInterface(World, ModeInterface))
	{
		return;
	}

	ModeInterface->PlayAudioClip(AudioType, Pitch);
}