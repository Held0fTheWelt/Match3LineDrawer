// @Yves Tanas 2020


#include "Com/Communicator.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/GameField/GameFieldInterface.h"

void Communicator::BroadcastLevelLoad(const class UWorld* World, FGameSetup& GameSetup)
{
	TArray<AActor*> Actors;
	
	UGameplayStatics::GetAllActorsWithInterface(World, UGameFieldInterface::StaticClass(), Actors);

	for (auto Actor : Actors)
	{
		IGameFieldInterface* Interface = Cast<IGameFieldInterface>(Actor);
		if (Interface != nullptr)
		{
			Interface->SetColourSet(GameSetup.Colors);
		}
	}
}

void Communicator::SetupMouse(const UWorld* World)
{
	APlayerController* Current = UGameplayStatics::GetPlayerController(World, 0);
	if (Current == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find PlayerController ! This shouldn't happen !"));
		return;
	}

	Current->bShowMouseCursor = true;
	Current->bEnableClickEvents = true;
	Current->bEnableMouseOverEvents = true;
	UWidgetBlueprintLibrary::SetInputMode_GameOnly(Current);
}
