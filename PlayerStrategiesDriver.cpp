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
	gameInstance->getGameHand()->viewHand();
	for (int i = 0; i < 6; i++) {
		cout << "===================\n===================\nTurn #" << gameInstance->getTurnNumber() << endl;
		gameInstance->getCurrentPlayer()->executeStrategy(gameInstance->getGameHand(), gameInstance->getCurrentPlayer()->getBidingFacility(), gameInstance->getCurrentPlayer());
		gameInstance->getGameHand()->slideCardsLeft();
		gameInstance->getDeck()->fillHand(gameInstance->getGameHand());
		gameInstance->nextPlayer();
	}


	cout << "hello" << endl;
	string first;
	cin >> first;


	return 0;
}