#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h";


	Player::Player() {
		
	}
	Player::Player(string* f, string* l) {
		this->firstName = f;
		this->lastName = l;
		//vector of regions already initialized
		this->myBidingFacility = new Bid(*f,*l);
		//this->myHand = new Hand( insert parameters );
		//initialize coins, tokens and armies
	}
	Player::Player(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		//this->myHand = b.myHand;
		//Tokens and armies
	}
	Player& Player::operator=(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		//this->myHand = b.myHand;
		//Tokens and armies
		return *this;
	}
	//Add assignment operator and stream insertion operator
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

	/*
	 void Player::setHand(Hand* aHand){
		myHand = &aHand;
	 }
	 */
	 void Player::setBidingFacility(Bid* aBidingFacilty){
		this->myBidingFacility = aBidingFacilty;
	 }
	 
	 void Player::setListOfTerritories(vector<region>* list){
		this->listOfTerritories = list;
	 }
	 void Player::setFirstName(string* f) {
		 this->firstName = f;
	 }
	 void Player::setLastName(string* l) {
		 this->lastName = l;
	 }

	 void Player::setCoins(int* c) {
		 this->coins = c;
	 }
	 //Set tokens and armies
	 //Hand Player::getHand(){
		//return myHand;//A pointer or raw value or a copy?
	 //}
	 //
	 Bid Player::getBidingFacility(){
		return *myBidingFacility;
	 }
	 
	 vector<region> Player::getListOfTerritories(){
		return *listOfTerritories;
	 }

	 string Player::getFirstName() {
		 return *firstName;
	 }

	 string Player::getLastName() {
		 return *lastName;
	 }

	 int Player::getCoins() {
		 return *coins;
	 }
	
	 
#endif