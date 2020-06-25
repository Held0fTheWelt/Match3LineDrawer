// @Yves Tanas 2020

#include "Structs/Player/PlayerInformation.h"

#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"

FPlayerInformation::FPlayerInformation()
{
	MovesLeft = 10;
	Heap.Empty();
	CurrentElement = nullptr;
	HeapCount = 0;
}

TArray<IGameFieldElementInterface*>& FPlayerInformation::GetSortedHeap()
{
	SortedHeap.Empty();	

	//UE_LOG(LogTemp, Warning, TEXT("Current Heap:"));
	//UE_LOG(LogTemp, Warning, TEXT("-------------"));

	//for (auto Element : Heap)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Element: %s"), *Element->GetComponentName());

	//}
	//UE_LOG(LogTemp, Warning, TEXT("-------------"));

	while (Heap.Num() > 0)
	{
		IGameFieldElementInterface* Current = Heap.Pop();

		if (Current->HasUpperElement())
		{
			if (TestUpper(Current, Current->GetUpperElement()) == nullptr)
			{
				SortedHeap.Add(Current);
			}
			else
			{
				Heap.Insert(Current, 0);
			}
		}
		else
		{
			SortedHeap.Add(Current);
		}
	}

	/*UE_LOG(LogTemp, Warning, TEXT("Sorted Heap:"));
	UE_LOG(LogTemp, Warning, TEXT("-------------"));

	for (auto Element : SortedHeap)
	{
		UE_LOG(LogTemp, Warning, TEXT("Element: %s"), *Element->GetComponentName());

	}*/

	return SortedHeap;
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

IGameFieldElementInterface* FPlayerInformation::TestUpper(IGameFieldElementInterface* BaseElement, IGameFieldElementInterface* Element)
{
	if (Element->HasUpperElement())
	{
		IGameFieldElementInterface* Upper = Element->GetUpperElement();
		for (auto HeapElement : Heap)
		{
			if (HeapElement == Upper)
			{
				return Upper;
			}
		}

	}

	return nullptr;
}
