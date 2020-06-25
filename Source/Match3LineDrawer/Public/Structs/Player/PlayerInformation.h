// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/GameFieldElement/GameFieldElementInterface.h"
#include "PlayerInformation.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FPlayerInformation
{
	GENERATED_BODY()

public:
	FPlayerInformation();

public:
	UPROPERTY(VisibleAnywhere)
	int32 MovesLeft;

	UPROPERTY(VisibleAnywhere)
	int32 HeapCount;

	TArray<IGameFieldElementInterface*> Heap;
	TArray<IGameFieldElementInterface*> &GetSortedHeap();

	UPROPERTY(VisibleAnywhere)
	int32 CurrentColorIndex;

	IGameFieldElementInterface* CurrentElement;
	TArray<IGameFieldElementInterface*> SortedHeap;

public:
	IGameFieldElementInterface* Pop();
	void Push(IGameFieldElementInterface* Value);

	void SetCurrentColorIndex(int32 Index);
	int32  GetCurrentColorIndex() const;

	IGameFieldElementInterface* GetCurrentInterface();
	void SetInterface(IGameFieldElementInterface* Interface);
	void RemoveInterface();
	bool HasCurrentInterface() const;
	IGameFieldElementInterface* TestUpper(IGameFieldElementInterface* BaseElement, IGameFieldElementInterface* Element);
};

