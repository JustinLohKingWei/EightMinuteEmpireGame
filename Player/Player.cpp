#include "Player.h";

//Default constructor
//Player::Player(string f, string l, Card* aCard, vector<region*> listOfRegions, vector<Army*> listOfArmies) : firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myCard(aCard), listOfTerritories(listOfRegions), listOfArmy(listOfArmies) { this->coins = 0; }
//Copy constructor
Player::Player(const Player& b) {
	this->firstName = b.firstName;
	this->lastName = b.lastName;
	this->listOfTerritories = b.listOfTerritories;
	this->myBidingFacility = b.myBidingFacility;
	this->myListOfCardsUsed = b.myListOfCardsUsed;
	this->listOfArmy = b.listOfArmy;
	this->strategy = b.strategy;

}
//Assignment operator
Player& Player::operator=(const Player& b) {
	this->firstName = b.firstName;
	this->lastName = b.lastName;
	this->listOfTerritories = b.listOfTerritories;
	this->myBidingFacility = b.myBidingFacility;
	this->myListOfCardsUsed = b.myListOfCardsUsed;
	return *this;
}
//Stream insertion operator
ostream& operator << (ostream& out, const Player& aPlayer) {
	out << "Player " << aPlayer.firstName << " " << aPlayer.lastName << " owns " << aPlayer.listOfTerritories.size() << " regions." << endl;
	return out;
}
istream& operator >> (istream& in, Player& aPlayer) {
	cout << "Enter first name ";
	in >> aPlayer.firstName;
	cout << "Enter last name ";
	in >> aPlayer.lastName;
	return in;
}


Army::Army(const Army& b) {
	this->aRegion = b.aRegion;
	this->isPlaced = b.isPlaced;
}

Army& Army::operator =(const Army& e) {
	this->aRegion = e.aRegion;
	this->isPlaced = e.isPlaced;
	return *this;
}

ostream& operator << (ostream& out, const Army& anArmy) {
	out << "Army at " << anArmy.aRegion->name << ", isPlaced: " << anArmy.isPlaced << endl;
	return out;
}

//City::City() {}

City::City(const City& b) {
	this->aRegion = b.aRegion;
}

City& City::operator =(const City& e) { this->aRegion = e.aRegion; return *this; }

ostream& operator << (ostream& out, const City& aCity) {
	out << "Army at " << aCity.aRegion << endl;
	return out;
}

// A player pays a certain amount of coins of either copper ('c') or silver ('s') type    -Justin
bool Player::PayCoin(int payableAmount, char type) {
	bool success = false;
	cout << " executing PayCoin()..." << endl;
	bool isEnough = true;
	if (type == 's' || type == 'c' || payableAmount > 0) {		//checks for valid input
		string coinType;
		if (type == 's') {
			coinType = "silver";
			if (payableAmount > this->getBidingFacility()->getSilverCoins()) {		//checks if there are enough coins for payment
				isEnough = false;
			}
		}
		else if (type == 'c') {
			coinType = "copper";
			if (payableAmount > this->getBidingFacility()->getCopperCoins()) {		//checks if there are enough coins for payment
				isEnough = false;
			}
		}

		cout << this->getFirstName() << " has to pay " << payableAmount << " " << coinType << "coins" << endl;
		cout << this->getFirstName() << " has " << this->getBidingFacility()->getSilverCoins() << " silver coins, and has " << this->getBidingFacility()->getCopperCoins() << " copper coins." << endl;

		if (isEnough) {														// allows payment if there are enough coins
			this->getBidingFacility()->payCoins(payableAmount, type);
			success = true;
		}
		else {																// denies payment if inadequate
			cout << "Not enough coins to make this purchase!";
			success = false;
		}
		cout << "After payment , " << this->getFirstName() << " has " << this->getBidingFacility()->getSilverCoins() << " silver coins, and has " << this->getBidingFacility()->getCopperCoins() << " copper coins." << endl;
	}
	else {
		cout << "Invalid input";
		success = false;
	}
	return success;
}

void Player::PlaceNewArmies(int numberOfArmies, region* aRegion) {//Handling placing in multiple regions in the driver
	//cout << " executing PlaceNewArmies()..." << endl;
	int counter = 0;
	for (Army* armyPiece : getListOfArmy()) {

		if (!armyPiece->getIsPlaced() && counter < numberOfArmies && listOfCities.size() == 0) {
			armyPiece->setRegion(aRegion);//Starting region
			armyPiece->setPlaced(true);
			counter++;
		}
		else {
			for (City* cityPiece : getListOfCities()) {
				//Placing on a region where player has city
				if (cityPiece->getRegion()->name == aRegion->name && !armyPiece->getIsPlaced() && counter < numberOfArmies) {
					armyPiece->setRegion(aRegion);
					armyPiece->setPlaced(true);
					cityPiece->setPlaced(true);
					counter++;
				}
			}
		}
	}
}

