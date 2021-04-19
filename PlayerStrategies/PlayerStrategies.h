#pragma once
#include "../Player/Player.h"
#include "../BidingFacility//Bid.h"

#include <iostream>
using namespace std;

class Hand;

class Strategy {
public:
	virtual void playTurn(Hand * aGameHand, Bid* biddingFacility)  = 0;

};

	
class GreedyComputerStrategy : public Strategy
{
public:
	void playTurn(Hand* GameHand, Bid* biddingFacility);
};

class HumanStrategy : public Strategy {
public:
	void playTurn(Hand* GameHand, Bid* biddingFacility);
};

class ModerateComputerStrategy : public Strategy {
public:
	void playTurn(Hand *aGameHand, Bid* biddingFacility);
};