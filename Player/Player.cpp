 #include "Player.h";

//Default constructor
Player::Player() {

}
//Parameterized constructor
//Player::Player(string f, string l, Card* aCard, vector<Region*> listOfRegions, vector<Army*> listOfArmies) : firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myCard(aCard), listOfTerritories(listOfRegions), listOfArmy(listOfArmies) { this->coins = 0; }
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
	out << "Player " << aPlayer.firstName << " " << aPlayer.lastName << " owns " << aPlayer.listOfTerritories.size() << " Regions." << endl;
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
	out << "Army at " << anArmy.aRegion->get_name() << ", isPlaced: " << anArmy.isPlaced << endl;
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

		cout << this->getFirstName() << " has to pay " << payableAmount << " " << coinType << " coins" << endl;
		cout << this->getFirstName() << " has " << this->getBidingFacility()->getSilverCoins() << " silver coins, and has " << this->getBidingFacility()->getCopperCoins() << " copper coins." << endl;
		std::ostringstream oss;
		if (isEnough) {														// allows payment if there are enough coins
			this->getBidingFacility()->payCoins(payableAmount, type);
			success = true;
			oss << " was able to pay! ";
		}
		else {																// denies payment if inadequate
			oss << " was not able to pay! ";
			success = false;
		}
		// Notify GameMessageBoard of Event:
		oss << "They have " << this->getBidingFacility()->getSilverCoins() << " silver coins, and has " << this->getBidingFacility()->getCopperCoins() << " copper coins." << endl;
		string message = oss.str();
		this->notifyEvent(this->getFirstName(), message);
	}
	else {
		cout << "Invalid input" << endl; 
		success = false;
	}
	cout << "TOUCHED OBSERVER" << endl;
	Notify();
	return success;
}

void Player::PlaceNewArmies(int numberOfArmies) {//Handling placing in multiple Regions in the driver
	
	int numPlaced = 0;
	if (listOfTerritories.size() == 1) {//Set at starting Region
		
		for (Army* x : listOfArmy) {
			if (numPlaced < 4) {
				x->setRegion(listOfTerritories.at(0));
				numPlaced++;
				// Notify GameMessageBoard of Event:
				std::ostringstream oss;
				oss << "has placed an army at region " << listOfTerritories.at(0)->get_name() << endl;
				string message = oss.str();
				this->notifyEvent(this->getFirstName(), message);
			}
		}
	}
	else {
		numPlaced = numberOfArmies;

		while (numPlaced > 0) {
			cout << "Choose a Region below" << endl;
			int RegionIndex = 0;
			for (Region* x : listOfTerritories) {
				cout << x->get_name() << "(" << RegionIndex << ")" << endl;
				RegionIndex++;
			}
			int indexChoice;
			cin >> indexChoice;

			cout << "You have chosen to place armies at " << listOfTerritories.at(indexChoice)->get_name() << endl;

			cout << "How many armies would you like to place?" << endl;
			
			int armyCounter = 0;
			int numChoice;
			cin >> numChoice;

			if (numChoice > numberOfArmies || (numPlaced - numChoice) < 0 || numChoice <= 0) {
				cout << "Invalid number of armies to place" << endl;
				continue;
			}
			cout << listOfTerritories.at(indexChoice)->get_name() << "test"<<endl;
			for (Army* x : listOfArmy) {
				if (x->getRegion() == nullptr && armyCounter < numChoice) {
					x->setRegion(listOfTerritories.at(indexChoice));
					// Notify GameMessageBoard of Event:
					std::ostringstream oss;
					oss << "has placed an army at region " << listOfTerritories.at(indexChoice)->get_name() << endl;
					string message = oss.str();
					this->notifyEvent(this->getFirstName(), message);
					armyCounter++;
				}
			}
			numPlaced -= numChoice;
		}
	}
	Notify();
}

