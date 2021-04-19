#pragma once
#include "../Player/Player.h"
#include "../Game/Game.h"
#include "../BidingFacility//Bid.h"

#include <iostream>
using namespace std;

class Hand;

class Strategy {
public:

	string getType() { return type; }

	virtual void playTurn(Hand * aGameHand, Bid* biddingFacility, Player* aPlayer)  = 0;


	string type;
};

	
class GreedyComputerStrategy : public Strategy
{
public:

	GreedyComputerStrategy() { type = "Greedy"; }

	void playTurn(Hand* GameHand, Bid* biddingFacility, Player* aPlayer);

};

class HumanStrategy : public Strategy {
public:
	HumanStrategy() { type = "Human"; }
	void playTurn(Hand* GameHand, Bid* biddingFacility);
};

class ModerateComputerStrategy : public Strategy {
public:
	ModerateComputerStrategy() { type = "Moderate"; }
	void playTurn(Hand *aGameHand, Bid* biddingFacility);
};