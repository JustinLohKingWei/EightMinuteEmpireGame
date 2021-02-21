#include "Card.h"
#ifndef CARD_CPP
#define CARD_CPP
#include <string>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

Card::Card(std::string theName, std::string theGood, std::string theAction) {
    name = theName;
    good = theGood;
    action = theAction;
}

void Card::showAction() {
    cout << "This card's action is: " << getAction() << "\n";
}

void Card::showGood() {
    cout << "This card's action is: " << getGood() << "\n";
}

std::string Card::getName() {
    return name;
}

std::string Card::getAction() {
    return action;
}

std::string Card::getGood() {
    return good;
}


Hand::Hand(Card* newCardsInHand[]){
    for (int i = 0; i < 6; i++) {
        cardsInHand[i] = newCardsInHand[i];
    }
}


void Hand::details(int index){
    cardsInHand[index]->showAction();
    cardsInHand[index]->showGood();
}
void Hand::viewHand(){
    for (int i = 0; i<5; i++){
        if (getCard(i) != NULL){
            details(i);
        }
        else{
            cout << "Space " << i << "is empty";
        }
    }
}

Card* Hand::exchange(int index){
    cout << "You've used the following card for " << getCost(index) << ": \n";
    details(index);
    Card* exchangedCard = cardsInHand[index];
    setCard(NULL, index);
    return exchangedCard;
}

int Hand::getCost(int index){
    if (index == 0){
        return 0;
    }
    else if (index == 1 || index == 2){
        return 1;
    }
    else if (index == 3 || index == 4){
        return 2;
    }
    else if (index == 5){
        return 3;
    }
}

Card* Hand::getCard(int index) {
    return cardsInHand[index];
}

void Hand::setCard(Card* newCard, int index){
    cardsInHand[index] = newCard;
}

Deck::Deck(deque<Card*> cardList) {
    listOfCards = cardList;
}

std::deque<Card*> Deck::getListOfCards() {
    return listOfCards;
}


Card* Deck::getTopCard() {
    Card* top = listOfCards[0];
    listOfCards.pop_front();
    return top;
}

void Deck::draw(Hand* aHand) {
    vector<int> indices;
    for (int i = 0; i < 6; i++) {
        if (aHand->getCard(i) == NULL) {
            indices.push_back(i);
        }
    }
    if (indices.size() == 0) {
        cout << "No space for new cards in hand. \n";
    }
    else {
        cout << "The available positions are: \n";
        for (int i = 0; i < indices.size(); i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
        cout << "Please enter the position for the card: ";
        bool incorrect = true;
        int position;
        do {
            std::cin >> position;
            if (aHand->getCard(position) != NULL || position > 5) {
                cout << "Incorrect input, please try again. \n";
            }
            else {
                incorrect = false;
            }
        } while (incorrect);

        aHand->setCard(getTopCard(), position);
    }
}


#endif CARD_CPP
