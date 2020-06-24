// @Yves Tanas 2020


#include "GameFieldElement.h"

#include "Engine/StaticMesh.h"
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
	SetHighlight(false);
}

void UGameFieldElement::OnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("Some warning message"));
	SetHighlight(true);
}
