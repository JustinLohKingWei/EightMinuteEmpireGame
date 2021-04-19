#include "PlayerStrategies.h"
#include <stdlib.h>
/*
	Steps in making a decision
	1. Check cards in hand (looking for building or destroying)
	2. If opportunity to destroy -> pick up card
	3. If no opportunity to destroy, but opportunity to build -> pick up build card
	4. If no such cards / opportunities, random pick card that player can afford
*/
void GreedyComputerStrategy::playTurn(Hand *gameHand, Bid* biddingFacility) {
	// check cards in hand
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	int currentCoins = biddingFacility->getCopperCoins();
	vector<int> buildingCards;
	vector<int> destroyingCards;
	vector<int> otherCards;
	string andDelim = " AND ";
	string orDelim = " OR ";
	string buildDelim = "Build City";
	string destroyDelim = "Destroy Army";
	for (int i = 0; i < cardsInHand.size(); i++) {
		Card currentCard = *(cardsInHand.at(i));

		if (gameHand->getCost(i) > currentCoins) {
			continue;
		}

		// holds cards that may be of interest
		
		// parse actions to see if any of them are of interest 
		if (currentCard.getAction().size() > 0) {
			
				
				string fullAction = currentCard.getAction();
				if (fullAction.find(buildDelim) != string::npos) {
					buildingCards.push_back(i);
				}
				if (fullAction.find(destroyDelim) != string::npos) {
					destroyingCards.push_back(i);
				}
				if (fullAction.find(buildDelim) == string::npos && fullAction.find(destroyDelim) == string::npos) {
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
	for (int index : buildingCards) {
		cout << "Building card: " << index << endl;
	}
	for (int index : destroyingCards) {
		cout << "Destroy card: " << index << endl;
	}
	for (int index : otherCards) {
		cout << "Other card: " << index << endl;
	}
	int numOfRandom = otherCards.size();
	int randomIndex = rand() % numOfRandom;
	cout << numOfRandom << endl;
	//make decision based on cards in hand (all affordable cards)
	//1. If you have destroying cards, check if you can destroy
	//2. If you have building cards, build a city
	//3. If you have none of the above, RNG an "other" card
	
	// check if armies to destroy
	if (destroyingCards.size() > 0) {
		// if destroyarmy works, continue
		
		// if none, move to next decision
	} 
	if (buildingCards.size() > 0) {
		// build city
	}
	// play a random card
	else {
		int numOfRandom = otherCards.size();
		int randomIndex = rand() % numOfRandom;
		// choose vector at to play card

	}

}

// controls a region in which it just needs to occupy it with more armies than the opponent
/*
1. Check card in hand
2. Check place new armies->place in region with ennemy(make sure it has more than the ennemy)->if no ennemies place armies in empty region(i.e. region with 0 armies)->else place in region with most armies
3. Move armies to region->if adj region has ennemy (move there)->else move anywhere
4. Choose randomly otherwise
*/
void ModerateComputerStrategy::playTurn(Hand* gameHand, Bid* biddingFacility) {
	// check cards in hand
	vector<int>placingArmiesCards;//interest cards 
	vector<int>movingArmiesCards;
	vector<int>otherCards;
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	int currentCoins = biddingFacility->getCopperCoins();


	cout << "SELECTING CARDS OF INTEREST\n" << endl;
	for (int i = 0; i < cardsInHand.size();i++) {

		if (gameHand->getCost(i) > currentCoins) {
			continue;
		}

		Card currentCard = *(cardsInHand.at(i));

		// read all cards and choose the ones that have to do with controlling a region
		// controlling a region = having more armies in a given region

		if (currentCard.getAction().find_first_of("Place Army")){
			cout << "Card with action of primary interest: "<< currentCard.getAction() << endl;
			placingArmiesCards.push_back(i);
		}
		else if (currentCard.getAction().find_first_of("Move Armies")) {
			cout << "Card with action of secondary interest: " << currentCard.getAction() << endl;
			movingArmiesCards.push_back(i);
		}
		else {
			cout << "Adding misc cards" << endl;
			otherCards.push_back(i);
		}

	}
	if (placingArmiesCards.size() == 0) {
		if (movingArmiesCards.size() == 0) {
			//Generate index of misc card
			int randomOtherCardIndex = rand() % otherCards.size();
			int amount = 0;
			Card* current = cardsInHand.at(otherCards.at(randomOtherCardIndex));
			//Process actions
			string action = current->getAction();

			if (action.find("AND") || action.find("OR")) {
				Player::listOfPlayers.at(2)->andOr(current); //TO BE OVERLOADED
			}
			else if (action.find("Build City")) {
				amount = std::stoi(action.substr(action.find(":") + 1));
				Player::listOfPlayers.at(2)->BuildCity(amount);
			}
			else if (action.find("Destroy Army")) {
				amount = std::stoi(action.substr(action.find(":") + 1));
				Player::listOfPlayers.at(2)->DestroyArmy(amount);
			}
		}
		else {
			
			int randomMovingCardIndex = rand() % movingArmiesCards.size();
			int amount = 0;
			Card* current = cardsInHand.at(movingArmiesCards.at(randomMovingCardIndex));

			string action = current->getAction();

			if (action.find("AND") || action.find("OR")) {
				Player::listOfPlayers.at(2)->andOr(current);
			}
			else {
				amount = std::stoi(action.substr(action.find(":") + 1));
				Player::listOfPlayers.at(2)->MoveArmies(amount);
			}	
		}
	
	}
	else {
		int randomPlacingCardIndex = rand() % placingArmiesCards.size();
		int amount = 0;
		Card* current = cardsInHand.at(movingArmiesCards.at(randomPlacingCardIndex));

		string action = current->getAction();
		if (action.find("AND") || action.find("OR")) {
			Player::listOfPlayers.at(2)->andOr(current);
		}
		else {
			amount = std::stoi(action.substr(action.find(":") + 1));
			Player::listOfPlayers.at(2)->PlaceNewArmies(amount);
		}
	}
	//make decision based on cards in hand


}
 void HumanStrategy::playTurn(Hand * gameHand, Bid* bid) {
	int affIndex = 0;
	int currentCoins = bid->getCopperCoins();
	int amount = 0;
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	cout << "Selecting a card from hand..." << endl;
	vector<int> affordableCards;
	
	//check if can afford card
	for (Card* x : cardsInHand) {
		if (gameHand->getCost(affIndex) > currentCoins) {
			affIndex++;
			continue;
		}
		affordableCards.push_back(affIndex);
		affIndex++;
	}

	cout << "Human choose a card to play..." << endl;

	for (int x : affordableCards) {
		cout << "(" << x << ")" << cardsInHand.at(x)->getAction() << " with cost " << gameHand->getCost(x) << endl;
	}
	int indexChoice;
	cin >> indexChoice;

	Card* current = cardsInHand.at(affordableCards.at(indexChoice));
	string action = current->getAction();

	if (action.find("AND") || action.find("OR")) {
		Player::listOfPlayers.at(0)->andOr(current);
	}
	else {
		amount = std::stoi(action.substr(action.find(":") + 1));
		if (action == "Place Army") {
			Player::listOfPlayers.at(0)->PlaceNewArmies(amount);
		}
		else if (action == "Move Armies") {
			Player::listOfPlayers.at(0)->MoveArmies(amount);
		}
		else if (action == "Build City") {
			Player::listOfPlayers.at(0)->BuildCity(amount);
		}
		else if (action == "Destroy Army") {
			Player::listOfPlayers.at(0)->DestroyArmy(amount);
		}
	}

	//pay card cost
	Player::listOfPlayers.at(0)->PayCoin(gameHand->getCost(indexChoice), 'c');
}
 //TODO
/*
* Add isTurn bool to player (DONE)
* Verify card cost payment (DONE)
* Reimplement methods based on strat 
* Check strat type
* Test strat
* Part 4
*/