#include "Card.h"
#ifndef CARD_CPP
#define CARD_CPP
#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Empty Constructor
Card::Card() {
    name = "Card Name";
    good = "Card Good";
    action = "Card Action";
}

//Constructor with Parameters
Card::Card(std::string theName, std::string theGood, std::string theAction) {
    name = theName;
    good = theGood;
    action = theAction;
}

// Copy Constructor
Card::Card(const Card& c) {
    name = c.name;
    good = c.action;
    action = c.action;
}

// Assignment Operator
Card& Card::operator = (const Card& card)
{
    Card :: operator= (card);
    name = card.name;
    good = card.action;
    action = card.action;
    return *this;
}

// Stream output Operator
ostream& operator <<(ostream& out, const Card& c)
{
    out << "Card Name: " << c.name << " Card Good: " << c.good << " Card Action: " << c.action << endl;
    return out;
}

// Stream input operator
istream& operator >> (istream& in, Card& c)
{
    cout << "Enter Card Name: ";
    in >> c.name;
    cout << "Enter Card Good ";
    in >> c.good;
    cout << "Enter Card Action ";
    in >> c.action;
    return in;
}

// Displays the action of a card.
void Card::showAction() {
    cout << "This card's action is: " << getAction() << "\n";
}

// Displays the good of a card.
void Card::showGood() {
    cout << "This card's action is: " << getGood() << "\n";
}

// Returns the name of a card.
std::string Card::getName() {
    return name;
}

// Returns the action of a card.
std::string Card::getAction() {
    return action;
}

// Returns the good of card.
std::string Card::getGood() {
    return good;
}


// Empty Constructor
Hand::Hand() {
    for (int i = 0; i < 6; i++) {
        cardsInHand[i] = NULL;
    }
}

// Parameterized Constructor
Hand::Hand(Card* newCardsInHand[]){
    for (int i = 0; i < 6; i++) {
        cardsInHand[i] = newCardsInHand[i];
    }
}

// Copy Constructor
Hand::Hand(const Hand& h) {
    for (int i = 0; i < 6; i++) {
        cardsInHand[i] = h.cardsInHand[i];
    }
}
Hand::~Hand() { 
    for (int i = 0; i < 6; i++) {
        delete cardsInHand[i];
    }
}

// Stream output Operator
ostream& operator <<(ostream& out, const Hand& h)
{
    int i = 0;
    for (int j = 0; j < 6; j++) {
        if (h.cardsInHand[j] != NULL) {
            i++;
        }
    }
    out << "There are " << i << " cards in the hand.";
    return out;
}

// Displays the details of an index of a card.
void Hand::details(int index){
    cout << *cardsInHand[index];
}

// Displays current hand.
void Hand::viewHand(){
    for (int i = 0; i<6; i++){
        if (getCard(i) != NULL){
            details(i);
        }
        else{
            cout << "Space " << i << "is empty";
        }
    }
}

// Returns a card with a given index.
Card* Hand::exchange(int index){
    cout << "You've used the following card for " << getCost(index) << ": \n";
    details(index);
    Card* exchangedCard = cardsInHand[index];
    setCard(NULL, index);
    return exchangedCard;
}

// Gets the cost of a current card.
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

// Re-arranges the array to push cards to the left
void Hand::slideCardsLeft(){
    // Check if card is missing from array
    int emptyIndex = -1; // -1 signifies no empty index
    for (int i = 0; i <= 5; i++) {
        if (getCard(i) == NULL) {
            emptyIndex = i;
        }
    }
    // If card is missing, take every card to the right and bring it one index lower
    if (emptyIndex != -1) {
        int indexBeingReplaced = emptyIndex;
        while (indexBeingReplaced < 5) {
            cardsInHand[indexBeingReplaced++] = cardsInHand[indexBeingReplaced+1];
        }
       setCard(NULL, indexBeingReplaced); 
    }
    // If no card is missing
    else {
        cout << "All spaces are occupied. No cards to slide to the left" << endl;
        cout << emptyIndex << endl;
    }
    
}

// Returns a card.
Card* Hand::getCard(int index) {
    return cardsInHand[index];
}

// Sets a card.
void Hand::setCard(Card* newCard, int index){
    cardsInHand[index] = newCard;
}

// Empty Constructor
Deck::Deck() {
    listOfCards = vector<Card*> {new Card("Ancient Phoenix", "Flight", "Move Armies: 5")};
}

// Parameterized Constructor
Deck::Deck(vector<Card*> cardList) {
    listOfCards = cardList;
}

// Copy Constructor
Deck::Deck(const Deck& d) {
    listOfCards = d.listOfCards;
}

Deck::~Deck() {
    for (int i = 0; i < listOfCards.size(); i++) {
        delete listOfCards[i];
    }
}

// Stream Output Operator
ostream& operator <<(ostream& out, const Deck& d)
{
    int i = 0;
    for (int j = 0; j < d.listOfCards.size(); j++) {
        if (d.listOfCards[j] != NULL) {
            i++;
        }
    }
    out << "There are " << i << " cards in the deck.";
    return out;
}


// Returns the list of cards.
std::vector<Card*> Deck::getListOfCards() {
    return listOfCards;
}


// Returns the top card of a deck.
Card* Deck::getTopCard() {
    Card* top = listOfCards[0];
    listOfCards.erase(listOfCards.begin());
    return top;
}

// Allows users to draw card then place it in the Hand.
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