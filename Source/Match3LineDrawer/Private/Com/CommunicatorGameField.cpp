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
#include "Structs/ElementReturnInformation/ElementReturnInformation.h"

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

FElementReturnInformation Communicator::ClearCurrentFieldElementMaterial(const UWorld* World, IGameFieldElementInterface* Element)
{
	IGameFieldInterface* GameField;
	if (!(GetGameFieldInterface(World, GameField)))
	{
		return FElementReturnInformation();
	}

	if (Element->HasUpperElement())
	{
		FElementReturnInformation CurrentInformation = FElementReturnInformation(Element->GetColorNumber(), Element->GetMaterialInterface());
		FElementReturnInformation ReturnInformation = ClearCurrentFieldElementMaterial(World, Element->GetUpperElement());
		UE_LOG(LogTemp, Warning, TEXT("Element %s now has returned Colorindex %d"), * Element->GetComponentName(), ReturnInformation.ColorIndex);
		Element->SetColorInformation(ReturnInformation.ColorIndex);
		//Element->SetMaterialInterface(GameField->GetMaterialInterface(ReturnInformation.ColorIndex));
		UE_LOG(LogTemp, Warning, TEXT("Element %s is returning Colorindex %d"), *Element->GetComponentName(),CurrentInformation.ColorIndex);
		return CurrentInformation;
	}
	else
	{
		FElementReturnInformation CurrentInformation = FElementReturnInformation(Element->GetColorNumber(), Element->GetMaterialInterface());

		IGameFieldInterface* Interface = nullptr;
		if (!GetGameFieldInterface(World, Interface))
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not find GameField ! This shouldn't happen !"));
			return CurrentInformation;
		}
		FElementReturnInformation ReturnInformation = Interface->GetRandomMaterialInterface();

		UE_LOG(LogTemp, Warning, TEXT("Element %s now has new Colorindex %d"), *Element->GetComponentName(), ReturnInformation.ColorIndex);
		Element->SetColorInformation(ReturnInformation.ColorIndex);
		//Element->SetMaterialInterface(GameField->GetMaterialInterface(ReturnInformation.ColorIndex));
		UE_LOG(LogTemp, Warning, TEXT("Element %s is returning Colorindex %d"), *Element->GetComponentName(), CurrentInformation.ColorIndex);

		return CurrentInformation;
	}
}