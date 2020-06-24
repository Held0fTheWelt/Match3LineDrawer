// @Yves Tanas 2020


#include "Widgets\Crosshair\CrosshairUserWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Components/PanelWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Engine/Texture2D.h"
#include "Components/PanelSlot.h"
#include "Components/CanvasPanelSlot.h"
#include "UObject/ConstructorHelpers.h"

UCrosshairUserWidget::UCrosshairUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UCrosshairUserWidget::NativeConstruct()
{
	Super::NativeConstruct();


	if (WidgetTree == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Widget Tree was null"));
		return;
	}
		
	Canvas = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass());
	WidgetTree->RootWidget = Canvas;
	
	CrossHair = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
	Canvas->AddChild(CrossHair);
	
	if (UCanvasPanelSlot* NewSlot = Cast<UCanvasPanelSlot>(CrossHair->Slot))
	{
		NewSlot->SetSize(FVector2D(50.f, 50.f));
	}


	FString PathToLoad = "/Game/Images/UI/Crosshair.Crosshair";
	UTexture2D* ImageToShow = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(PathToLoad)));;

	if (ImageToShow != nullptr)
	{
		CrossHair->SetBrushFromTexture(ImageToShow, true);
		UE_LOG(LogTemp, Warning, TEXT("Crosshair ready"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ImageToShow was null"));
	}

	AddToViewport(1);
}