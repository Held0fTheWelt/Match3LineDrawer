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
	CurrentStatus.HeapCount = 0;
	CurrentStatus.CurrentElement = nullptr;
	CurrentStatus.Heap.Empty();
}

void AGameStatePlayer::AddToList(IGameFieldElementInterface* Element)
{
	CurrentStatus.Push(Element);
}

IGameFieldElementInterface* AGameStatePlayer::PopList()
{
	return CurrentStatus.Pop();
}

bool AGameStatePlayer::HasCurrentElementInterface() const
{
	return !(CurrentStatus.CurrentElement == nullptr);
}

IGameFieldElementInterface* AGameStatePlayer::GetCurrentElementInterface()
{
	return CurrentStatus.CurrentElement;
}

bool AGameStatePlayer::IsElementValidNew(IGameFieldElementInterface* NewElement) const
{
	for (auto Element : CurrentStatus.Heap)
	{
		if (Element == NewElement)
		{
			return false;
		}
	}

	return true;
}

bool AGameStatePlayer::IsElementPrevious(IGameFieldElementInterface* NewElement) const
{
	if (CurrentStatus.HeapCount < 2)
		return false;
	if (CurrentStatus.Heap[CurrentStatus.Heap.Num() -2] == NewElement)
		return true;

	return false;
}
