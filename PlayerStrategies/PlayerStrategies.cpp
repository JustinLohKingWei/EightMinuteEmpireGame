#include "PlayerStrategies.h"

//focuses on building cities or destroying opponents
void GreedyComputerStrategy::playTurn() {
	// check cards in hand

	// make decision based on cards in hand

	// perform the action
}

void ModerateComputerStrategy::playTurn(Hand* gameHand) {
	// check cards in hand
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	for (int i = 0; i < cardsInHand.size();i++) {
		Card currentCard = *(cardsInHand.at(i));
		if (currentCard.getAction() != "") {
			cout << currentCard.getAction() << endl;
		}
	}

	//make decision based on cards in hand


}
