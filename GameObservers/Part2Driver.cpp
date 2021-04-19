#include "../Player/Player.h"
#include "../Card/Card.h"
#include "../PlayerStrategies/PlayerStrategies.h"
#include "../BidingFacility/Bid.h"
#include "../Game/Game.h"
#include "GameMessageBoard.h"
#include <iostream>
using std::cout;
using std::endl;


int main() {
	cout << "Testing Part 2 Observer" << endl;

	Game* gameInstance = new Game();
	gameInstance->initializePlayers();
	gameInstance->initializeDeck();
	gameInstance->initializeHand();
	gameInstance->getGameHand()->viewHand();
	for (int i = 0; i < 6; i++) {
		cout << "===================\n===================\nTurn #" << gameInstance->getTurnNumber() << endl;
		gameInstance->getCurrentPlayer()->executeStrategy(gameInstance->getGameHand(), gameInstance->getCurrentPlayer()->getBidingFacility(), gameInstance->getCurrentPlayer());
		gameInstance->getGameHand()->slideCardsLeft();
		gameInstance->getDeck()->fillHand(gameInstance->getGameHand());
		gameInstance->nextPlayer();
	}
	
	return 0;
}