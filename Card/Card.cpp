#include "Card.h"
#ifndef CARD_CPP
#define CARD_CPP
#include <string>
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

// Empty Constructor
Card::Card() {
    name = "Card Name";
    good = "Card Good";
    action = "Card Action";
    maxPlayerCount = 0;
}

//Constructor with Parameters
Card::Card(std::string theName, std::string theGood, std::string theAction, int playerCount) {
    name = theName;
    good = theGood;
    action = theAction;
    maxPlayerCount = playerCount;
}

// Copy Constructor
Card::Card(const Card& c) {
    name = c.name;
    good = c.action;
    action = c.action;
    maxPlayerCount = c.maxPlayerCount;
}

// Assignment Operator
Card& Card::operator = (const Card& card)
{
    Card :: operator= (card);
    name = card.name;
    good = card.action;
    action = card.action;
    maxPlayerCount = card.maxPlayerCount;
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
    cout << "Enter Max Player Count ";
    in >> c.maxPlayerCount;
    return in;
}

// Displays the action of a card.
void Card::showAction() {
    cout << "This card's action is: " << getAction() << "\n";
}

// Displays the good of a card.
void Card::showGood() {
    cout << "This card's good is: " << getGood() << "\n";
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

int Card::getMaxPlayerCount() {
    return maxPlayerCount;
}


// Empty Constructor
Hand::Hand() {
    cardsInHand;
    for (int i = 0; i < 6; i++) {
        cardsInHand.push_back(NULL);
    }
}

// Parameterized Constructor
Hand::Hand(vector<Card*> newCardsInHand){
    cardsInHand;
    for (int i = 0; i < 6; i++) {
        cardsInHand.push_back(newCardsInHand.at(i));
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
            cout << "Index " << i << " ";
            details(i);
            cout << endl;
        }
        else{
            cout << "Space " << i << " is empty " << endl;
        }
    }
}

// Returns a card with a given index.
Card* Hand::exchange(int index){
    cout << "You've used the following card for " << getCost(index) << ": \n";
    details(index);
    Card* exchangedCard = cardsInHand[index];
    delete cardsInHand[index];
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

// Returns a card.
Card* Hand::getCard(int index) {
    return cardsInHand[index];
}

// Sets a card.
void Hand::setCard(Card* newCard, int index){
    cardsInHand[index] = newCard;
}

// Re-arranges the array to push cards to the left
void Hand::slideCardsLeft() {
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
            cardsInHand.at(indexBeingReplaced) = cardsInHand.at(indexBeingReplaced+1);
            indexBeingReplaced += 1;
        }
        setCard(NULL, indexBeingReplaced);
    }
    // If no card is missing
    else {
        cout << "All spaces are occupied. No cards to slide to the left" << endl;
        cout << emptyIndex << endl;
    }

}

vector<Card*> Hand::getCards    InHand() {
    return cardsInHand;
}

vector<Card*> Deck::listOfCards = {//list of cards
      new Card("Ancient Phoenix", "Flight", "Move Armies: 5", 2),
      new Card("Ancient Spirit Tree", "Elixers: 3", "Place Armies: 4", 2),
      new Card("Cursed Banshee", "Elixers: 2", "Move Armies: 6", 2),
      new Card("Cursed King", "Elixers: 1", "Place Armies: 3 OR Move Armies: 4", 2),
      new Card("Cursed Tower", "+1 VP Per Flight", "Build City", 2),
      new Card("Dire Eye", "Flight", "Place Armies: 4", 2),
      new Card("Forest Elf", "+1 Army", "Place Armies: 3 OR Move Armies: 2", 2),
      new Card("Forest Pixie", "+1 Army", "Move Armies: 4", 2),
      new Card("Graveyard", "+1 VP Per Cursed", "Place Armies: 2", 2),
      new Card("Night Hydra", "+1 Army", "Move Armies: 5 AND Destroy Army", 2),
      new Card("Night Wizard", "+1 VP Per Night", "Place Armies: 3 AND Destroy Army", 2),
      new Card("Noble Knight", "+1 Move", "Place Armies: 4 AND Destroy Ar,u", 2),
      new Card("Stronghold", "+1 VP Per Dire", "Build City", 2),
      new Card("Ancient Sage", "+1 VP Per Ancient", "Move Armies: 3", 2),
      new Card("Ancient Woods", "+1 Army", "Build City AND Place Armies: 1", 2),
      new Card("Cursed Gargoyles", "Flight", "Move Armies: 5", 2),
      new Card("Cursed Mausoleum", "+1 Move", "Build City", 2),
      new Card("Dire Dragon", "Flight", "Place Armies: 3 AND Destroy Army", 2),
      new Card("Dire Giant", "Immune to Attack", "Place Armies: 3 AND Destroy Army", 2),
      new Card("Dire Ogre", "+1 VP Per 3 Coins", "Move Armies: 2", 2),
      new Card("Forest Gnome", "Elixers: 3", "Move Armies: 2", 2),
      new Card("Forest Tree Town", "+1 Move", "Build City", 2),
      new Card("Lake", "+1 VP Per Forest", "Place Armies: 2 OR Move Armies: 3", 2),
      new Card("Night Village", "+1 Army", "Build City", 2),
      new Card("Noble Hills", "3 Noble cards = 4VP", "Place Armies: 3", 2),
      new Card("Noble Unicorn", "+1 Move", "Move Armies: 4 AND Place Armies: 1", 2),
      new Card("Arcane Manticore", "+1 Move", "Place Armies: 4 AND Destroy Army", 3),
      new Card("Arcane Sphinx", "Flight", "Place Armies: 3 OR Move Armies: 4", 3),
      new Card("Arcane Temple", "+1 VP Per Arcane", "Move Armies: 3", 3),
      new Card("Mountain Dwarf", "2 Mountain = 3VP", "Place Armies: 2 AND Destroy Army", 3),
      new Card("Mountain Treasury", "Elixers: 1 AND Coins: 2", "Move Armies: 3", 3),
      new Card("Castle", "Elixers: 1", "Place Armies: 3 OR Build City", 4),
      new Card("Castle 2", "Elixers: 1", "Move Armies: 3 AND Build City", 4),

};

// Empty Constructor
Deck::Deck() {
    
}

// Parameterized constructor
Deck::Deck(vector<Card*> cardList) {
    listOfCards = cardList;
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
    int emptyIndex = -1;
    for (int i = 0; i < 6; i++) {
        if (aHand->getCard(i) == NULL) {
            emptyIndex = i;
            break;
        }
    }
    if (emptyIndex == -1) {
        cout << "No space for new cards in hand. \n";
    }
    else {
        aHand->setCard(getTopCard(), emptyIndex);
    }
}

void Deck::fillHand(Hand* aHand) {
    for (int i = 0; i < 6; i++) {
        if (aHand->getCard(i) == NULL) {
            aHand->setCard(getTopCard(), i);
        }
    }
}

void Deck::filterDeck(int playerCount) {
    std::vector<Card*> resultListOfCards;
    for (auto& c : listOfCards) {
        if (c->getMaxPlayerCount() <= playerCount) {
            resultListOfCards.push_back(c);
        }
    }
    listOfCards = resultListOfCards;
}

void Deck::shuffleDeck() {
    std::srand(std::time(0));
    std::random_shuffle(std::begin(listOfCards), std::end(listOfCards) );
}


#endif CARD_CPP