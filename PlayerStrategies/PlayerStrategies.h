#pragma once
#include "../Player/Player.h"
#include "../BidingFacility//Bid.h"

#include <iostream>
using namespace std;

class Hand;

class Strategy {
public:
	virtual void playTurn(Hand * aGameHand, Bid* biddingFacility)  = 0;
	string getType() { return type; }

	string type;
};

	
class GreedyComputerStrategy : public Strategy
{
public:
	GreedyComputerStrategy() { type = "Greedy"; }
	void playTurn(Hand* GameHand, Bid* biddingFacility);
	
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