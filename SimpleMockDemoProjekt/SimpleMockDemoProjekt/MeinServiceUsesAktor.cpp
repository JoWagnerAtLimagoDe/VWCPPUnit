#include "pch.h"
#include "MeinServiceUsesAktor.h"

MeinServiceUsesAktor::MeinServiceUsesAktor(Aktor& aktor):aktor(aktor)
{
}

void MeinServiceUsesAktor::foo(int value)
{
	aktor.doIt(ParameterStruct{ value + 1, value + 2, value + 3 });
	
}
void MeinServiceUsesAktor::bar(int value)
{
	
}
