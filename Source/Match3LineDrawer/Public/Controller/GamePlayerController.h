// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/Controller/PlayerControllerInterface.h"
#include "GamePlayerController.generated.h"

UCLASS()
class AGamePlayerController : public APlayerController, public IPlayerControllerInterface
{
	GENERATED_BODY()

public:
	AGamePlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	UFUNCTION()
	void MousePressed();
	UFUNCTION()
	void MouseReleased();

	UPROPERTY(VisibleAnywhere, Category = "Mouse")
	bool bMouseIsPressed;

	virtual const bool GetMouseIsPressed() const override;

	virtual void ResetPlayerControllerValues() override;

private:
	class IPlayerStateInterface* StateInterface;

private:
	void SolveConditionMatched();
};
