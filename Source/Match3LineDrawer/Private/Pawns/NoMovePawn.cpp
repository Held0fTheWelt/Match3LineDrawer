// @Yves Tanas 2020


#include "NoMovePawn.h"

#include "Camera/CameraComponent.h"

// Sets default values
ANoMovePawn::ANoMovePawn()
{
 	if(Camera == nullptr)
		Camera = CreateDefaultSubobject<UCameraComponent>(FName("Camera"));

	RootComponent = Camera;

}

// Called when the game starts or when spawned
void ANoMovePawn::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ANoMovePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

}

