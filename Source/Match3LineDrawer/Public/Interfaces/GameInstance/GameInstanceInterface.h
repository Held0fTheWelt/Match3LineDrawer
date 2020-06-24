// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameInstanceInterface.generated.h"

UINTERFACE(MinimalAPI)
class UGameInstanceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IGameInstanceInterface
{
	GENERATED_BODY()

public:
	virtual void Quit() = 0;
	virtual void OpenGame() = 0;
	virtual void OpenMenu() = 0;
};
