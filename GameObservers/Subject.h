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
    Subject();
    ~Subject();

private:
   static list<GameObservers *> *_gameObservers;
};
