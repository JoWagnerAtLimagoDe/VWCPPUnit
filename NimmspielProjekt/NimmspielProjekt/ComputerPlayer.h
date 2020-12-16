#pragma once
#include "TakeGamePlayer.h"
#include <iostream>

class ComputerPlayer :
    public TakeGamePlayer
{
    virtual std::string getName() const {
        return "ComputerPlayer";
    }
    virtual int doTurn(int stones) const {
        const int zuege[] = { 3,1,1,2 };
        return zuege[stones % 4];
        
    }
};

