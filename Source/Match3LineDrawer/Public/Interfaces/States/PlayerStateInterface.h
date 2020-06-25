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
	virtual void SetCurrentColorIndex(class IGameFieldElementInterface* Interface) = 0;
	virtual int32 GetCurrentColorIndex() const = 0;
	virtual void ResetValues() = 0;
	virtual void AddToList(class IGameFieldElementInterface* Element) = 0;
	virtual class IGameFieldElementInterface* PopList() = 0;
	virtual bool HasCurrentElementInterface() const = 0;
	virtual class IGameFieldElementInterface* GetCurrentElementInterface() = 0;
	virtual bool IsElementValidNew(class IGameFieldElementInterface* NewElement) const = 0;
	virtual bool IsElementPrevious(class IGameFieldElementInterface* NewElement) const = 0;
	virtual bool MoveComplete() = 0;
	virtual TArray<class IGameFieldElementInterface*> GetHeap() = 0;
};
