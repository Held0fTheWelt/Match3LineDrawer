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
	TArray<int32> Heap;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentColorIndex;

	IGameFieldElementInterface* ElementInterface;

public:
	int32 Pop();
	void Push(int32 Value);

	void SetCurrentColorIndex(int32 Index);
	int32  GetCurrentColorIndex() const;

	IGameFieldElementInterface* GetCurrentInterface();
	void SetInterface(IGameFieldElementInterface* Interface);
	void RemoveInterface();
	bool HasCurrentInterface() const;
};

