#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "../Map/Map.h";
#include "../BidingFacility/Bid.h"
using namespace std;

class Player {
public:
	Player();
	Player(string f, string l);
	Player(const Player &b);
	Player& operator =(const Player& e);
	void PayCoin();
	void PlaceNewArmies();
	void MoveArmies();
	void MoveOverLand();
	void BuildCity();
	void DestroyArmy();

	//void setHand(Hand* aHand);
	void setBidingFacility(Bid* aBidingFacility);
	void setListOfTerritories(vector<region>* list);
	void setFirstName(string f);
	void setLastName(string l);
	void setCoins(int* c);
	//Hand getHand();
	Bid* getBidingFacility();
	vector<region> getListOfTerritories();
	string getFirstName();
	string getLastName();
	int getCoins();
	//Tokens and armies
private:
	vector<region>* listOfTerritories;
	//Hand* myHand;
	Bid* myBidingFacility;
	string firstName, lastName;
	int* coins;
	//Tokens and armies
};
#endif
