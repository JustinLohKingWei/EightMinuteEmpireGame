#include "Player/Player.h"
#include "Card/Card.h"
#include "PlayerStrategies/PlayerStrategies.h"
#include "BidingFacility/Bid.h"
#include "Game/Game.h"
int main() {
    Game* gameInstance = new Game();
    gameInstance->initializePlayers();
    gameInstance->biddingPhase();
    gameInstance->initializeDeck();
    gameInstance->initializeHand();
    string fName;
    string lName;
    string first, last;
    gameInstance->getGameHand()->viewHand();

    cout << "Please enter first name" << endl;
    cin >> first;
    cout << "Please enter last name" << endl;
    cin >> last;
    fName = string(first);
    lName = string(last);
    vector<Card*>cards;
    vector<Region*>listOfRegions;
    vector<Army*>listOfArmies(18, new Army);
    vector<City*>listOfCities(3, new City);

    Strategy* greedyStrat = new GreedyComputerStrategy();
	Player* player1 = new Player(fName, lName, cards, listOfRegions, listOfArmies, 
        listOfCities, greedyStrat);//Creating player
    Strategy* greedyStrat2 = new GreedyComputerStrategy();
    Player* player2 = new Player(fName, lName, cards, listOfRegions, listOfArmies,
        listOfCities, greedyStrat2);//Creating player
    (*(*player1).getBidingFacility()).pickUpCoins();
	(*player1).executeStrategy(gameInstance->getGameHand(), player1->getBidingFacility());
    cout << "hello" << endl;
    cin >> first;


	return 0;
}