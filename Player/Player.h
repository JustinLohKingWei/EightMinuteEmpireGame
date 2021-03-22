#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "../Map/Map.h";
#include "../BidingFacility/Bid.h"
#include "../Card/Card.h"
using namespace std;

class Player {
public:
	Player();
	Player(string f, string l, Card* aCard, vector<region*> listOfRegions, vector<Army*> listOfArmies, vector<City*> listOfCities) : 
		firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myCard(aCard), listOfTerritories(listOfRegions), listOfArmy(listOfArmies), listOfCities(listOfCities) { this->coins = 0; };
	Player(const Player &b);
	Player& operator =(const Player& e);
	~Player() {delete myBidingFacility;};//Destructor
	friend ostream& operator << (ostream& out, const Player& aPlayer);
	friend istream& operator >> (istream& in, Player& aPlayer);
	void PayCoin();
	void PlaceNewArmies();
	void MoveArmies();
	void MoveOverLand();
	void BuildCity();
	void DestroyArmy();

	void setCard(Card* aCard);
	void setBidingFacility(Bid* aBidingFacility);
	void setListOfTerritories(vector<region*> list);
	void setFirstName(string f);
	void setLastName(string l);
	void setCoins(int c);
	Card* getCard();
	Bid* getBidingFacility();
	vector<region*> getListOfTerritories();
	string getFirstName();
	string getLastName();
	int getCoins();
	
private:
	vector<region*> listOfTerritories;
	vector<City*> listOfCities;
	vector<Army*> listOfArmy;
	Card* myCard;
	Bid* myBidingFacility;
	string firstName, lastName;
	int coins;
	
};

class Army {
public:
	Army();
	Army(const Army& b);
	Army& operator =(const Army& e);
	~Army();
	friend ostream& operator << (ostream& out, const Army& anArmy);
	void setRegion(region* aRegion);
	region* getRegion();
private:
	region* aRegion;
};

class City {
public:
	City();
	City(const City& b);
	City& operator =(const City& e);
	~City();
	friend ostream& operator << (ostream& out, const City& aCity);
	void setRegion(region* aRegion);
	region* getRegion();
private:
	region* aRegion;
};


#endif
