// @Yves Tanas 2020

#include "GamePlayerController.h"

#include "Com/Communicator.h"
#include "Engine/World.h"
#include "GameFramework/PlayerState.h"
#include "Interfaces/States/PlayerStateInterface.h"

AGamePlayerController::AGamePlayerController()
{
	bShowMouseCursor = true;

	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bMouseIsPressed = false;
}

void AGamePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
		
}

void AGamePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AGamePlayerController::MousePressed);
	InputComponent->BindAction("MouseClick", IE_Released, this, &AGamePlayerController::MouseReleased);

}

void AGamePlayerController::MousePressed()
{
	bMouseIsPressed = true;

	Communicator::CountCurrentHighlight(GetWorld());
}

void AGamePlayerController::MouseReleased()
{
	bMouseIsPressed = false;

	Communicator::ResetAllElements(GetWorld());

	
}

const bool AGamePlayerController::GetMouseIsPressed() const
{
	return bMouseIsPressed;
}

void AGamePlayerController::ResetPlayerControllerValues()
{
	bMouseIsPressed = false;
}
