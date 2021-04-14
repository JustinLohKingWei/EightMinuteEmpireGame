#include"./Player/Player.h";
#include "GameMessageBoard.h"
#include <iostream>
using namespace std;

GameMessageBoard:: GameMessageBoard(Player* p){
  //Upon instantiation, attaches itself to a ClockTimer
  _subject = p;
  _subject->Attach(this);
}