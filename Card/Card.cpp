#include "Card.h"
#ifndef CARD_CPP
#define CARD_CPP
#include <string>
#include <iostream>
#include <vector>
#include <deque>

Card::Card(std::string theGood, std::string theAction) {
    good = theGood;
    action = theAction;
}

void Card::action() {
    cout << "This card's action is: " << getAction() >> "\n";
}

void Card::good() {
    cout << "This card's action is: " << getGood() >> "\n";
}

std::string Card::getAction() {
    return action;
}

std::string Card::getGood() {
    return good;
}


Deck::Deck(deque<Card*> cardList) {
    listOfCards = cardList;
}

vector<Card*> Deck::getListOfCards() {
    return listOfCards;
}


Card* Deck::getTopCard(){
    return listOfCards.pop_front();
}

void Deck::draw(Hand *hand) {
    vector<int> indices;
    for (int i = 0; i < 6; i++){
        if (hand.getCard(i) == null){
            indices.push_back(i);
        }
    }
    if (indices.size() == 0){
        cout << "No space for new cards in hand. \n";
    }
    else {
        cout << "The available positions are: \n";
        for (int i = 0; i < indices.size(); i++){
            cout << indices[i] << " ";
        }
        cout << endl;
        cout << "Please enter the position for the card: "
        bool incorrect = true;
        do {
            std::cin >> position;
            if (hand.getCard(position) != null || position > 5){
                cout << "Incorrect input, please try again. \n";
            }
            else{
                incorrect = false;
            }
        }while(incorrect);

        hand.setCard(this.getTopCard(), position);
    }
}

Hand::Hand(array<Card*, 6> newCardsInHand){
    cardsInHand = newCardsInHand;
}


void Hand::details(int index){
    cout << this.cardsInHand[index].action() >> "\n";
    cout << this.cardsInHand[index].good() >> "\n";
}
void Hand::viewHand(){
    for (int i = 0; i<5; i++){
        if (this.getCard(i) != null){
            this.details(i);
        }
        else{
            cout << "Space " >> i >> "is empty";
        }
    }
}

void Hand::exchange(int index){
    cout << "You've used the following card: \n"
    this.details(index);
    this.setCard(nullptr_t, index);
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

void Hand::setCard(Card* newCard, int index){
    cardsInHand[index] = newCard;
}

#endif CARD_CPP
