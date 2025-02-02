// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "Enums/AudioType/AudioType.h"
#include "Structs/Setup/GameSetup.h"
#include "Structs/ElementReturnInformation/ElementReturnInformation.h"
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
    
    static void PlaySoundClip(const UWorld* World, EGameAudioType AudioType, float Pitch);

    static void RowSolved(const UWorld* World, int32 NumberOfTiles);

    static void ClearHeap(const UWorld* World, TArray<class IGameFieldElementInterface*> Elements);

private:
    static bool GetPlayerController(const UWorld* World, class APlayerController* &PlayerController);

    static bool GetPlayerControllerInterface(const UWorld* World, class IPlayerControllerInterface* &Interface);

    static bool GetPlayerStateInterface(const UWorld* World, class IPlayerStateInterface* &Interface);

    static bool GetGameFieldInterface(const UWorld* World, class IGameFieldInterface* &Interface);

    static bool GetGameStateInterface(const UWorld* World, class IGameStateInterface* &Interface);

    static bool GetGameModeInterface(const UWorld* World, class IGameModeInterface* &Interface);

    static void SpreadColorSet(const UWorld* World, FColorDefinition& Colordefinition);

    static FElementReturnInformation ClearCurrentFieldElementMaterial(const UWorld* World, class IGameFieldElementInterface* Element);

};
