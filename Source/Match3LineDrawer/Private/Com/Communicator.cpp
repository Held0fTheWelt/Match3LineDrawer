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

void Communicator::BroadcastLevelLoad(const class UWorld* World, FGameSetup& GameSetup)
{
	SpreadColorSet(World, GameSetup.Colors);
}

void Communicator::SetupMouse(const UWorld* World)
{
	APlayerController* PlayerController = nullptr;

	if (!GetPlayerController(World, PlayerController)) return;
	
	PlayerController->bShowMouseCursor = true;
	PlayerController->bEnableClickEvents = true;
	PlayerController->bEnableMouseOverEvents = true;
//	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
}

bool Communicator::GetPlayerController(const UWorld* World, APlayerController* &PlayerController)
{
	if (PlayerController == nullptr)
	{
		APlayerController* Current = UGameplayStatics::GetPlayerController(World, 0);
		if (Current == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find PlayerController ! This shouldn't happen !"));
			return false;
		}

		PlayerController = Current;
	}
	return true;
}

bool Communicator::GetPlayerControllerInterface(const UWorld* World, IPlayerControllerInterface*& Interface)
{
	if (Interface == nullptr)
	{
		APlayerController* Current = UGameplayStatics::GetPlayerController(World, 0);
		if (Current == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find PlayerController ! This shouldn't happen !"));
			return false;
		}

		IPlayerControllerInterface* CurrentInterface = Cast<IPlayerControllerInterface>(Current);
		if (CurrentInterface == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not cast PlayerController to Interface! This shouldn't happen !"));
			return false;
		}
		
		Interface = CurrentInterface;
	}
	return true;
}

void Communicator::SpreadColorSet(const UWorld* World, FColorDefinition& Colordefinition)
{
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsWithInterface(World, UGameFieldInterface::StaticClass(), Actors);

	for (auto Actor : Actors)
	{
		IGameFieldInterface* Interface = Cast<IGameFieldInterface>(Actor);
		if (Interface != nullptr)
		{
			Interface->SetColourSet(Colordefinition);
		}
	}
}

bool Communicator::IsMouseDown(const UWorld* World) 
{
	IPlayerControllerInterface* Interface= nullptr;

	if (!GetPlayerControllerInterface(World, Interface)) return false;

	return Interface->GetMouseIsPressed();
}

void Communicator::ResetGameFieldComponents(const UWorld* World)
{

	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsWithInterface(World, UGameFieldInterface::StaticClass(), Actors);

	for (auto Actor : Actors)
	{
		IGameFieldInterface* Interface = Cast<IGameFieldInterface>(Actor);
		if (Interface != nullptr)
		{
			TArray<IGameFieldElementInterface*> Elements = Interface->GetGameFieldElements();

			for (auto Element : Elements)
			{
				Element->SetHighlight();
			}
		}
	}
}

void Communicator::SetCurrentColorIndex(const UWorld* World, class IGameFieldElementInterface* ElementInterface)
{
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsWithInterface(World, UPlayerStateInterface::StaticClass(), Actors);

	for (auto Actor : Actors)
	{
		IPlayerStateInterface* Interface = Cast<IPlayerStateInterface>(Actor);
		if (Interface != nullptr)
		{
			Interface->SetCurrentColorIndex(ElementInterface);
		}
	}
}
