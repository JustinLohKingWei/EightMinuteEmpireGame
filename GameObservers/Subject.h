#pragma once

#include "GameObservers.h" //subject
#include "../Card/Card.h"
#include <list>
using namespace std;
using std::list;

//class GameObservers;

class Subject
{
public:
    static list<GameObservers*>* _gameObservers;
    virtual void Attach(GameObservers *o);
    virtual void Detach(GameObservers *o);
    virtual void Notify();
    virtual void notifyEvent(string playerName, string msg);
    virtual void notifyCard(Card* card, int cardPosition, int playerNumber, int cost);
    Subject();
    ~Subject();

private:

};
