// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/GameInstance/GameInstanceInterface.h"
#include "GameInstanceGame.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API UGameInstanceGame : public UGameInstance, public IGameInstanceInterface
{
	GENERATED_BODY()
	
public:
	UGameInstanceGame();

	/** virtual function to allow custom GameInstances an opportunity to set up what it needs */
	virtual void Init();


private:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainUITemplate;
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MainMenuTemplate;
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> IngameMenuTemplate;

	UPROPERTY(EditDefaultsOnly, Category = "Maps")
	FName MapName_Menu;
	UPROPERTY(EditDefaultsOnly, Category = "Maps")
	FName MapName_Game;

private:
	UFUNCTION(Exec)
	virtual void Quit() override;
	UFUNCTION(Exec)
	virtual void OpenGame() override;
	UFUNCTION(Exec)
	virtual void OpenMenu() override;	
};
