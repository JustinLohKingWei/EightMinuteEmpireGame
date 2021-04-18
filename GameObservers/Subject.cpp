#include "Subject.h" //subject
#include "GameObservers.h"
#include <iostream>
using namespace std;

Subject::Subject()
{
    _gameObservers = new list<GameObservers *>;
}
Subject::~Subject()
{
    delete _gameObservers;
}
void Subject::Attach(GameObservers *o)
{
    _gameObservers->push_back(o);
};
void Subject::Detach(GameObservers *o)
{
    _gameObservers->remove(o);
};
void Subject::Notify()
{
    list<GameObservers *>::iterator i = _gameObservers->begin();
    for (; i != _gameObservers->end(); ++i)
        (*i)->Update();
};
void Subject::notifyEvent(string playerName, string msg) {
    list<GameObservers*>::iterator i = _gameObservers->begin();
    for (; i != _gameObservers->end(); ++i)
        (*i)->updateEvent(playerName, msg);
};