// @Yves Tanas 2020

#include "GameModeGame.h"

#include "Com/Communicator.h"
#include "Engine/World.h"
#include "Enums/AudioType/AudioType.h"
#include "GamePlayerController.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/GameStateBase.h"
#include "Interfaces/States/GameStateInterface.h"
#include "Kismet/GameplayStatics.h"
#include "Structs/AudioSetup/AudioSetup.h"

AGameModeGame::AGameModeGame()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGamePlayerController::StaticClass();

}

void AGameModeGame::BeginPlay()
{
	Super::BeginPlay();

	UWorld* const World = GetWorld();

	Communicator::SetupMouse(World);

	Communicator::BroadcastLevelLoad(World, GameSetup);

	AGameStateBase* GameStateBase = GetGameState<AGameStateBase>();

	if (GameStateBase == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find GameStateBase ! This shouldn't happen !"));
		return;
	}

	StateInterface = Cast<IGameStateInterface>(GameStateBase);

	if (StateInterface == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not cast GameStateBase to GameStateInterface ! This shouldn't happen !"));
	}	

	StateInterface->SetNewTileScore(GameSetup.PointsPerTile);
	StateInterface->SetNewTileCountMultiplier(GameSetup.Multiplier.GetMultiplierList());
}

void AGameModeGame::RowSolved(int32 RowCount)
{
	
}

void AGameModeGame::PlayAudioClip(EGameAudioType  AudioType, float Pitch)
{
	switch (AudioType)
	{
	case EGameAudioType::AT_NONE:
		break;
	case EGameAudioType::AT_HOVER:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.HoverSound, FVector(0, 0, 0), 1, Pitch);
		break;
	case EGameAudioType::AT_CLICK:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.ClickedSound, FVector(0, 0, 0), 1, Pitch);		
		break;
	case EGameAudioType::AT_THREE:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.ThreeLine, FVector(0, 0, 0), 1, Pitch);
		break;
	case EGameAudioType::AT_SIX:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.SixLine, FVector(0, 0, 0), 1, Pitch);
		break;
	case EGameAudioType::AT_EIGHT:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.EightLine, FVector(0, 0, 0), 1, Pitch);
		break;
	case EGameAudioType::AT_TEN:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.TenLine, FVector(0, 0, 0), 1, Pitch);
		break;
	case EGameAudioType::AT_FAILURE:
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), GameSetup.AudioSetup.FailureSound, FVector(0, 0, 0), 1, Pitch);
		break;
	default:
		break;
	}
}
