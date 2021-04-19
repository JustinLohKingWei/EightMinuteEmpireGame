#pragma once
#include "../Player/Player.h";
#include "../Card/Card.h";
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
    void updateEvent(string playerName, string msg);
    void displayCard(Card* card, int cardPosition, int playerNumber, int cost);

private:
    Player *_subject;
};