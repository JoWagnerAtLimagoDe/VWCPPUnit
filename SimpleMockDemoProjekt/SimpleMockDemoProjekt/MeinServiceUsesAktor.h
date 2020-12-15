#pragma once

#include "Aktor.h"

class MeinServiceUsesAktor
{

private:
	Aktor& aktor;

public:
	MeinServiceUsesAktor(Aktor& aktor);

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
	void bar(int value);
	
};

