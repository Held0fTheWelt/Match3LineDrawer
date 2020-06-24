// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerStateInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayerStateInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IPlayerStateInterface
{
	GENERATED_BODY()
			
public:
	virtual void SetCurrentColorIndex(class IGameFieldElementInterface* ElementInterface) = 0;
	virtual int32 GetCurrentColorIndex() const = 0;
};