void Player::MoveArmies(int numberOfArmiesToMove) {
	vector<int>adjList;
	cout << " executing MoveArmies()..." << endl;
	int counter = 0;
	cout << "displaying armies available..." << endl;
	int index = 0;
	int adjacency = 0;
	//bool selected = false;
	string choice;
	//int choiceOfMovement;

	for (Army* armyPiece : getListOfArmy()) {
		cout << "Army # " << index++ << " " << *armyPiece << "\n" << endl;//Displaying available armies

	}
	while (counter < numberOfArmiesToMove) {
		cout << "Displaying regions with owned player's army + adjacency" << endl;
		for (region* aRegion : getListOfTerritories()) {
			adjacency = 0;
			map<string, region*>::iterator it = aRegion->adj.begin();
			while (it != aRegion->adj.end()) {
				region* current = it->second;
				adjacency++;
				adjList.push_back(adjacency);
				cout << "\ncurrent region " << aRegion->name << " adjacent to: " << current->name << "( " << adjacency << " )" << endl;

				it++;
			}

			cout << "Select an army to move from current region? Enter key : (Y/y)es (N/n)o" << endl;
			cin >> choice;

			if (choice == "Y" || choice == "y") {
				/*if (adjacency == 1) {

				}*/
				MoveOverLand(adjList, aRegion);
				counter++;
			}

			if (choice == "N" || choice == "n") {
				continue;
			}
		}
	}




}

void Player::MoveOverLand(vector<int> list, region* from) {
	int choice;
	cout << " executing MoveOverLand()..." << endl;
	cout << "\nSelect target adjacent region to move army" << endl;
	cin >> choice;
	int index = 0;
	int counter = 0;
	map<string, region*>::iterator it = from->adj.begin();
	while (it != from->adj.end()) {
		region* current = it->second;
		for (Army* armyPiece : getListOfArmy()) {
			if (index == choice - 1) {

				if (armyPiece->getRegion()->name == from->name) {
					armyPiece->setRegion(current);


					cout << "\nMoved an armyPiece from " << from->name << " to " << current->name << endl;

					for (region* aRegion : getListOfTerritories()) {
						if (aRegion->name == from->name) {
							cout << "hello" << endl;
							aRegion = nullptr;
							break;

						}
						counter++;
					}
					return;
				}

			}

		}
		index++;
		it++;
	}
}

void Player::MoveOverWater() {

}

void Player::BuildCity(region* where) {
	cout << " executing BuildCity()..." << endl;
	for (City* cityPiece : getListOfCities()) {
		if (cityPiece->getIsPlaced() == false) {
			cityPiece->setPlaced(true);
			cityPiece->setRegion(where);
			return;
		}
	}
}
//Maybe static player array?
bool Player::DestroyArmy(vector<Player*>listOfPlayers, region* where, string target) {
	cout << " executing DestroyArmy()..." << endl;
	bool isAtRegion = false;
	for (Army* armyPiece : getListOfArmy()) {
		if (armyPiece->getRegion()->name == where->name) {//If current player has an army at the specified region
			isAtRegion = true;
		}
	}
	if (isAtRegion == false) {//If current player does not have any army at specified region, do nothing
		return false;
	}
	else {
		for (Player* aPlayer : listOfPlayers) {

			if (aPlayer->getFirstName() == target) {
				for (Army* armyPiece : aPlayer->listOfArmy) {

					if (armyPiece->getRegion() == where) {
						delete armyPiece;
						break;
					}

				}
			}
		}
	}
	return true;
}

