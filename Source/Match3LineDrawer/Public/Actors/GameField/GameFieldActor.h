// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/UObjectGlobals.h"
#include "GameFramework/Actor.h"
#include "Interfaces/GameField/GameFieldInterface.h"
#include "GameFieldActor.generated.h"

UCLASS()
class MATCH3LINEDRAWER_API AGameFieldActor : public AActor, public IGameFieldInterface
{
	GENERATED_BODY()
	
public:	
	AGameFieldActor(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	
public:
	/** Static mesh to create */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameField Settings")
	int32 SizeX;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameField Settings")
	int32 SizeY;

protected:
	/** Storage for all mesh components */
	UPROPERTY(VisibleAnywhere, Transient, Category = Components)
	TArray<class UGameFieldElement*> GameFieldElements;

	UPROPERTY(EditAnywhere)
	UMaterialInterface* Material;

private:
	const FVector CalculateElementPosition(int8 i, int8 j);

	virtual void SetColourSet(FColorDefinition& ColorDefinition) override;
};
