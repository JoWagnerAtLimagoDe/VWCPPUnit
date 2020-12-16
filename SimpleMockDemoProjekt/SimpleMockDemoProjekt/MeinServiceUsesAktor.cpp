#include "pch.h"
#include "MeinServiceUsesAktor.h"

MeinServiceUsesAktor::MeinServiceUsesAktor(Aktor& aktor, Sensor & sensor):aktor(aktor),sensor(sensor)
{
}

void MeinServiceUsesAktor::foo(int value)
{
	aktor.doIt(ParameterStruct{ value + 1, value + 2, value + 3 });
	
}

//erzeugt ParameterObject und setzt für x = value + 3, y = value + 2; z = value + 1; ruft doIt mit diesen Params auf
void MeinServiceUsesAktor::bar()
{
	const int value = sensor.getValue();
	aktor.doIt(ParameterStruct{ value + 3, value + 2, value + 1 });
}