void Player::andOr(Card* current) {
	string delim1 = "AND";
	string delim2 = "OR";
	string action1 = "";
	string action2 = "";
	string choiceOfRegion;
	if (current->getAction().find(delim1)) {// AND
		action1 = current->getAction().substr(0, current->getAction().find(delim1));
		action2 = current->getAction().substr(current->getAction().find(delim1));

		action1 = current->getAction().substr(0, current->getAction().find(" "));
		string amount1 = action1.substr(current->getAction().find(": "));
		int amountOfFirstAction = std::stoi(amount1);

		action2 = current->getAction().substr(0, current->getAction().find(" "));
		string amount2 = action1.substr(current->getAction().find(": "));
		int amountOfSecondAction = std::stoi(amount2);
		int actionCount = 0;

		while (actionCount < 2) {
			if (action1 == "Place") {

				for (City* aCity : getListOfCities()) {
					if (aCity->getIsPlaced()) {
						cout << "Place new army at this region? (Y/y)es/(N/n)o : " << aCity->getRegion()->name << endl;
						cin >> choiceOfRegion;
						if (choiceOfRegion == "Y" || choiceOfRegion == "y") {
							PlaceNewArmies(amountOfFirstAction, aCity->getRegion());
						}

						if (choiceOfRegion == "N" || choiceOfRegion == "n") {
							continue;
						}
					}
				}

			}
			else if (action1 == "Move") {
				MoveArmies(amountOfFirstAction);

			}
			else if (action1 == "Build") {
				for (Army* anArmy : getListOfArmy()) {
					if (anArmy->getIsPlaced()) {
						cout << "Place new city at this region? (Y/y)es/(N/n)o : " << anArmy->getRegion()->name << endl;
						cin >> choiceOfRegion;
						if (choiceOfRegion == "Y" || choiceOfRegion == "y") {
							BuildCity(anArmy->getRegion());
						}

						if (choiceOfRegion == "N" || choiceOfRegion == "n") {
							continue;
						}
					}
				}

			}
			else if (action1 == "Destroy") {
				string choiceToDestroy;
				for (Army* anArmy : getListOfArmy()) {
					if (anArmy->getIsPlaced()) {
						cout << "Destroy army at this region? (Y/y)es/(N/n)o : " << anArmy->getRegion()->name << endl;
						cin >> choiceToDestroy;
						if (choiceToDestroy == "Y" || choiceToDestroy == "y") {
							for (Player* aPlayer : listOfPlayers) {
								for (Army* bArmy : aPlayer->getListOfArmy()) {
									if (bArmy->getIsPlaced() && bArmy->getRegion()->name == anArmy->getRegion()->name) {
										DestroyArmy(listOfPlayers, bArmy->getRegion(), aPlayer->getFirstName());
									}
								}

							}
						}

						if (choiceToDestroy == "N" || choiceToDestroy == "n") {
							continue;
						}

					}
				}

			}

			actionCount++;
		}

	}




	else if (current->getAction().find(delim2)) {// OR
		action1 = current->getAction().substr(0, current->getAction().find(delim2));
		action2 = current->getAction().substr(current->getAction().find(delim2));

		action1 = current->getAction().substr(0, current->getAction().find(" "));
		string amount1 = action1.substr(current->getAction().find(": "));
		int amountOfFirstAction = std::stoi(amount1);

		action2 = current->getAction().substr(0, current->getAction().find(" "));
		string amount2 = action1.substr(current->getAction().find(": "));
		int amountOfSecondAction = std::stoi(amount2);


	}
	else {
		action1 = current->getAction().substr(0, current->getAction().find(": "));
		string amount1 = action1.substr(current->getAction().find(": "));
		int amountOfAction = std::stoi(amount1);
	}
}

//Setters and getters
 /*void Player::setCard(Card* aCard){
	myCard = aCard;
 }*/

void Player::setBidingFacility(Bid* aBidingFacilty) {
	this->myBidingFacility = aBidingFacilty;
}

void Player::setListOfTerritories(vector<region*> list) {
	this->listOfTerritories = list;
}
void Player::setFirstName(string f) {
	this->firstName = f;
}
void Player::setLastName(string l) {
	this->lastName = l;
}
void playerGoods::setRegion(region* aRegion) {
	this->aRegion = aRegion;
}
void playerGoods::setPlaced(bool placed) {
	this->isPlaced = placed;
}
/*
 Card* Player::getCard(){
	return myCard;
 }*/

Bid* Player::getBidingFacility() {
	return myBidingFacility;
}

vector<region*> Player::getListOfTerritories() {
	return listOfTerritories;
}

vector<Army*> Player::getListOfArmy() {
	return listOfArmy;
}

vector<City*> Player::getListOfCities() {
	return listOfCities;
}

string Player::getFirstName() {
	return firstName;
}

string Player::getLastName() {
	return lastName;
}


void Player::setStrategy(Strategy* newStrategy)
{
	this->strategy = newStrategy;
}

void Player::executeStrategy(Hand *aGameHand)
{
	this->strategy->playTurn(aGameHand);
}

region* playerGoods::getRegion() {
	return aRegion;
}

bool playerGoods::getIsPlaced() {
	return isPlaced;
}

