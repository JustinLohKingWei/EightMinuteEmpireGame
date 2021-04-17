#include "PlayerStrategies.h"

/*
	Steps in making a decision
	1. Check cards in hand (looking for building or destroying)
	2. If opportunity to destroy -> pick up card
	3. If no opportunity to destroy, but opportunity to build -> pick up build card
	4. If no such cards / opportunities, random pick card that player can afford
*/
void GreedyComputerStrategy::playTurn(Hand *gameHand) {
	// check cards in hand
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	for (int i = 0; i < cardsInHand.size(); i++) {
		Card currentCard = *(cardsInHand.at(i));


		// holds cards that may be of interest
		vector<int> buildingCards;
		vector<int> destroyingCards;
		vector<int> otherCards;
		string andDelim = " AND ";
		string orDelim = " OR ";
		string buildDelim = "Build City";
		string destroyDelim = "Destroy Army";
		// parse actions to see if any of them are of interest
		if (currentCard.getAction().size() > 0) {
			string fullAction = currentCard.getAction();
			if (fullAction.find(buildDelim)) {
				buildingCards.push_back(i);
			}
			else if (fullAction.find(destroyDelim)) {
				destroyingCards.push_back(i);
			}
			else {
				otherCards.push_back(i);
			}
			//if (fullAction.find(andDelim)!=string::npos) {// 2 actions (AND)
			//	// Action before AND
			//	string action1 = fullAction.substr(0, fullAction.find(andDelim));
			//	// Action after AND
			//	string action2 = fullAction.substr(action1.size() + string(" AND ").size());
			//}
			//else if (fullAction.find(orDelim)!=string::npos) { // 2 actions (OR)
			//	// Action before OR
			//	string action1 = fullAction.substr(0, fullAction.find(orDelim));
			//	// Action after OR
			//	string action2 = fullAction.substr(action1.size() + string(" OR ").size());
			//}
			//else { // card only has 1 action
			//}
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
