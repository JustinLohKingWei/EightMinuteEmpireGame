#ifndef PLAYER_CPP
#define PLAYER_CPP

#include "Player.h";


	Player::Player() {
		
	}
	/*
	* Player::Player(string f, string l, vector<Territory>* listOfTerritories, Hand* aHand, BidingFacility* aBidingFacility){
	*	firstName = f;
	*	lastName = l;
	*	listOfTerritories = &listOfTerritories;
	*	myHand = &aHand;
	*	myBidingFacility = &aBidingFacility;
	* }
	* 
	* Player::Player(Player &b){
	*	firstName = b.firstName;
	*	lastName = b.lastName;
	*	listOfTerritories = b.listOfTerritories;
	*	myHand = b.myHand;
	*	myBidingFacility = b.myBidingFacility;
	* }
	*/
	
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
	* void Player::setHand(Hand* aHand){
	*	myHand = &aHand;
	* }
	* 
	* void Player::setBidingFacility(BidingFacility* aBidingFacilty){
	*	myBidingFacility = &aBidingFacilty;
	* }
	* 
	* void Player::setListOfTerritories(vector<Territory>* list){
	*	listOfTerritories = &list;
	* }
	* 
	* Hand Player::getHand(){
	*	return myHand;//A pointer or raw value or a copy?
	* }
	* 
	* BidingFacilty Player::getBidingFacility(){
	*	return myBidingFacility;
	* }
	* 
	* vector<Territory> Player::getListOfTerritories(){
	*	return listOfTerritories;
	*}
	*/
	 
#endif