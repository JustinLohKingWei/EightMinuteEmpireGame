#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h";

	//Default constructor
	Player::Player() {
		
	}
	//Parameterized constructor
	//Player::Player(string f, string l, Card* aCard, vector<region*> listOfRegions, vector<Army*> listOfArmies) : firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myCard(aCard), listOfTerritories(listOfRegions), listOfArmy(listOfArmies) { this->coins = 0; }
	//Copy constructor
	Player::Player(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		this->myCard = b.myCard;
		this->listOfArmy = b.listOfArmy;
		
	}
	//Assignment operator
	Player& Player::operator=(const Player& b) {
		this->firstName = b.firstName;
		this->lastName = b.lastName;
		this->listOfTerritories = b.listOfTerritories;
		this->coins = b.coins;
		this->myBidingFacility = b.myBidingFacility;
		this->myCard = b.myCard;
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

	Army::Army() {}

	Army::Army(const Army& b) {
		this->aRegion = b.aRegion;
	}

	Army& Army::operator =(const Army& e) { this->aRegion = e.aRegion; return *this; }

	ostream& operator << (ostream& out, const Army& anArmy) {
		out << "Army at " << anArmy.aRegion << endl;
		return out;
	}
	
	City::City() {}

	City::City(const City& b) {
		this->aRegion = b.aRegion;
	}

	City& City::operator =(const City& e) { this->aRegion = e.aRegion; return *this; }

	ostream& operator << (ostream& out, const City& aCity) {
		out << "Army at " << aCity.aRegion << endl;
		return out;
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

	//Setters and getters
	 void Player::setCard(Card* aCard){
		myCard = aCard;
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
	
	 Card* Player::getCard(){
		return myCard;
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
	
	 void Army::setRegion(region* aRegion) {
		this->aRegion = aRegion;
	 }

	 region* Army::getRegion() {
		 return aRegion;
	 }

	 void City::setRegion(region* aRegion) {
		 this->aRegion = aRegion;
	 }

	 region* City::getRegion() {
		 return aRegion;
	 }
#endif