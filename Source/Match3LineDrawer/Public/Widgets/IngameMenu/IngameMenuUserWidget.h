// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IngameMenuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API UIngameMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UButton* BackToGame;
	UPROPERTY(meta = (BindWidget))
	class UButton* BackToMenu;
};
