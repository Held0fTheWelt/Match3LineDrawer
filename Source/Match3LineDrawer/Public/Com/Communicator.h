// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "Structs/Setup/GameSetup.h"

/**
 * 
 */
class MATCH3LINEDRAWER_API Communicator
{
public:
    static void BroadcastLevelLoad(const class UWorld* World, FGameSetup& GameSetup);

    static void SetupMouse(const class UWorld* World);

    static bool IsMouseDown(const UWorld* World);

    static void ResetGameFieldComponents(const UWorld* World);

private:
    static bool GetPlayerController(const UWorld* World, class APlayerController* &PlayerController);

    static bool GetPlayerControllerInterface(const UWorld* World, class IPlayerControllerInterface* &Interface);

    static void SpreadColorSet(const UWorld* World, FColorDefinition& Colordefinition);

};
