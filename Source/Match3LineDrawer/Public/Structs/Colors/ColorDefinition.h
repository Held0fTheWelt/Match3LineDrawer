// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "ColorDefinition.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FColorDefinition
{
	GENERATED_BODY()

public:
	FColorDefinition();

public:
	UPROPERTY(EditDefaultsOnly, Category = "Colors")
	TArray<FColor> Colors;
};

