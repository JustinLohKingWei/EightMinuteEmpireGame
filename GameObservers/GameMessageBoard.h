#pragma once
#include "./Player/Player.h";
#include "GameObservers.h";

class GameMessageBoard : public GameObservers //concrete observers
{

public:
    GameMessageBoard();
    GameMessageBoard(Player *p);
    ~GameMessageBoard();
    void Update();
    void Display();
    void SetSubject(Player *);

private:
    Player *_subject;
};