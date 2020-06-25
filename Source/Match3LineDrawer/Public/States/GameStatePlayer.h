// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Structs/Player/PlayerInformation.h"
#include "Interfaces/States/PlayerStateInterface.h"
#include "GameStatePlayer.generated.h"

/**
 * 
 */
UCLASS()
class MATCH3LINEDRAWER_API AGameStatePlayer : public APlayerState, public IPlayerStateInterface
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Stats")
	FPlayerInformation CurrentStatus;


	virtual int32 GetCurrentColorIndex() const override;
	virtual void SetCurrentColorIndex(class IGameFieldElementInterface* Interface);
	virtual void ResetValues() override;
	virtual void AddToList(IGameFieldElementInterface* Element) override;
	virtual class IGameFieldElementInterface* PopList() override;
	virtual bool HasCurrentElementInterface() const override;
	virtual IGameFieldElementInterface* GetCurrentElementInterface() override;
	virtual bool IsElementValidNew(IGameFieldElementInterface* NewElement) const override;
	virtual bool IsElementPrevious(IGameFieldElementInterface* NewElement) const override;
	virtual bool MoveComplete() override;
	virtual TArray<class IGameFieldElementInterface*>& GetHeap() override;
};
