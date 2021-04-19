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
   lastCoins = _subject->getBidingFacility()->getCopperCoins();
   lastArmies = _subject->getNoOfArmies();
   lastRegions = _subject->getNoOfRegions();
   lastCities = _subject->getNoOfCities();
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
    cout << "OBSERVER DISPLAY" << endl;
    string name = _subject->getFirstName();
    int coins = _subject->getBidingFacility()->getCopperCoins();
    int noOfArmies = _subject->getNoOfArmies();
    int noOfRegions = _subject->getNoOfRegions();
    int noOfCards = _subject->getNoOfCards();
    int noOfCities = _subject->getNoOfCities();

    if (noOfCities > lastCities) {
        cout << name << " has gained a city! What a chad !" << endl;
    }
    else if (noOfCities < lastCities) {
        cout << name << " has lost control of a city! OH the SHAME!" << endl;
    }
    else {
        cout << name << " has neither lost or gained any regions." << endl;
    }


    if (noOfRegions>lastRegions) {
        cout << name<<" has gained a region! They are Unstoppable !" << endl;
    }
    else if (noOfRegions < lastRegions) {
        cout << name << " has lost control of a region!"<<name<<"please do not cry until the game is over" << endl;
    }
    else {
        cout << name << " has neither lost or gained any regions." << endl;
    }

    if (noOfCards>6) {
        cout << name << "has more than 6 cards! Congratulations!" << endl;
    }


    lastCoins = _subject->getBidingFacility()->getCopperCoins();
    lastArmies = _subject->getNoOfArmies();
    lastRegions = _subject->getNoOfRegions();
    lastCities = _subject->getNoOfCities();

    cout<<name<<"   ||  "<<noOfArmies<< " armies   ||  "<<noOfRegions<<" Regions   ||  "<<coins<<"coins  || " << noOfCards << "cards     "<<endl;
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
