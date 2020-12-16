#pragma once
#include "Game.h"
#include "TakeGamePlayer.h"
#include <iostream>
#include <string>
#include <vector>

class TakegameImpl :
    public Game
{
public:

    TakegameImpl() :stones(23) {}

    void play() {
        while (!isGameOver())   executeTurns();
    }

    void addPlayer(TakeGamePlayer *player) {
        players.push_back(player);
    }

private:
    int stones;
    int turn;
    std::vector<TakeGamePlayer*> players;

    bool isGameOver() {
        return stones < 1 || players.size() == 0;
    }
    void executeTurns()
    {
        for (TakeGamePlayer *player : players) {
            executeTurn(player);
        }
    }
    void executeTurn(TakeGamePlayer* player) {
        if (isGameOver()) return;

        doValidTurn(player);

        terminateTurn(player);
       
    }
    
    void terminateTurn(TakeGamePlayer* player) {
        calculateScene();
        checkLosing(player);
    }

    void doValidTurn(TakeGamePlayer* player)
    {
        while (turnIsInvalid(player)) {
            print("ungueltige Eingabe");
        }
    }
   

    bool turnIsInvalid(TakeGamePlayer*player) {
        turn = player->doTurn(stones);
        return ! isValid();
    }

    void checkLosing(TakeGamePlayer* player)
    {
        if (isGameOver()) print( player->getName() + " hat verloren");

    }

    void print(std::string message) {
        std::cout << message << std::endl;
    }



    bool isValid() {
        return turn >= 1 && turn <= 3;
    }
  
  

    void calculateScene()
    {
        stones -= turn;
    }

 

    
   
};

