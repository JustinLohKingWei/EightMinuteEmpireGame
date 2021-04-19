#pragma once
#include <string>
#include "../Card/Card.h"

class GameObservers             // observer class
{
public:
    virtual ~GameObservers();
    virtual void Update()=0;
    virtual void updateEvent(string playerName, string msg) = 0;
    virtual void displayCard(Card* card, int cardPosition, int playerNumber)=0;

protected:
    GameObservers();
};