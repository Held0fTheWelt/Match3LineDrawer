// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"
#include "CrosshairUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API UCrosshairUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCrosshairUserWidget(const FObjectInitializer& ObjectInitializer);

public:
	
	UPROPERTY()
	class UCanvasPanel* Canvas;

	UPROPERTY()
	class UImage* CrossHair;

public:
	virtual void NativeConstruct() override;

};
