// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"

#include "Structs/Setup/GameSetup.h"

/**
 * 
 */
class MATCH3LINEDRAWER_API Communicator
{
public:
    static void BroadcastLevelLoad(const class UWorld* World, FGameSetup& GameSetup);

    static void SetupMouse(const class UWorld* World);
};
