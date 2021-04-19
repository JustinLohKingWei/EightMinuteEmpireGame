#pragma once
#include "GameObservers.h" //subject
#include <list>
using namespace std;
using std::list;

//class GameObservers;

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
   static list<GameObservers *> *_gameObservers;
};
