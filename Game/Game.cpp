#include "Game.h"

Game::Game() {
	cout << "Default game created" << endl;
	currentPlayer = 0;
	numOfPlayers = 0;
	turnNumber = 0;
	listOfPlayers;
}

Game::Game(vector<Player*> players) : listOfPlayers(players) {
	cout << "Game with " << listOfPlayers.size() <<" players created" << endl;
	currentPlayer = 0;
	numOfPlayers = listOfPlayers.size();
	turnNumber = 1;
}

void Game::nextPlayer() {
	int currentPlayer = (++turnNumber + (numOfPlayers-1)) % numOfPlayers;
	cout << "Play has been passed to player #" << currentPlayer+1 <<
		": " << listOfPlayers.at(currentPlayer)->getFirstName() << " "
		<< listOfPlayers.at(currentPlayer)->getLastName()<< endl;
}