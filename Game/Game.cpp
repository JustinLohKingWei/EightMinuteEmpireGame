#include "Game.h";

Game::Game() {
	cout << "Default game created" << endl;
}

Game::Game(vector<Player*> players) {
	cout << "Game with " << players.size <<" players created" << endl;
	listOfPlayers = players;
}

Game::nextPlayer() {
	cout << "Play has been passed to the next player" << endl;
}