// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
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
};

