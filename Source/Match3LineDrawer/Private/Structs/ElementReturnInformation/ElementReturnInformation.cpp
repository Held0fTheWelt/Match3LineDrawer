// @Yves Tanas 2020


#include "Structs/ElementReturnInformation/ElementReturnInformation.h"

FElementReturnInformation::FElementReturnInformation()
{
	ColorIndex = 0;
	Material = nullptr;
}

FElementReturnInformation::FElementReturnInformation(int32 Index, UMaterialInterface* Interface)
{
	ColorIndex = Index;
	Material = Interface;
}