void Player::MoveArmies(int numberOfArmiesToMove) {

	cout << "Your armies are currently at...\n" << endl;
	int numCurrent = numberOfArmiesToMove;
	Region* current = 0;
	
	while (numCurrent > 0) {
		int RegionFromSelect = 0;
		for (Army* myArmy : listOfArmy) {

			if (current != myArmy->getRegion() && myArmy->getRegion() != nullptr) {
				myArmy->getRegion()->update_armies_to_region(this);
				cout << "(" << RegionFromSelect << ")" << myArmy->getRegion()->get_name() << " with " << myArmy->getRegion()->get_number_of_armies(this) << " armies\n" << endl;

				cout << "Current region adjacent to:" << endl;

				for (auto& x : myArmy->getRegion()->get_adjacency()) {
					cout << x.first << endl;
				}
				cout << "" << endl;
			}
			RegionFromSelect++;
			current = myArmy->getRegion();
		}
		cout << "Ennemy armies positions" << endl;
		for (Player* aPlayer : listOfPlayers) {
			if (aPlayer == this) {
				continue;
			}
			for (Region* x : aPlayer->listOfTerritories) {
				cout << x->get_name() << endl;
				x->update_armies_to_region(aPlayer);
				int numArmies = x->get_number_of_armies(aPlayer);
				cout << *aPlayer << "with " << numArmies << " armies " << endl;
			}
		}

		cout << "Select your region from where you want to move a piece..." << endl;
		int regionChoice; //from
		cin >> regionChoice;

		Region* from = listOfArmy.at(regionChoice)->getRegion();
		cout << "You have targeted: " << from->get_name() << endl;

		cout << "\nTargeted region is adjacent to:" << endl;
		int adjIndex = 0;
		for (auto& x : from->get_adjacency()) {
			cout << "(" << adjIndex << ")" << x.first << endl;
			adjIndex++;
		}
		adjIndex = 0;
		cout << "" << endl;

		cout << "Select new region:" << endl;
		cin >> regionChoice;
		Region* to = 0;
		for (auto& x : from->get_adjacency()) {
			if (adjIndex == regionChoice) {
				to = x.second;
			}
			adjIndex++;
		}
		if (to != nullptr) {
			cout << "You have targeted " << to->get_name() << " to move pieces" << endl;
			//MoveOverLand(from, to);
			from->update_armies_to_region(this);
			int fromNum = from->get_number_of_armies(this);

			cout << "\nHow many armies do you wish to move?" << endl;
			int moveChoice;
			cin >> moveChoice;

			if (moveChoice > fromNum || moveChoice <= 0) {
				cout << "Invalid number" << endl;
				continue;
			}

			int moveCounter = 0;
			while (moveCounter < moveChoice) {
				
				to->update_armies_to_region(this);
				int numA = to->get_number_of_armies(this);

				if (numA == 0) {
					listOfTerritories.push_back(to);
				}
				string ToIslandName = to->get_name().substr(0, to->get_name().find("Region"));
				string FromIslandName = from->get_name().substr(0, from->get_name().find("Region"));
				if (ToIslandName == FromIslandName) {
					MoveOverLand(from, to);
				}
				else {
					MoveOverWater(from, to);
					return;
				}
				moveCounter++;
			}
			numCurrent -= moveChoice;
			// Notify GameMessageBoard of Event:
			std::ostringstream oss;
			oss << "has moved" << moveChoice << " army piece(s) from region " << from->get_name() << " to " << to->get_name() << endl;
			string message = oss.str();
			this->notifyEvent(this->getFirstName(), message);
		}
		else {
			cout << "To is NULL" << endl;
		}
	}
	Notify();
}

void Player::MoveOverLand(Region* from, Region* to) {
	cout << "Moving over land..." << endl;
	
	Region* current = 0;
	for (Army* a : listOfArmy) {
		current = a->getRegion();
		if (current == from && current != nullptr) {
			a->setRegion(nullptr);
			a->setRegion(to);
			cout << "Armypiece moved from " << current->get_name() << " to " << a->getRegion()->get_name() << endl;
			return;
		}
		
	}
}

void Player::MoveOverWater(Region* from, Region* to) {
	cout << "Moving over water..." << endl;

	Region* current = 0;
	for (Army* a : listOfArmy) {
		current = a->getRegion();
		if (current == from && current != nullptr) {
			a->setRegion(nullptr);
			a->setRegion(to);
			cout << "Armypiece moved from " << current->get_name() << " to " << a->getRegion()->get_name() << endl;
			return;
		}

	}
}

