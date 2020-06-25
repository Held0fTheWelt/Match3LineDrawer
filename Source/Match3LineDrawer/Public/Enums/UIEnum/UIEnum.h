// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class EUIEnum : uint8
{
	UI_MENU		UMETA(DisplayName = "Menu"),
	UI_PAUSE	UMETA(DisplayName = "Pause"),
	UI_GAME		UMETA(DisplayName = "Game")
};