// @Yves Tanas 2020


#include "GameFieldActor.h"

#include "Components/GameFieldElement/GameFieldElement.h"
#include "Components/SceneComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Math/UnrealMathUtility.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AGameFieldActor::AGameFieldActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	SizeX = 7;
	SizeY = 6;

	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInterface> MaterialInstance;
		FConstructorStatics()
			: PlaneMesh(TEXT("/Game/Meshes/HexMesh.HexMesh"))
			, MaterialInstance(TEXT("/Game/Materials/FieldMaterial_Inst.FieldMaterial_Inst"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	UStaticMesh* GameFieldMesh = ConstructorStatics.PlaneMesh.Get();

	GameFieldElements = TArray<UGameFieldElement*>();

	if (RootComponent == nullptr)
		RootComponent = CreateDefaultSubobject<USceneComponent>(FName("RootComponent"));

	if (GameFieldMesh != nullptr)
	{
		for (int8 i = 0; i < SizeX; i++)
		{
			for (int8 j = 0; j < SizeY; j++)
			{
				const FString ElementName = "GameField" + FString::FromInt(i) + FString::FromInt(j);

				// create the static mesh component
				UGameFieldElement* Element = CreateDefaultSubobject<UGameFieldElement>(FName(*ElementName));
				Element->SetupAttachment(RootComponent);

				// keep our own reference to the mesh
				GameFieldElements.Add(Element);

				// now you can do whatever setup you need to do				
				Element->SetRelativeLocation(CalculateElementPosition(i, j));
				Element->SetStaticMesh(GameFieldMesh);
			}
		}
	}

	Material = ConstructorStatics.MaterialInstance.Get();
}

void AGameFieldActor::BeginPlay()
{
	Super::BeginPlay();
	
}

const FVector AGameFieldActor::CalculateElementPosition(int8 i, int8 j)
{
	return FVector(i * 15,0,j * 17.5f + (i % 2 == 0 ? 0 : 8.75f));
}

void AGameFieldActor::SetColourSet(FColorDefinition& ColorDefinition)
{
	if (Material == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not change Material, because MaterialInstance was null"));
		return;
	}

	TArray<UMaterialInterface*> ColorMaterials;
	
	for (auto Color : ColorDefinition.Colors)
	{
		UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(Material, this);
		//set paramater with Set***ParamaterValue
		DynMaterial->SetVectorParameterValue("Color", FLinearColor(Color));

		ColorMaterials.Add(DynMaterial);
	}

	if (ColorMaterials.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not change Material, because Dynamic MaterialInstances Array was null"));
		return;
	}

	for (auto Element : GameFieldElements)
	{
		Element->SetNewMaterialInstance(ColorMaterials[FMath::RandRange(0, ColorMaterials.Num()-1)]);
	}
}

TArray<class IGameFieldElementInterface*> AGameFieldActor::GetGameFieldElements()
{
	TArray<class IGameFieldElementInterface*> Interfaces;

	for (auto Element : GameFieldElements)
	{
		Interfaces.Add(Element);
	}

	return Interfaces;
}

