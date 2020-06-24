// @Yves Tanas 2020


#include "GameStatePlayer.h"

#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"

int32 AGameStatePlayer::GetCurrentColorIndex() const
{
	return CurrentStatus.GetCurrentColorIndex();
}

void AGameStatePlayer::SetCurrentColorIndex(IGameFieldElementInterface* ElementInterface)
{
	CurrentStatus.SetCurrentColorIndex(ElementInterface->GetColorNumber());
}
