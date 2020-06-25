// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "ElementReturnInformation.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FElementReturnInformation
{
	GENERATED_BODY()

public:
	FElementReturnInformation();
	FElementReturnInformation(int32 index, class UMaterialInterface* Material);

public:
	UPROPERTY(VisibleAnywhere)
	class UMaterialInterface* Material;

	UPROPERTY(VisibleAnywhere)
	int32 ColorIndex;
};
