#pragma once

#include "Aktor.h"
#include "Sensor.h"
class MeinServiceUsesAktor
{

private:
	Aktor& aktor;
	Sensor& sensor;
public:
	MeinServiceUsesAktor(Aktor& aktor, Sensor &sensor);

	/*
	 *	erzeugt ParameterObject und setzt für x = value + 1, y = value + 2; z = value + 3; ruft doIt mit diesen Params auf
	 *
	 * 
	 */
	void foo(int value);
	/*
	 *	erzeugt ParameterObject und setzt für x = value + 3, y = value + 2; z = value + 1; ruft doIt mit diesen Params auf
	 *
	 *
	 */
	void bar();
	
};

