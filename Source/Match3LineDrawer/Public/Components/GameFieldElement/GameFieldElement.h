// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"
#include "GameFieldElement.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API UGameFieldElement : public UStaticMeshComponent, public IGameFieldElementInterface
{
	GENERATED_BODY()


public:
	void SetNewMaterialInstance(class UMaterialInterface* MaterialInterface);

protected:
	virtual void BeginPlay() override;

private:
	virtual void SetHighlight(bool IsHighlighted) override;
	// OnEndMouseOver Event Listener
	UFUNCTION()
	void OnEndMouseOver(UPrimitiveComponent* TouchedComponent);

	// OnBeginMouseOver Event Listener
	UFUNCTION()
	void OnBeginMouseOver(UPrimitiveComponent* TouchedComponent);
};
