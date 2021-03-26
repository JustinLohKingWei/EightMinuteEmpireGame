#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../Player/Player.h"

class Game {
public:
	Game();
	Game(vector<Player*> players);
	void nextPlayer();
	Player* getCurrentPlayer();

private:
	vector<Player*> listOfPlayers;
	int currentPlayer;
	int numOfPlayers;
	int turnNumber;
};