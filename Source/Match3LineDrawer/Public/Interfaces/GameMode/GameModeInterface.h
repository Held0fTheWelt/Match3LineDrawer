// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Enums/AudioType/AudioType.h"
#include "UObject/Interface.h"
#include "GameModeInterface.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSolveGroup);

UINTERFACE(MinimalAPI)
class UGameModeInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class MATCH3LINEDRAWER_API IGameModeInterface
{
	GENERATED_BODY()

public:
	virtual void RowSolved(int32 RowCount) = 0;
	virtual void PlayAudioClip(EGameAudioType  AudioType, float Pitch) = 0;
};
