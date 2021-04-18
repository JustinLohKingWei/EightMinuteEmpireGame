#pragma once
class GameObservers             // observer class
{
public:
    virtual ~GameObservers();
    virtual void Update()=0;
    virtual void updateEvent(string playerName, string msg) = 0;

protected:
    GameObservers();
};