#pragma once
class GameObservers             // observer class
{
public:
    virtual ~GameObservers();
    virtual void Update()=0;

protected:
    GameObservers();
};