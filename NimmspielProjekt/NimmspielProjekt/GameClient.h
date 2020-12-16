#pragma once
#include "Game.h"
class GameClient
{
private:
	Game& game;

public:
	GameClient(Game& game) :game(game) {}
	void run() {
		game.play();
	}
};

