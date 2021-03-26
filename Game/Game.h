#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Game {
public:
	Game();
	Game(vector<Player*> players);
	void nextPlayer();

private:
	vector<Player*> listOfPlayers;
	int currentPlayer;
};