// @Yves Tanas 2020


#include "GameFieldElement.h"


#include "Com/Communicator.h"
#include "Engine/StaticMesh.h"
#include "Interfaces/GameField/GameFieldInterface.h"
#include "Materials/MaterialInterface.h"


void UGameFieldElement::BeginPlay()
{
	Super::BeginPlay();

	OnBeginCursorOver.AddDynamic(this, &UGameFieldElement::OnBeginMouseOver);
	OnEndCursorOver.AddDynamic(this, &UGameFieldElement::OnEndMouseOver);
}

void UGameFieldElement::SetNewMaterialInstance(UMaterialInterface* MaterialInterface)
{
	for (int i = 0; i < GetMaterials().Num(); i++)
	{
		SetMaterial(i, MaterialInterface);
	}
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

void UGameFieldElement::SetColorInformation(int32 ColorNumber)
{
	IGameFieldInterface* GameField = Cast<IGameFieldInterface>(GetOwner());

	if (GameField == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not Cast Owner to GameFieldInterface! This shouldn't happen !"));
		return;
	}
	else
	{
		UMaterialInterface* MaterialInterface = GameField->GetMaterialInterface(ColorNumber);

		if (MaterialInterface != nullptr)
		{
			SetNewMaterialInstance(MaterialInterface);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not Get MaterialInterface from GameFieldInterface! This only leads to wrong index usage!"));
		}
	}
}

void UGameFieldElement::SetColorNumber(int32 ColorNumber)
{
	ElementInformation.SetColorNumber(ColorNumber);
}
