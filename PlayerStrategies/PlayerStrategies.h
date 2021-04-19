#pragma once
#include "../Player/Player.h"
#include "../Game/Game.h"
#include <iostream>
using namespace std;

class Hand;

class Strategy {
public:
	virtual void playTurn(Hand * aGameHand, Bid* biddingFacility, Player* aPlayer)  = 0;

};

	
class GreedyComputerStrategy : public Strategy
{
public:
	void playTurn(Hand* GameHand, Bid* biddingFacility, Player* aPlayer);
};

class HumanStrategy : public Strategy {
public:
	void playTurn(Hand* GameHand, Bid* biddingFacility);
};

class ModerateComputerStrategy : public Strategy {
public:
	void playTurn(Hand *aGameHand, Bid* biddingFacility);
};