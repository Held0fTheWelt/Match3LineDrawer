// @Yves Tanas 2020


#include "GameInstanceGame.h"


#include "Blueprint/UserWidget.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Widgets/Menu/MenuUserWidget.h"
#include "Widgets/Main/MainUserWidget.h"

UGameInstanceGame::UGameInstanceGame()
{
	MapName_Game = FName("Map_Game");
	MapName_Menu = FName("Map_Menu");

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FClassFinder<UUserWidget> MenuUI;
		ConstructorHelpers::FClassFinder<UUserWidget> MainUI;
		ConstructorHelpers::FClassFinder<UUserWidget> IngameMenuUI;
		FConstructorStatics()
			: MenuUI(TEXT("/Game/Blueprints/Widgets/Menu/W_MenuUI"))
			, MainUI(TEXT("/Game/Blueprints/Widgets/Game/W_GameUI"))
			, IngameMenuUI(TEXT("/Game/Blueprints/Widgets/IngameMenu/W_IngameMenuUI"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	MainMenuTemplate = ConstructorStatics.MenuUI.Class;
	MainUITemplate = ConstructorStatics.MainUI.Class;
	IngameMenuTemplate = ConstructorStatics.IngameMenuUI.Class;
}

void UGameInstanceGame::Init()
{
	Super::Init();
	
}
void UGameInstanceGame::Quit()
{
	FGenericPlatformMisc::RequestExit(true);
}
void UGameInstanceGame::OpenMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), MapName_Menu, true);
}

void UGameInstanceGame::OpenGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), MapName_Game, true);
}
