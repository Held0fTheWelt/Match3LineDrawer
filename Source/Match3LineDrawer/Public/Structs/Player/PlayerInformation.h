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

	UPROPERTY(VisibleAnywhere)
	int32 CurrentColorIndex;

	IGameFieldElementInterface* CurrentElement;

public:
	IGameFieldElementInterface* Pop();
	void Push(IGameFieldElementInterface* Value);

	void SetCurrentColorIndex(int32 Index);
	int32  GetCurrentColorIndex() const;

	IGameFieldElementInterface* GetCurrentInterface();
	void SetInterface(IGameFieldElementInterface* Interface);
	void RemoveInterface();
	bool HasCurrentInterface() const;
};

