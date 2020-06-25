// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EGameAudioType : uint8
{
	AT_NONE		UMETA(DisplayName = "None selected"),
	AT_HOVER	UMETA(DisplayName = "Hover Sound Playing"),
	AT_CLICK	UMETA(DisplayName = "Click Sound Playing"),
	AT_THREE	UMETA(DisplayName = "Three Lines Playing"),
	AT_SIX		UMETA(DisplayName = "6 Lines Playing"),
	AT_EIGHT	UMETA(DisplayName = "8 Lines Playing"),
	AT_TEN		UMETA(DisplayName = "10 Lines Playing"),
	AT_FAILURE	UMETA(DisplayName = "Failure Sound Playing")
};