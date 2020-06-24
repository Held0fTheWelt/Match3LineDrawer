// @Yves Tanas 2020


#include "GameStatePlayer.h"

#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"

int32 AGameStatePlayer::GetCurrentColorIndex() const
{
	return CurrentStatus.GetCurrentColorIndex();
}

void AGameStatePlayer::SetCurrentColorIndex(IGameFieldElementInterface* Interface)
{
	CurrentStatus.SetCurrentColorIndex(Interface->GetColorNumber());
	CurrentStatus.CurrentElement = Interface;
}

void AGameStatePlayer::ResetValues()
{
	CurrentStatus.CurrentColorIndex = -1;
	CurrentStatus.CurrentElement = nullptr;
	CurrentStatus.Heap.Empty();
}

void AGameStatePlayer::AddToList(IGameFieldElementInterface* Element)
{
	CurrentStatus.Push(Element);
}

void AGameStatePlayer::PopList()
{
	CurrentStatus.Pop();
}

bool AGameStatePlayer::HasCurrentElementInterface() const
{
	return !(CurrentStatus.CurrentElement == nullptr);
}

IGameFieldElementInterface* AGameStatePlayer::GetCurrentElementInterface()
{
	return CurrentStatus.CurrentElement;
}
