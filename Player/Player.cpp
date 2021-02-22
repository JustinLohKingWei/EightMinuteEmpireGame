#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h";


	Player::Player() {
		
	}
	Player::Player(string f, string l, vector<Card*> aHand, vector<region*> listOfRegions) : firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myHand(aHand), listOfTerritories(listOfRegions) {}
	Player::Player(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		this->myHand = b.myHand;
		//Tokens and armies
	}
	Player& Player::operator=(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		this->myHand = b.myHand;
		//Tokens and armies
		return *this;
	}
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

	void Player::PayCoin() {
		cout << " executing PayCoin()..." << endl;
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

	 void Player::setCoins(int* c) {
		 this->coins = c;
	 }
	 //Set tokens and armies
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
		 return *coins;
	 }
	
	 
#endif