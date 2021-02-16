#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
using namespace std;

class Player {
public:
	Player();
	//Player(vector<Territory>* listOfTerritories, Hand* aHand, BidingFacility* aBidingFacility);
	//Player(Player &b);
	void PayCoin();
	void PlaceNewArmies();
	void MoveArmies();
	void MoveOverLand();
	void BuildCity();
	void DestroyArmy();

	//void setHand(Hand* aHand);
	//void setBidingFacility(BidingFacility* aBidingFacility);
	//void setListOfTerritories(vector<Territory>* list);
	//Hand getHand();
	//BidingFacility getBidingFacility();
	//vector<Territory> getListOfTerritories();
private:
	//vector<Territory> listOfTerritories;
	//Hand* myHand;
	//BidingFacility* myBidingFacility;
	string firstName, lastName;
};
#endif
