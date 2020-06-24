// @Yves Tanas 2020

#include "Structs/Player/PlayerInformation.h"

FPlayerInformation::FPlayerInformation()
{
	MovesLeft = 10;
	Heap.Empty();
}

int32 FPlayerInformation::Pop()
{
	if (Heap.Num() > 0)
	{
		int32 Value = -1;
		Heap.HeapPop(Value,true);
		return Value;
	}
	else
	{
		return -1;
	}
}

void FPlayerInformation::Push(int32 Value)
{
	Heap.Push(Value);
}

void FPlayerInformation::SetCurrentColorIndex(int32 Index)
{
	CurrentColorIndex = Index;
}

int32 FPlayerInformation::GetCurrentColorIndex() const
{
	return CurrentColorIndex;
}
