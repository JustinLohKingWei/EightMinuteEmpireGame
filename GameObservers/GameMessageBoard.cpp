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
}

void Update() {}
void Display() {}
void SetSubject(Player *p) {}