#include "GameObservers.h";
#include <iostream>
using std::cout;
using std::endl;               // observer class

GameObservers::GameObservers() {}

GameObservers::~GameObservers() {

    cout<<"In game observer"<<endl;
}