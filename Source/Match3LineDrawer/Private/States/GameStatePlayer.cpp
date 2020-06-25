// @Yves Tanas 2020


#include "GameStatePlayer.h"

#include "Com/Communicator.h"
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
	Communicator::PlaySoundClip(GetWorld(), EGameAudioType::AT_CLICK, .5 + .1 * CurrentStatus.HeapCount);
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

bool AGameStatePlayer::MoveComplete()
{
	UE_LOG(LogTemp, Warning, TEXT("Move counted with a count of %d"), CurrentStatus.HeapCount);

	if (CurrentStatus.HeapCount < 3)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d tiles is too few to make a complete move. try again"), CurrentStatus.HeapCount);
		return false;
	}

	Communicator::RowSolved(GetWorld(), CurrentStatus.HeapCount);

	if (CurrentStatus.HeapCount >= 10)
	{
		Communicator::PlaySoundClip(GetWorld(), EGameAudioType::AT_TEN, 1);		
	}
	else if (CurrentStatus.HeapCount >= 8)
	{
		Communicator::PlaySoundClip(GetWorld(), EGameAudioType::AT_EIGHT, 1);
	}
	else if (CurrentStatus.HeapCount >= 6)
	{
		Communicator::PlaySoundClip(GetWorld(), EGameAudioType::AT_SIX, 1);
	}
	else if (CurrentStatus.HeapCount >= 3)
	{
		Communicator::PlaySoundClip(GetWorld(), EGameAudioType::AT_THREE, 1);
	}
	return true;
}

TArray<class IGameFieldElementInterface*>& AGameStatePlayer::GetHeap()
{
	return CurrentStatus.GetSortedHeap();
}
