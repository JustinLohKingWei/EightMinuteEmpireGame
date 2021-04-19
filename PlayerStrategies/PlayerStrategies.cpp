#include "PlayerStrategies.h"

#include <stdlib.h>
/*
	Steps in making a decision
	1. Check cards in hand (looking for building or destroying)
	2. If opportunity to destroy -> pick up card
	3. If no opportunity to destroy, but opportunity to build -> pick up build card
	4. If no such cards / opportunities, random pick card that player can afford
*/
void GreedyComputerStrategy::playTurn(Hand* gameHand, Bid* biddingFacility, Player* currentPlayer) {
	// check cards in hand
	cout << currentPlayer->getFirstName() << " is playing." << endl;
	vector<Card*> cardsInHand = (*gameHand).getCardsInHand();
	int currentCoins = biddingFacility->getCopperCoins();
	vector<int> buildingCards;
	vector<int> destroyingCards;
	vector<int> placeArmyCards;
	vector<int> moveArmyCards;
	vector<int> otherCards;
	vector<int> andCards;
	vector<int> orCards;
	string andDelim = " AND ";
	string orDelim = " OR ";
	string buildDelim = "Build City";
	string destroyDelim = "Destroy Army";
	string placeDelim = "Place Armies";
	string moveDelim = "Move Armies";

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
			if (fullAction.find(placeDelim) != string::npos) {
				placeArmyCards.push_back(i);
			}
			if (fullAction.find(moveDelim) != string::npos) {
				moveArmyCards.push_back(i);
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


	//make decision based on cards in hand (all affordable cards)
	//1. If you have destroying cards, check if you can destroy
	//2. If you have building cards, build a city
	//3. If you have none of the above, RNG an "other" card

	// check if armies to destroy
	if (destroyingCards.size() > 0) {
		/*
			1. To destroy an army, algorith must check if there's an opportunity to
			destroy one (e.g. have options returned to it).
			2. If there is, algorithm must decide which one to destroy
		*/
		vector<Army*> targetableArmies = currentPlayer->canDestroyArmy();
		// if there is an enemy to target
		if (targetableArmies.size() > 0) {
			// exchange a card
			int numOfDestroy = destroyingCards.size();
			int indexToPlay = destroyingCards.at(rand() % numOfDestroy);
			Card* chosenCard = gameHand->getCard(indexToPlay);
			currentPlayer->PayCoin(gameHand->getCost(indexToPlay), 'c');
			gameHand->exchange(indexToPlay);

			int possibleTargets = targetableArmies.size();
			int targetIndex = rand() % possibleTargets;
			Army* targetedArmy = targetableArmies.at(targetIndex);
			currentPlayer->destroyArmy(targetedArmy);
			return;
		}

		// if no targetable army, moves on to next priority

	}
	if (buildingCards.size() > 0) {
		// build city
		vector<Region*> possibleBuildRegions = currentPlayer->canBuildCity();
		if (possibleBuildRegions.size() > 0) {
			int numOfBuild = buildingCards.size();
			int indexToPlay = buildingCards.at(rand() % numOfBuild);
			Card* chosenCard = gameHand->getCard(indexToPlay);
			gameHand->exchange(indexToPlay);

			int numOfPossibleRegions = possibleBuildRegions.size();
			int targetIndex = rand() % numOfPossibleRegions;
			Region* regionToBuildCity = possibleBuildRegions.at(targetIndex);
			currentPlayer->buildCity(regionToBuildCity);
			return;
		}
	}
	if (placeArmyCards.size() > 0) {
		// choose a card first (need the value of the place army action)
		int numOfPlaceArmy = placeArmyCards.size();
		int indexToPlay = placeArmyCards.at(rand() % numOfPlaceArmy);
		Card* chosenCard = gameHand->getCard(indexToPlay);

		string action = chosenCard->getAction();
		action = action.substr(action.find("Place Armies: "));
		string numOfArmies = action.substr(string("Place Armies: ").size(), string("Place Armies: ").size() + 1);
		int actionValue = std::stoi(numOfArmies);
		vector<City*> listOfCities = currentPlayer->getListOfCities();
		for (int i = 0; i < actionValue; i++) {
			for (City* aCity : listOfCities) {
				if (aCity->getRegion() != nullptr) {
					currentPlayer->placeNewArmy(aCity->getRegion());
					currentPlayer->PayCoin(gameHand->getCost(indexToPlay), 'c');
					gameHand->exchange(indexToPlay);
					return;
				}
				else {

					currentPlayer->placeNewArmy();
					currentPlayer->PayCoin(gameHand->getCost(indexToPlay), 'c');
					gameHand->exchange(indexToPlay);
					return;
				}
			}
		}
	}
	// play a move card
	int numOfMove = moveArmyCards.size();
	if (numOfMove <= 0) {
		return;
	}
	int indexToPlay = moveArmyCards.at(rand() % numOfMove);
	Card* chosenCard = gameHand->getCard(indexToPlay);
	string action = chosenCard->getAction();
	action = action.substr(action.find("Move Armies: "));
	string numOfArmies = action.substr(string("Move Armies: ").size(), string("Move Armies: ").size() + 1);
	int actionValue = std::stoi(numOfArmies);
	currentPlayer->PayCoin(gameHand->getCost(indexToPlay), 'c');
	gameHand->exchange(indexToPlay);
	return;

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

	cout << "SELECTING CARDS OF INTEREST\n" << endl;
	for (int i = 0; i < cardsInHand.size(); i++) {
		Card currentCard = *(cardsInHand.at(i));

		// read all cards and choose the ones that have to do with controlling a region
		// controlling a region = having more armies in a given region

		if (currentCard.getAction().find_first_of("Place Army")) {
			cout << "Card with action of primary interest: " << currentCard.getAction() << endl;
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
