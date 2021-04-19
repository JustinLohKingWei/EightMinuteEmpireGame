#pragma once
#include "GameObservers.h" //subject
#include <list>
using namespace std;

//Needs to have a forward reference due to
//circular reference between Observer and Subject
class GameObservers;

class Subject
{
public:
    virtual void Attach(GameObservers *o);
    virtual void Detach(GameObservers *o);
    virtual void Notify();
    virtual void notifyEvent(string playerName, string msg);
    virtual void notifyCard(Card* card, int cardPosition, int playerNumber);
    Subject();
    ~Subject();

private:
    list<GameObservers *> *_gameObservers;
};
