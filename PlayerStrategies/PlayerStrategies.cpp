#include "PlayerStrategies.h"

//focuses on building cities or destroying opponents
void GreedyComputerStrategy::playTurn(Hand *gameHand) {
	// check cards in hand
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	for (int i = 0; i < cardsInHand.size(); i++) {
		Card currentCard = *(cardsInHand.at(i));


		// holds cards that may be of interest
		vector<Card*> buildingCards;
		vector<Card*> destroyingCards;
		string andDelim = "AND";
		// parse actions to see if any of them are of interest
		if (currentCard.getAction() != "") {
			cout << currentCard.getAction() << endl;
			if (currentCard.getAction().find(delim1)) {// AND
				
			}
		}
	}

	//make decision based on cards in hand


}

// controls a region in which it just needs to occupy it with more armies than the opponent
void ModerateComputerStrategy::playTurn(Hand* gameHand) {
	// check cards in hand
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	for (int i = 0; i < cardsInHand.size();i++) {
		Card currentCard = *(cardsInHand.at(i));

		// read all cards and choose the ones that have to do with controlling a region
		// controlling a region = having more armies in a given region
		if (currentCard.getAction() != "") {
			cout << currentCard.getAction() << endl;
		}
	}

	//make decision based on cards in hand


}
