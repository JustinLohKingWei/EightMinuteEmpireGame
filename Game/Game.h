#pragma once
#include <iostream>
#include <vector>
#include "../Player/Player.h"
#include "../Card/Card.h"
#include "../Map/Map.h"
using namespace std;
class Player;
class WorldMap;

class Game {
public:
	Game();
	Game(vector<Player*> players);
	void nextPlayer();
	Player* getCurrentPlayer();
	int getNumOfPlayers();
	Hand* getGameHand();
	Deck* getDeck();
	//WorldMap* getMap();
	void setGameHand(Hand* aHand);
	bool getGameOver();
	void setGameOver(bool value);
	int getTurnNumber();
	void initializeDeck();
	void initializeHand();
	void initializeMap();
	void biddingPhase();
	void initializePlayers();


private:
	vector<Player*> listOfPlayers;
	int currentPlayer;
	int numOfPlayers;
	int turnNumber;
	Hand* theGameHand;
	Deck* gameDeck;
	WorldMap* map;
	bool gameOver;
};