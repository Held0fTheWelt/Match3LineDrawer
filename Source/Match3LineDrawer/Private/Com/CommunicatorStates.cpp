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


#pragma region Set CurrentColorIndex
void Communicator::SetCurrentColorIndex(const UWorld* World, class IGameFieldElementInterface* Interface)
{
	IPlayerStateInterface* StateInterface = nullptr;
	if (!GetPlayerStateInterface(World, StateInterface))
	{
		return;
	}
	TArray<AActor*> Actors;
		
	StateInterface->SetCurrentColorIndex(Interface);
	
}
#pragma endregion

#pragma region Get CurrentColorIndex
int32 Communicator::GetCurrentColorIndex(const UWorld* World)
{
	IPlayerStateInterface* Interface = nullptr;
	if (!GetPlayerStateInterface(World, Interface))
	{
		return -1;
	}
	return Interface->GetCurrentColorIndex();	
}
#pragma endregion

void Communicator::AddToComboList(const UWorld* World, IGameFieldElementInterface* Interface)
{
	IPlayerStateInterface* StateInterface = nullptr;
	if (!GetPlayerStateInterface(World, StateInterface))
	{
		return;
	}
	StateInterface->AddToList(Interface);
}

void Communicator::PopComboList(const UWorld* World)
{
	IPlayerStateInterface* StateInterface = nullptr;
	if (!GetPlayerStateInterface(World, StateInterface))
	{
		return ;
	}
	StateInterface->PopList();
}

void Communicator::CountCurrentHighlight(const UWorld* World)
{
	IPlayerStateInterface* Interface = nullptr;
	if (!GetPlayerStateInterface(World, Interface))
	{
		return;
	}

	if (Interface->HasCurrentElementInterface())
	{
		IGameFieldElementInterface* Element = Interface->GetCurrentElementInterface();

		if (Element != nullptr)
		{
			Interface->AddToList(Element);
		}
	}
}


void Communicator::ResetPlayerState(const UWorld* World)
{
	IPlayerStateInterface* Interface = nullptr;
	if (!GetPlayerStateInterface(World, Interface))
	{
		return;
	}
	Interface->ResetValues();
}

bool Communicator::GetPlayerStateInterface(const UWorld* World, IPlayerStateInterface*& Interface)
{
	if (Interface == nullptr)
	{
		TArray<AActor*> Actors;

		UGameplayStatics::GetAllActorsWithInterface(World, UPlayerStateInterface::StaticClass(), Actors);

		for (auto Actor : Actors)
		{
			IPlayerStateInterface* StateInterface = Cast<IPlayerStateInterface>(Actor);
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
#pragma endregion