void Player::BuildCity(int numberOfCities) {
	cout << "executing BuildCity()..." << endl;
	
	Region* current = 0;
	int RegionSelect = 0;
	int numPlaced = numberOfCities;
	int numChoice = 0;
	int cityCounter = 0;
	while (numPlaced > 0) {
		cout << "Available Regions to add city:" << endl;
		for (Army* a : listOfArmy) {
			if (current != a->getRegion() && a->getRegion() != nullptr) {
				cout << a->getRegion()->get_name() << "(" << RegionSelect << ")" << endl;
			}
			
			else if(current == a->getRegion() || a->getRegion() == nullptr){
				RegionSelect++;
				continue;
			}
			RegionSelect++;
			current = a->getRegion();
			
		}
		
		cout << "Select Region to add city:" << endl;
		cin >> RegionSelect;

		cout << "Select how many cities you wish to place:" << endl;
		cin >> numChoice;

		if (numChoice > numberOfCities || (numPlaced - numChoice) < 0 || numChoice <= 0) {
			RegionSelect = 0;
			cout << "Invalid number of cities to place" << endl;
			continue;
		}

		Region* where = listOfArmy.at(RegionSelect)->getRegion();
		for (City* c : listOfCities) {
			
			if (c->getRegion() == nullptr && cityCounter < numChoice) {
				cout << "City built at " << where->get_name() << endl;
				c->setRegion(where);
				cityCounter++;
			}
			

		}
		std::ostringstream oss;
		// Notify GameMessageBoard of Event:
		oss << "has placed" << cityCounter << " city piece(s) at region " << where->get_name() << endl;
		string message = oss.str();
		this->notifyEvent(this->getFirstName(), message);
		numPlaced -= cityCounter;
		cityCounter = 0;
	}
	
}
//Maybe static player array?

bool Player::DestroyArmy(int numberToDestroy) {
	int remainingToDestroy = numberToDestroy;
	int RegionTargetIndex = 0;
	Region* current = 0;

	for (Region* x : listOfTerritories) {
		cout << "(" << RegionTargetIndex << ") " << x->get_name() << endl;
		RegionTargetIndex++;
	}
	cout << "Your armies are currently at: " << endl;
	for (Army* myArmy : listOfArmy) {
		if (current != myArmy->getRegion() && myArmy->getRegion() != nullptr) {
			cout << myArmy->getRegion()->get_name() << endl;
			cout << "=======================" << endl;
			cout << "Checking for enemy armies at current Region...\n" << endl;

			int playerIndex = 0;
			for (Player* aPlayer : listOfPlayers) {
				if (aPlayer == this) {
					playerIndex++;
					continue;
				}
				myArmy->getRegion()->update_armies_to_region(aPlayer);
				cout << "(" << playerIndex << ")" << *aPlayer << "Number of armies at this Region: " << myArmy->getRegion()->get_number_of_armies(aPlayer) << endl;
				playerIndex++;
			}
			cout << "" << endl;

			cout << "Select a player on your Region to destroy army:" << endl;
			int playerTarget;
			cin >> playerTarget;

			cout << "You have targeted: " << *listOfPlayers.at(playerTarget) << endl;

			cout << "How many armies do you wish to destroy on that Region?" << endl;

			int armyNumToDestroy;
			cin >> armyNumToDestroy;

			if ((armyNumToDestroy > numberToDestroy) || (remainingToDestroy - armyNumToDestroy) < 0 || armyNumToDestroy <= 0) {

				cout << "Invalid number of armies to destroy" << endl;
				continue;
			}


			for (auto* army : listOfPlayers.at(playerTarget)->getListOfArmy()) {
				if (army->getRegion() == myArmy->getRegion() && remainingToDestroy > armyNumToDestroy) {
					army = nullptr;
					delete army;
					// Notify GameMessageBoard of Event:
					std::ostringstream oss;
					oss << "has destroyed an army at region " << myArmy->getRegion()->get_name() << endl;
					string message = oss.str();
					this->notifyEvent(this->getFirstName(), message);
				}

			}
			remainingToDestroy -= armyNumToDestroy;
			current = myArmy->getRegion();
		}
	}
	Notify();
	return true;
}
void Player::andOr(Card* current) {
	string delim1 = "AND";
	string delim2 = "OR";
	string action1 = "";
	string action2 = "";

	string actions[] = { "Place Army", "Move Armies", "Build City", "Destroy Army" };
	string choiceOfRegion;
	if (current->getAction().find(delim1) && current->getAction().find(delim1)!= string::npos) {// AND
		cout << "AND" << endl;
		action1 = current->getAction().substr(0, current->getAction().find(delim1));
		action2 = current->getAction().substr(current->getAction().find(delim1) + 4);

		cout << action1 << endl;
		cout << action2 << endl;

		string amount1 = action1.substr(current->getAction().find(":") + 1);
		int amountOfFirstAction = std::stoi(amount1);

		cout << "amount 1 " << amountOfFirstAction << endl;

		string amount2 = action2.substr(action2.find(":") + 1);
		int amountOfSecondAction = std::stoi(amount2);

		cout << "amount 2 " << amountOfSecondAction << endl;
		
		action1 = action1.substr(0, action1.find(":"));
		action2 = action2.substr(0, action2.find(":"));
		
		if (action1 == actions[0]) {
			PlaceNewArmies(amountOfFirstAction);
		}
		else if (action1 == actions[1]) {
			MoveArmies(amountOfFirstAction);
		}
		else if (action1 == actions[2]) {
			BuildCity(amountOfFirstAction);
		}
		else if (action1 == actions[3]) {
			DestroyArmy(amountOfFirstAction);
		}
		if (action2 == actions[0]) {
			PlaceNewArmies(amountOfSecondAction);
		}
		else if (action2 == actions[1]) {
			MoveArmies(amountOfSecondAction);
		}
		else if (action2 == actions[2]) {
			BuildCity(amountOfSecondAction);
		}
		else if (action2 == actions[3]) {
			DestroyArmy(amountOfSecondAction);
		}

	}
	else if (current->getAction().find(delim2) && current->getAction().find(delim2) != string::npos) {
		cout << "OR" << endl;
		action1 = current->getAction().substr(0, current->getAction().find(delim2));
		action2 = current->getAction().substr(current->getAction().find(delim2) + 3);
		string action[] = { action1, action2 };
		cout << action1 << endl;
		cout << action2 << endl;

		string amount1 = action1.substr(current->getAction().find(":") + 1);
		int amountOfFirstAction = std::stoi(amount1);

		cout << "amount " << amountOfFirstAction << endl;

		string amount2 = action2.substr(action2.find(":") + 1);
		int amountOfSecondAction = std::stoi(amount2);

		cout << "amount " << amountOfSecondAction << endl;

		cout << "Choose your action (Press 1 or 2)" << endl;

		int actionChoice;
		cin >> actionChoice;

		action1 = action1.substr(0, action1.find(":"));
		action2 = action2.substr(0, action2.find(":"));

		if (action1 == actions[0] && actionChoice == 1) {
			//Place army
			cout << "Place armies" << endl;
			PlaceNewArmies(amountOfFirstAction);
			return;
		}
		else if (action1 == actions[1] && actionChoice == 1) {
			//Move armies
			cout << "Move armies" << endl;
			MoveArmies(amountOfFirstAction);
			return;
		}
		else if (action1 == actions[2] && actionChoice == 1) {
			//Build army
			cout << "Build city" << endl;
			BuildCity(amountOfFirstAction);
			return;
		}
		else if (action1 == actions[3] && actionChoice == 1) {
			//Destroy army
			cout << "Destroy army" << endl;
			DestroyArmy(amountOfFirstAction);
			return;
		}
		else if (action2 == actions[0] && actionChoice == 2) {
			//Place army
			cout << "Place armies" << endl;
			PlaceNewArmies(amountOfSecondAction);
			return;
		}
		else if (action2 == actions[1] && actionChoice == 2) {
			//Move armies
			cout << "Move armies" << endl;
			MoveArmies(amountOfSecondAction);
			return;
		}
		else if (action2 == actions[2] && actionChoice == 2) {
			//Build army
			cout << "Build city" << endl;
			BuildCity(amountOfSecondAction);
			return;
		}
		else if (action2 == actions[3] && actionChoice == 2) {
			//Destroy army
			cout << "Destroy army" << endl;
			DestroyArmy(amountOfSecondAction);
			return;
		}
	}
	Notify();
}

