#pragma once

struct ParameterStruct
{
	int x;
	int y;
	int z;
};

// Dependency
class Aktor
{
public:
	virtual void doIt(ParameterStruct p)=0;
};

