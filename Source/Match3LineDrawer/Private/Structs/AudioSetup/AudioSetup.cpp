// @Yves Tanas 2020

#include "Structs/AudioSetup/AudioSetup.h"

#include "Sound/SoundBase.h"
#include "UObject/ConstructorHelpers.h"

FAudioSetup::FAudioSetup()
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<USoundBase> Hover;
		ConstructorHelpers::FObjectFinderOptional<USoundBase> Click;
		ConstructorHelpers::FObjectFinderOptional<USoundBase> Fail;
		ConstructorHelpers::FObjectFinderOptional<USoundBase> ThreeLine;
		ConstructorHelpers::FObjectFinderOptional<USoundBase> SixLine;
		ConstructorHelpers::FObjectFinderOptional<USoundBase> EightLine;
		ConstructorHelpers::FObjectFinderOptional<USoundBase> TenLine;
		FConstructorStatics()
			: Hover(TEXT("/Game/Sounds/Hover.Hover"))
			, Click(TEXT("/Game/Sounds/Counted.Counted"))
			, Fail(TEXT("/Game/Sounds/Error.Error"))
			, ThreeLine(TEXT("/Game/Sounds/ThreeLine.ThreeLine"))
			, SixLine(TEXT("/Game/Sounds/SixLine.SixLine"))
			, EightLine(TEXT("/Game/Sounds/EightLine.EightLine"))
			, TenLine(TEXT("/Game/Sounds/TenLine.TenLine"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	HoverSound = ConstructorStatics.Hover.Get();
	ClickedSound = ConstructorStatics.Click.Get();
	FailureSound = ConstructorStatics.Fail.Get();
	ThreeLine = ConstructorStatics.ThreeLine.Get();
	SixLine = ConstructorStatics.SixLine.Get();
	EightLine = ConstructorStatics.EightLine.Get();
	TenLine = ConstructorStatics.TenLine.Get();
}
