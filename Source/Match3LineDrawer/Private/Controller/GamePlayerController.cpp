// @Yves Tanas 2020

#include "GamePlayerController.h"
#include "Engine/World.h"

AGamePlayerController::AGamePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AGamePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	
}

void AGamePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	//Super::SetupInputComponent();
}
