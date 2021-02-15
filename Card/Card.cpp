#include "Card.h"
#ifndef CARD_CPP
#define CARD_CPP
#include <string>
#include <iostream>
#include <vector>

Card::Card(std::string theGood, std::string theAction, int theCost) {
    good = theGood;
    action = theAction;
    cost = theCost;
}

void Card::action() {
    cout << "This card's action is: " << getAction();
}

void Card::good() {
    cout << "This card's action is: " << getGood();
}

void Card::cost() {
    cout << "This card's action is: " << getCost();
}

std::string Card::getAction() {
    return action;
}

std::string Card::getGood() {
    return good;
}

int Card::getCost() {
    return cost;
}

void Deck::draw(Hand *hand) {

}

#endif CARD_CPP
