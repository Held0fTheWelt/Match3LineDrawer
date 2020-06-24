// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API UMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UButton* Start;
	UPROPERTY(meta = (BindWidget))
	class UButton* Quit;
};
