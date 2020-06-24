// @Yves Tanas 2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NoMovePawn.generated.h"

UCLASS()
class MATCH3LINEDRAWER_API ANoMovePawn : public APawn
{
	GENERATED_BODY()

public:
	ANoMovePawn();

protected:
	UPROPERTY(VisibleAnywhere, Category = Components)
	class UCameraComponent* Camera;

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
