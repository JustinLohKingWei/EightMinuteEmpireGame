#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "../Map/Map.h"
#include "../BidingFacility/Bid.h"
#include "../Card/Card.h"
#include "../GameObservers/Subject.h";
#include "../PlayerStrategies/PlayerStrategies.h"
using namespace std;

class Region;
class Strategy;

struct playerGoods {

	void setRegion(Region* aRegion);
	Region* getRegion();
	void setPlaced(bool placed);
	
	string fname;
	string lname;

	void setOwner(string fname, string lname) { this->fname = fname; this->lname = lname; }
	Region* aRegion;
	bool isPlaced;
};

class Army : public playerGoods {
public:
	Army() { aRegion = 0;  isPlaced = false; };
	Army(const Army& b);
	Army& operator =(const Army& e);
	~Army() {  };
	friend ostream& operator << (ostream& out, const Army& anArmy);

};

class City : public playerGoods {
public:
	City() { aRegion = 0; isPlaced = false; };
	City(const City& b);
	City& operator =(const City& e);
	~City() { delete aRegion; };
	friend ostream& operator << (ostream& out, const City& aCity);

};

class Player : public Subject {
public:
	Player();
	Player(string f, string l, vector<Card*>listOfCardsUsed, vector<Region*> listOfRegions, vector<Army*> listOfArmies, vector<City*> listOfCities, Strategy* initStrategy) :
		firstName(f), lastName(l), myBidingFacility(new Bid(f, l)), myListOfCardsUsed(listOfCardsUsed), listOfTerritories(listOfRegions), listOfArmy(listOfArmies), listOfCities(listOfCities), strategy(initStrategy) {
		listOfPlayers.push_back(this);
	};
	Player(const Player& b);
	Player& operator =(const Player& e);
	~Player() {};//Destructor
	friend ostream& operator << (ostream& out, const Player& aPlayer);
	friend istream& operator >> (istream& in, Player& aPlayer);
	bool PayCoin(int payableAmount, char type);

	// Card action-related methods
	void PlaceNewArmies(int numberOfArmies);
	void MoveArmies(int numberOfArmiesToMove);
	void MoveOverLand(Region* from, Region* to);
	void MoveOverWater(Region* from, Region* to);
	vector<Region*> canBuildCity();
	bool buildCity(Region*);
	void BuildCity(int numberOfCities);
	bool DestroyArmy(int numberToDestroy);
	void andOr(Card* currentCard);
	vector<Army*> canDestroyArmy();
	void destroyArmy(Army*);

	//void setCardUsed(Card* aCard);
	void setBidingFacility(Bid* aBidingFacility);
	void setListOfTerritories(vector<Region*> list);
	void setFirstName(string f);
	void setLastName(string l);
	vector<Card*> get_my_list_of_used_cards() const;

	//Card* getCard();
	Bid* getBidingFacility();
	vector<Region*> getListOfTerritories();
	vector<Army*> getListOfArmy();
	vector<City*> getListOfCities();
	string getFirstName();
	string getLastName();
	static vector<Player*>listOfPlayers;
	
	//MVC methods

	// Strategy methods
	void setStrategy(Strategy* newStrategy);
	void executeStrategy(Hand* aGameHand, Bid* biddingFacility, Player* thisPlayer);
private:
	Strategy* strategy;
	vector<Region*> listOfTerritories;
	vector<City*> listOfCities;//10
	vector<Army*> listOfArmy;//18
	vector<Card*>myListOfCardsUsed;
	Bid* myBidingFacility;
	string firstName, lastName;
	
};