//Setters and getters
 /*void Player::setCard(Card* aCard){
	myCard = aCard;
 }*/

void Player::setBidingFacility(Bid* aBidingFacilty) {
	this->myBidingFacility = aBidingFacilty;
}

void Player::setListOfTerritories(vector<Region*> list) {
	this->listOfTerritories = list;
}
void Player::setFirstName(string f) {
	this->firstName = f;
}
void Player::setLastName(string l) {
	this->lastName = l;
}

vector<Card*> Player::get_my_list_of_used_cards() const
{
	return this->myListOfCardsUsed;
}
void playerGoods::setRegion(Region* aRegion) {

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

vector<Region*> Player::getListOfTerritories() {
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

void Player::executeStrategy(Hand *aGameHand, Bid* biddingFacility)
{
	this->strategy->playTurn(aGameHand, biddingFacility);
}

Region* playerGoods::getRegion() {
	return aRegion;
}

// MVC
void Player::useCard(Card* card, int cardPosition, int playerNumber) {
	// This method will notify the GameBoard about a card played.
	// _gameObservers->notifyCardPlayed(card, cardPosition, playerNumber);
}

//MVC Methods Part 3
int Player::getNoOfVictoryPoints() {
	return 0;
}
int Player::getNoOfArmies() {
	return listOfArmy.size();
}
int Player::getNoOfRegions() {
	return listOfTerritories.size();
}

int Player::getNoOfCards() {
	return myListOfCardsUsed.size();
}

int Player::getNoOfCities() {
	return listOfCities.size();
}

vector<Player*> Player::listOfPlayers;

