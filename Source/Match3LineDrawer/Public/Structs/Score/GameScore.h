// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameScore.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FGameScore
{
	GENERATED_BODY()

public:
	FGameScore();

public:
	UPROPERTY(VisibleAnywhere)
	int32 Score;
};

