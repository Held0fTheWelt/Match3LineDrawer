// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "AudioSetup.generated.h"


USTRUCT(BlueprintType)
struct MATCH3LINEDRAWER_API FAudioSetup
{
	GENERATED_BODY()

public:
	FAudioSetup();

public:
	UPROPERTY(VisibleAnywhere)
	class USoundBase* HoverSound;

	UPROPERTY(VisibleAnywhere)
	class USoundBase* ClickedSound;

	UPROPERTY(VisibleAnywhere)
	class USoundBase* FailureSound;
	
	UPROPERTY(VisibleAnywhere)
	class USoundBase* ThreeLine;

	UPROPERTY(VisibleAnywhere)
	class USoundBase* SixLine;

	UPROPERTY(VisibleAnywhere)
	class USoundBase* EightLine;

	UPROPERTY(VisibleAnywhere)
	class USoundBase* TenLine;

};

