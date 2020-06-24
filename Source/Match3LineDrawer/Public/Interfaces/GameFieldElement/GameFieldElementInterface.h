// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameFieldElementInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameFieldElementInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IGameFieldElementInterface
{
	GENERATED_BODY()

public:
	virtual void SetHighlight(bool IsHighlighted = false) = 0;
	virtual void SetColorInformation(int32 ColorNumber) = 0;
};
