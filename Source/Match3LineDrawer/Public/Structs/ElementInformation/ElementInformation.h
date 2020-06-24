// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "ElementInformation.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FElementInformation
{
	GENERATED_BODY()

public:
	FElementInformation();

public:
	UPROPERTY(VisibleAnywhere)
	int32 ColorNumber;

public:
	void SetColorNumber(int32 ColorNumber);
};
