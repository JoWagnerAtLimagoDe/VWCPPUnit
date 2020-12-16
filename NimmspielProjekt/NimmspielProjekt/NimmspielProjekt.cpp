// NimmspielProjekt.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "takegame_impl.h"
#include "GameClient.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
int main()
{
    HumanPlayer human;
    ComputerPlayer computer;
    TakegameImpl game;
    game.addPlayer(&human);
    game.addPlayer(&computer);
    GameClient client(game);
    client.run();

}

