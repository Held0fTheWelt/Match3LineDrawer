// @Yves Tanas 2020


#include "Structs/ElementInformation/ElementInformation.h"

FElementInformation::FElementInformation()
{
	ColorNumber = -1;
	Row = -1;
	Column = -1;
}

void FElementInformation::SetColorNumber(int32 NewColorNumber)
{
	ColorNumber = NewColorNumber;
}