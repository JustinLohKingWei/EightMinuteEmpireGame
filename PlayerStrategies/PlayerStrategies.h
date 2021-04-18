#pragma once
#include "../Player/Player.h"

#include <iostream>
using namespace std;

class Hand;

class Strategy {
public:
	virtual void playTurn(Hand * aGameHand)  = 0;

};

	
class GreedyComputerStrategy : public Strategy
{
public:
	void playTurn(Hand* GameHand);
};

class HumanStrategy : public Strategy {
public:
	void playTurn(Hand* GameHand);
};

class ModerateComputerStrategy : public Strategy {
public:
	void playTurn(Hand *aGameHand);
};