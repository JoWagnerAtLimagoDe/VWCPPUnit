#pragma once
#include <string>
#include <typeinfo>

class TakeGamePlayer
{


public:
	virtual std::string getName() const = 0;
	virtual int doTurn(int stones) const = 0;
};

