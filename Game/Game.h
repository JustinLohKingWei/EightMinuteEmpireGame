#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../Player/Player.h"
#include "../Card/Card.h"

class Game {
public:
	Game();
	Game(vector<Player*> players);
	void nextPlayer();
	Player* getCurrentPlayer();
	int getNumOfPlayers();
	Hand* getGameHand();
	void setGameHand(Hand* aHand);
	


private:
	vector<Player*> listOfPlayers;
	int currentPlayer;
	int numOfPlayers;
	int turnNumber;
	Hand* theGameHand;
};