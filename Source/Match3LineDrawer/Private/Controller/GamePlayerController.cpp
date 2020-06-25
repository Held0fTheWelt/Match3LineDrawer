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
		
	APlayerState* State = GetPlayerState<APlayerState>();

	if (State == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerState was null in PlayerController. This shouldn't happen !"));
	}

	StateInterface = Cast<IPlayerStateInterface>(State);

	if (StateInterface == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not cast PlayerState to PlayerStateInterface. This shouldn't happen !"));
	}
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
	if (StateInterface == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerStateInterface was null!"));		
	}
	else
	{
		if (StateInterface->MoveComplete())
		{
			SolveConditionMatched();
		}
		else
		{
			Communicator::ResetAllElements(GetWorld());
		}
	}

	bMouseIsPressed = false;	
}

const bool AGamePlayerController::GetMouseIsPressed() const
{
	return bMouseIsPressed;
}

void AGamePlayerController::ResetPlayerControllerValues()
{
	bMouseIsPressed = false;
}

void AGamePlayerController::SolveConditionMatched()
{
	Communicator::ClearHeap(GetWorld(), StateInterface->GetHeap());

	Communicator::ResetAllElements(GetWorld());
}
