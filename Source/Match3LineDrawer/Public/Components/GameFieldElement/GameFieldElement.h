// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"
#include "Structs/ElementInformation/ElementInformation.h"
#include "GameFieldElement.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API UGameFieldElement : public UStaticMeshComponent, public IGameFieldElementInterface
{
	GENERATED_BODY()


public:
	UGameFieldElement();

public:

	virtual void SetColorInformation(int32 ColorNumber) override;

	void SetColorNumber(int32 ColorNumber);

	virtual void SetMaterialInterface(class UMaterialInterface* Material) override;
	void SetUpperElement(IGameFieldElementInterface* Upper);
	virtual bool HasUpperElement() const override;
	virtual IGameFieldElementInterface* GetUpperElement() const override;
	
protected:
	virtual void BeginPlay() override;

private:
	virtual void SetHighlight(bool IsHighlighted = false) override;
	// OnEndMouseOver Event Listener
	UFUNCTION()
	void OnEndMouseOver(UPrimitiveComponent* TouchedComponent);

	// OnBeginMouseOver Event Listener
	UFUNCTION()
	void OnBeginMouseOver(UPrimitiveComponent* TouchedComponent);

private:
	UPROPERTY(VisibleAnywhere, Category = "Information")
	FElementInformation ElementInformation;
	
	IGameFieldElementInterface* UpperElement;

	// Inherited via IGameFieldElementInterface
	virtual int32 GetColorNumber() const override;


	// Inherited via IGameFieldElementInterface
	virtual UMaterialInterface* GetMaterialInterface() override;


	// Inherited via IGameFieldElementInterface

};
