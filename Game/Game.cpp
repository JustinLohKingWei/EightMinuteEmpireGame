#include "Game.h"

Game::Game() : theGameHand(), listOfPlayers() {
	cout << "Default game created" << endl;
	currentPlayer = 0;
	numOfPlayers = 0;
	turnNumber = 0;
}

Game::Game(vector<Player*> players) : listOfPlayers(players), theGameHand(){
	cout << "Game with " << listOfPlayers.size() <<" players created" << endl;
	currentPlayer = 0;
	numOfPlayers = listOfPlayers.size();
	turnNumber = 1;
}

Player* Game::getCurrentPlayer() {
	return listOfPlayers.at(currentPlayer);
}

void Game::nextPlayer() {
	int currentPlayer = (++turnNumber + (numOfPlayers-1)) % numOfPlayers;
	cout << "Play has been passed to player #" << currentPlayer+1 <<
		": " << listOfPlayers.at(currentPlayer)->getFirstName() << " "
		<< listOfPlayers.at(currentPlayer)->getLastName()<< endl;
}

int Game::getNumOfPlayers() {
	return numOfPlayers;
}

Hand* Game::getGameHand() {
	return theGameHand;
}

void Game::setGameHand(Hand* aHand) {
	theGameHand = aHand;
}