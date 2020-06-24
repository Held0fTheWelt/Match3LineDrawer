// @Yves Tanas 2020


#include "Com/Communicator.h"

#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Interfaces/GameField/GameFieldInterface.h"
#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"
#include "Interfaces/Controller/PlayerControllerInterface.h"
#include "Interfaces/States/PlayerStateInterface.h"

#pragma region Spread ColorSet
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
#pragma endregion

#pragma region Reset GameField Components
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
#pragma endregion