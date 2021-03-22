#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h";

	//Default constructor
	Player::Player() {
		
	}
	//Parameterized constructor
	Player::Player(string f, string l, vector<Card*> aHand, vector<region*> listOfRegions) : firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myHand(aHand), listOfTerritories(listOfRegions) {}
	//Copy constructor
	Player::Player(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		this->myHand = b.myHand;
		
	}
	//Assignment operator
	Player& Player::operator=(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		this->myHand = b.myHand;
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

	// A player pays a certain amount of coins of either copper ('c') or silver ('s') type    -Justin
	void Player::PayCoin(int payableAmount,char type) {
		cout << " executing PayCoin()..." << endl;
		bool isEnough = true;
		if (type == 's' || type =='c'||payableAmount>0) {		//checks for valid input
			string coinType;
			if (type == 's') {
				coinType = "silver";
				if (payableAmount> this->getBidingFacility()->getSilverCoins()) {		//checks if there are enough coins for payment
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
			}
			else {																// denies payment if inadequate
				cout << "Not enough coins to make this purchase!";
			}
			cout <<"After payment , "<< this->getFirstName() << " has " << this->getBidingFacility()->getSilverCoins() << " silver coins, and has " << this->getBidingFacility()->getCopperCoins() << " copper coins." << endl;
		}
		else {
			cout << "Invalid input";
		}
	}

	void Player::PlaceNewArmies() {
		cout << " executing PlaceNewArmies()..." << endl;
	}

	void Player::MoveArmies() {
		cout << " executing MoveArmies()..." << endl;
	}

	void Player::MoveOverLand() {
		cout << " executing MoveOverLand()..." << endl;
	}

	void Player::BuildCity() {
		cout << " executing BuildCity()..." << endl;
	}

	void Player::DestroyArmy() {
		cout << " executing DestroyArmy()..." << endl;
	}

	//Setters and getters
	 void Player::setHand(vector<Card*> aHand){
		myHand = aHand;
	 }
	 
	 void Player::setBidingFacility(Bid* aBidingFacilty){
		this->myBidingFacility = aBidingFacilty;
	 }
	 
	 void Player::setListOfTerritories(vector<region*> list){
		this->listOfTerritories = list;
	 }
	 void Player::setFirstName(string f) {
		 this->firstName = f;
	 }
	 void Player::setLastName(string l) {
		 this->lastName = l;
	 }

	 void Player::setCoins(int c) {
		 this->coins = c;
	 }
	
	 vector<Card*> Player::getHand(){
		return myHand;
	 }
	 
	 Bid* Player::getBidingFacility(){
		return myBidingFacility;
	 }
	 
	 vector<region*> Player::getListOfTerritories(){
		return listOfTerritories;
	 }

	 string Player::getFirstName() {
		 return firstName;
	 }

	 string Player::getLastName() {
		 return lastName;
	 }

	 int Player::getCoins() {
		 return this->getBidingFacility()->getBidAmount();
	 }
	
	 
#endif