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
	Player(string f, string l, vector<Card*> aHand, vector<region*> listOfRegions);
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

	void setHand(vector<Card*> aHand);
	void setBidingFacility(Bid* aBidingFacility);
	void setListOfTerritories(vector<region*> list);
	void setFirstName(string f);
	void setLastName(string l);
	void setCoins(int c);
	vector<Card*> getHand();
	Bid* getBidingFacility();
	vector<region*> getListOfTerritories();
	string getFirstName();
	string getLastName();
	int getCoins();
	
private:
	vector<region*> listOfTerritories;
	vector<Card*> myHand;
	Bid* myBidingFacility;
	string firstName, lastName;
	int coins;
	
};




#endif
