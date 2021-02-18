#include "Card.h"
#ifndef CARD_CPP
#define CARD_CPP
#include <string>
#include <iostream>
#include <vector>
#include <deque>

Card(std::string theGood, std::string theAction, int theCost) {
    good = theGood;
    action = theAction;
    cost = theCost;
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


Deck(deque<Card*> cardList) {
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

        hand.setCard(this.getTopCard());
    }
}

Hand(array<Card*, 6> newCardsInHand){
    cardsInHand = newCardsInHand;
}

void exchange()

#endif CARD_CPP
