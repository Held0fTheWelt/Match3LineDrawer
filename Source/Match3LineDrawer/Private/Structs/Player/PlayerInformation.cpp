// @Yves Tanas 2020

#include "Structs/Player/PlayerInformation.h"

FPlayerInformation::FPlayerInformation()
{
	MovesLeft = 10;
	Heap.Empty();
	CurrentElement = nullptr;
	HeapCount = 0;
}

IGameFieldElementInterface* FPlayerInformation::Pop()
{
	if (Heap.Num() > 0)
	{
		IGameFieldElementInterface* Value = Heap.Pop(true);		
		HeapCount--;
		UE_LOG(LogTemp, Warning, TEXT("Heap popped. Now counts %d elements"), HeapCount);
		return Value;
	}
	else
	{
		return nullptr;
	}
}

void FPlayerInformation::Push(IGameFieldElementInterface* Value)
{
	Heap.Push(Value);
	HeapCount++;
	UE_LOG(LogTemp, Warning, TEXT("Heap pushed. Now counts %d elements"), HeapCount);
}

void FPlayerInformation::SetCurrentColorIndex(int32 Index)
{
	CurrentColorIndex = Index;
}

int32 FPlayerInformation::GetCurrentColorIndex() const
{
	return CurrentColorIndex;
}

void FPlayerInformation::SetInterface(IGameFieldElementInterface* Interface)
{
	CurrentElement = Interface;
}

void FPlayerInformation::RemoveInterface()
{
	CurrentElement = nullptr;
}

IGameFieldElementInterface* FPlayerInformation::GetCurrentInterface()
{
	return CurrentElement;
}

bool FPlayerInformation::HasCurrentInterface() const
{
	return !(CurrentElement == nullptr);
}
