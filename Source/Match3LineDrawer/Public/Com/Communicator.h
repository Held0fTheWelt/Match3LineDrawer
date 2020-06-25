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

    static void ResetPlayerController(const UWorld* World);

    static void ResetPlayerState(const UWorld* World);

    static void ResetAllElements(const UWorld* World);

    static void SetCurrentColorIndex(const UWorld* World, class IGameFieldElementInterface* Interface);

    static int32 GetCurrentColorIndex(const UWorld* World);

    static void AddToComboList(const UWorld* World, class IGameFieldElementInterface* Interface);

    static void PopComboList(const UWorld* World);

    static void CountCurrentHighlight(const UWorld* World);

    static void RowSolved(const UWorld* World, int32 NumberOfTiles);

    static void ClearHeap(TArray<class IPlayerControllerInterface*> Elements);

private:
    static bool GetPlayerController(const UWorld* World, class APlayerController* &PlayerController);

    static bool GetPlayerControllerInterface(const UWorld* World, class IPlayerControllerInterface* &Interface);

    static bool GetPlayerStateInterface(const UWorld* World, class IPlayerStateInterface* &Interface);

    static bool GetGameFieldInterface(const UWorld* World, class IGameFieldInterface* &Interface);

    static bool GetGameStateInterface(const UWorld* World, class IGameStateInterface* &Interface);

    static void SpreadColorSet(const UWorld* World, FColorDefinition& Colordefinition);

};
