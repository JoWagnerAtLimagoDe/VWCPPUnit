#pragma once
#include "TakeGamePlayer.h"
#include <iostream>

class HumanPlayer :
    public TakeGamePlayer
{
public:
    virtual std::string getName() const {
        return "HumanPlayer";
    }
    virtual int doTurn(int stones) const {
        int turn;
        std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1,2 oder 3." << std::endl;
        std::cin >> turn;
        return turn;
    }
};

