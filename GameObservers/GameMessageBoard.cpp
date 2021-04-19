#include "../Player/Player.h";
#include "GameMessageBoard.h"
#include <iostream>
using std::cout;
using std::endl;

GameMessageBoard::GameMessageBoard(Player *p)
{
  //Upon instantiation, attaches itself to a ClockTimer
  _subject = p;
  _subject->Attach(this);
};

GameMessageBoard::~GameMessageBoard()
{
  _subject->Detach(this);
};
GameMessageBoard::GameMessageBoard()
{
    _subject = nullptr;
};
void GameMessageBoard::Update()
{
  Display();
};

void GameMessageBoard::Display(){
    //TODO DISPLAY STATS HERE

    //int stat1 = _subject.getStat1();
    string name = _subject->getFirstName();
    int coins = _subject->getBidingFacility()->getCopperCoins();
    int noOfArmies = _subject->getNoOfArmies();
    int noOfRegions = _subject->getNoOfRegions();

    cout<<name<<"   ||  "<<noOfArmies<< " armies   ||  "<<noOfRegions<<" Regions   ||  "<<coins<<"coins  ||     "<<endl;
};

void GameMessageBoard::displayCard(Card* card, int cardPosition, int playerNumber, int cost) {
    cout << "GAME: Player " << playerNumber << " selects card #" << cardPosition << ". It costs " << cost << " coins." << endl;
    cout << "GAME: This card's action is: " << card->getAction() << endl;
}

void GameMessageBoard::updateEvent(string playerName, string msg) {
    cout << "GAME: Player " << playerName << " : " << msg << endl;
}

void GameMessageBoard::SetSubject(Player *p)
{
  _subject = p;
};
