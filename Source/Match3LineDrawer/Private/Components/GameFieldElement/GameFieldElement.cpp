// @Yves Tanas 2020


#include "GameFieldElement.h"


#include "Com/Communicator.h"
#include "Engine/StaticMesh.h"
#include "Interfaces/GameField/GameFieldInterface.h"
#include "Materials/MaterialInterface.h"
#include "..\..\..\Public\Components\GameFieldElement\GameFieldElement.h"

UGameFieldElement::UGameFieldElement()
{
	UpperElement = nullptr;
}

void UGameFieldElement::BeginPlay()
{
	Super::BeginPlay();

	OnBeginCursorOver.AddDynamic(this, &UGameFieldElement::OnBeginMouseOver);
	OnEndCursorOver.AddDynamic(this, &UGameFieldElement::OnEndMouseOver);
}

void UGameFieldElement::SetHighlight(bool IsHighlighted)
{
	if (IsHighlighted)
	{
		SetCustomDepthStencilValue(2);
		SetRenderCustomDepth(true);
	}
	else
	{		
		SetCustomDepthStencilValue(0);
		SetRenderCustomDepth(false);
	}
}

void UGameFieldElement::OnEndMouseOver(UPrimitiveComponent* TouchedComponent)
{
	if (Communicator::IsMouseDown(GetWorld()))
	{

	}
	else
	{
		SetHighlight();
	}
}

void UGameFieldElement::OnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	//UE_LOG(LogTemp, Warning, TEXT("Hover Component: %s"),*GetName());

	if (!Communicator::IsMouseDown(GetWorld()))
	{
		Communicator::SetCurrentColorIndex(GetWorld(), this);
		SetHighlight(true);
	}
	else
	{
		if (Communicator::GetCurrentColorIndex(GetWorld()) != ElementInformation.ColorNumber)
		{
			Communicator::ResetAllElements(GetWorld());
		}
		else
		{
			Communicator::AddToComboList(GetWorld(), this);
			SetHighlight(true);
		}
	}
}

int32 UGameFieldElement::GetColorNumber() const
{
	return ElementInformation.ColorNumber;
}

UMaterialInterface* UGameFieldElement::GetMaterialInterface()
{
	return GetMaterial(0);
}

FString UGameFieldElement::GetComponentName() const
{
	return GetName();
}

void UGameFieldElement::SetMaterialInterface(UMaterialInterface* Material)
{
	for (int i = 0; i < GetMaterials().Num(); i++)
	{
		SetMaterial(i, Material);
	}
}

void UGameFieldElement::SetColorInformation(int32 Number)
{
	IGameFieldInterface* GameField = Cast<IGameFieldInterface>(GetOwner());

	if (GameField == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not Cast Owner to GameFieldInterface! This shouldn't happen !"));
		return;
	}
	else
	{
		UMaterialInterface* MaterialInterface = GameField->GetMaterialInterface(Number);

		if (MaterialInterface != nullptr)
		{
			SetMaterialInterface(MaterialInterface);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not Get MaterialInterface from GameFieldInterface! This only leads to wrong index usage!"));
		}
	}

	ElementInformation.ColorNumber = Number;
}

void UGameFieldElement::SetColorNumber(int32 ColorNumber)
{
	ElementInformation.SetColorNumber(ColorNumber);
}

void UGameFieldElement::SetUpperElement(IGameFieldElementInterface* Upper)
{
	UpperElement = Upper;
}

bool UGameFieldElement::HasUpperElement() const
{
	return !(UpperElement == nullptr);
}

IGameFieldElementInterface* UGameFieldElement::GetUpperElement() const
{
	return UpperElement;
}
