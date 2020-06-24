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

#pragma region Setup Mouse
void Communicator::SetupMouse(const UWorld* World)
{
	APlayerController* PlayerController = nullptr;

	if (!GetPlayerController(World, PlayerController)) return;
	
	PlayerController->bShowMouseCursor = true;
	PlayerController->bEnableClickEvents = true;
	PlayerController->bEnableMouseOverEvents = true;
//	UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
}
#pragma endregion

#pragma region Get PlayerController
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
#pragma endregion

#pragma region Get PlayerControllerInterface
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


#pragma region Is Mouse Down
bool Communicator::IsMouseDown(const UWorld* World) 
{
	IPlayerControllerInterface* Interface= nullptr;

	if (!GetPlayerControllerInterface(World, Interface)) return false;

	return Interface->GetMouseIsPressed();
}
#pragma endregion

void Communicator::ResetPlayerController(const UWorld* World)
{
	IPlayerControllerInterface* Interface = nullptr;

	if (!GetPlayerControllerInterface(World, Interface)) return;

	Interface->ResetPlayerControllerValues();
}