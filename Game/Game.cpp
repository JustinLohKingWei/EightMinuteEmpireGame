#include "Game.h"

Game::Game() : theGameHand(new Hand()), listOfPlayers(), gameDeck(new Deck()) {
	cout << "Default game created" << endl;
	currentPlayer = 0;
	numOfPlayers = 2;
	turnNumber = 0;
	gameOver = false;
}

Game::Game(vector<Player*> players) : listOfPlayers(players), theGameHand(new Hand()), gameDeck(new Deck()){
	cout << "Game with " << listOfPlayers.size() <<" players created" << endl;
	currentPlayer = 0;
	numOfPlayers = listOfPlayers.size();
	turnNumber = 1;
	gameOver = false;
}

Player* Game::getCurrentPlayer() {
	return listOfPlayers.at(currentPlayer);
}



void Game::nextPlayer() {
	currentPlayer = (++turnNumber + (numOfPlayers-1)) % numOfPlayers;
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

Deck* Game::getDeck() {
	return gameDeck;
}

void Game::setGameHand(Hand* aHand) {
	theGameHand = aHand;
}


bool Game::getGameOver() {
	return gameOver;
}

void Game::setGameOver(bool value) {
	gameOver = value;
}

int Game::getTurnNumber() {
	return turnNumber;
}

void Game::initializeDeck()
{
	gameDeck = new Deck();
	gameDeck->filterDeck(numOfPlayers);
	gameDeck->shuffleDeck();
}

void Game::initializeHand() {
	gameDeck->fillHand(theGameHand);
}

void Game::biddingPhase() {

	for (int i = 0; i < numOfPlayers; i++) {
		(*(*listOfPlayers.at(i)).getBidingFacility()).pickUpCoins();
	}

	for (int i = 0; i < numOfPlayers; i++) {
		(*(*listOfPlayers.at(i)).getBidingFacility()).bidCoins();
	}

	int winnerAmount = 0;
	Player winner;
	// finds winner with largest alphabetical last name
    for (int i = 0; i < listOfPlayers.size(); i++) {
        (*(*listOfPlayers.at(i)).getBidingFacility()).displayBid();
        if (winnerAmount < (*(*listOfPlayers.at(i)).getBidingFacility()).getBidAmount()) {
			currentPlayer = i;
            winner = *listOfPlayers.at(i);
            winnerAmount = (*(*listOfPlayers.at(i)).getBidingFacility()).getBidAmount();
        }

        if (winnerAmount == (*(*listOfPlayers.at(i)).getBidingFacility()).getBidAmount()) {
            string a = winner.getLastName();
            string b = (*listOfPlayers.at(i)).getLastName();
            if (a > b) {
				currentPlayer = i;
                winner = *listOfPlayers.at(i);
            }
        }
    }

	cout << "Winning player: " << listOfPlayers.at(currentPlayer)->getFirstName() << endl;



}

void Game::initializePlayers() {
	for (int i = 0; i < numOfPlayers; i++) {
		string first, last, fName, lName;
		cout << "Please enter first name" << endl;
		cin >> first;
		cout << "Please enter last name" << endl;
		cin >> last;
		fName = string(first);
		lName = string(last);
		fName = string(first);
		lName = string(last);
		vector<Card*>cards;
    vector<Region*>listOfRegions;
    vector<Army*>listOfArmies(18, new Army);
    vector<City*>listOfCities(3, new City);
		Player* aPlayer = new Player(fName, lName, cards, listOfRegions, listOfArmies, listOfCities, new GreedyComputerStrategy());//Creating player
		listOfPlayers.push_back(aPlayer);
	}
}