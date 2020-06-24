// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerControllerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayerControllerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IPlayerControllerInterface
{
	GENERATED_BODY()

public:
	virtual const bool GetMouseIsPressed() const = 0;
	virtual void ResetPlayerControllerValues() = 0;
};
