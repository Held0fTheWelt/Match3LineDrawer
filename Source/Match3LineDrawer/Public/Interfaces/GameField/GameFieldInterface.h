// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Structs/Colors/ColorDefinition.h"
#include "Structs/ElementReturnInformation/ElementReturnInformation.h"
#include "GameFieldInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameFieldInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IGameFieldInterface
{
	GENERATED_BODY()

public:
	virtual void SetColourSet(FColorDefinition& ColorDefinition) = 0;
	virtual TArray<class IGameFieldElementInterface*> GetGameFieldElements() = 0;
	virtual class UMaterialInterface* GetMaterialInterface(int32 index) = 0;
	virtual FElementReturnInformation  GetRandomMaterialInterface() = 0;
};
