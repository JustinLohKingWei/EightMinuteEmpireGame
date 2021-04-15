#include "./Player/Player.h";
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

GameMessageBoard::GameMessageBoard()
{
  _subject->Detach(this);
};

void GameMessageBoard::Update()
{
  Display();
};
void GameMessageBoard::Display(){
    //TODO DISPLAY STATS HERE

    //int stat1 = _subject.getStat1();

    //cout<<stat1;

};

void GameMessageBoard::SetSubject(Player *p)
{
  _subject = p;
};
