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
    Subject();
    ~Subject();

private:
    list<GameObservers *> *_gameObservers;
};
