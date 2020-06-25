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

bool Communicator::GetGameFieldInterface(const UWorld* World, IGameFieldInterface*& Interface)
{
	TArray<AActor*> Actors;

	UGameplayStatics::GetAllActorsWithInterface(World, UGameFieldInterface::StaticClass(), Actors);

	for (auto Actor : Actors)
	{
		IGameFieldInterface* FieldInterface = Cast<IGameFieldInterface>(Actor);
		if (FieldInterface != nullptr)
		{
			Interface = FieldInterface;
			return true;
		}
	}
	return false;
}

#pragma region Spread ColorSet
void Communicator::SpreadColorSet(const UWorld* World, FColorDefinition& Colordefinition)
{
	IGameFieldInterface* Interface = nullptr;
	if (!(GetGameFieldInterface(World, Interface)))
	{
		return;
	}
	
	Interface->SetColourSet(Colordefinition);	
}
#pragma endregion

#pragma region Reset GameField Components
void Communicator::ResetGameFieldComponents(const UWorld* World)
{
	IGameFieldInterface* Interface = nullptr;
	if (!(GetGameFieldInterface(World, Interface)))
	{
		return;
	}
	TArray<IGameFieldElementInterface*> Elements = Interface->GetGameFieldElements();

	for (auto Element : Elements)
	{
		Element->SetHighlight();
	}
}
#pragma endregion

void Communicator::UpdateGameField(const UWorld* World, TArray<class IGameFieldElementInterface*> Heap)
{
	IGameFieldInterface* Interface = nullptr;
	if (!(GetGameFieldInterface(World, Interface)))
	{
		return;
	}

	for (auto Element : Heap)
	{
		Interface->UpdateGameField(Element);
	}
}