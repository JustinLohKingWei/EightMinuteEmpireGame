#include "Card.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
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
    for (int i = 0; i<5; i++){
        if (getCard(i) != NULL){
            cout << "Index " << i << " ";
            details(i);
            cout << endl;
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

// Returns a card.
Card* Hand::getCard(int index) {
    return cardsInHand[index];
}

// Sets a card.
void Hand::setCard(Card* newCard, int index){
    cardsInHand[index] = newCard;
}

vector<Card*> Deck::listOfCards = {//list of cards
      new Card("Ancient Phoenix", "Flight", "Move Armies: 5", 2),
      new Card("Ancient Spirit Tree", "Flight", "Move Armies: 5", 2),
      new Card("Cursed Banshee", "Flight", "Move Armies: 5", 2),
      new Card("Cursed King", "Flight", "Move Armies: 5", 2),
      new Card("Cursed Tower", "Flight", "Move Armies: 5", 2),
      new Card("Dire Eye", "Flight", "Move Armies: 5", 2),
      new Card("Forest Elf", "Flight", "Move Armies: 5", 2),
      new Card("Forest Goblin", "Flight", "Move Armies: 5", 2),
      new Card("Graveyard", "Flight", "Move Armies: 5", 2),
      new Card("Night Hydra", "Flight", "Move Armies: 5", 2),
      new Card("Night Wizard", "Flight", "Move Armies: 5", 2),
      new Card("Noble Knight", "Flight", "Move Armies: 5", 2),
      new Card("Stronghold", "Flight", "Move Armies: 5", 2),
      new Card("Ancient Sage", "Flight", "Move Armies: 5", 2),
      new Card("Ancient Woods", "Flight", "Move Armies: 5", 2),
      new Card("Cursed Gargoyles", "Flight", "Move Armies: 5", 2),
      new Card("Cursed Mausoleum", "Flight", "Move Armies: 5", 2),
      new Card("Dire Dragon", "Flight", "Move Armies: 5", 2),
      new Card("Dire Giant", "Flight", "Move Armies: 5", 2),
      new Card("Dire Ogre", "Flight", "Move Armies: 5", 2),
      new Card("Forest Gnome", "Flight", "Move Armies: 5", 2),
      new Card("Forest Tree Town", "Flight", "Move Armies: 5", 2),
      new Card("Lake", "Flight", "Move Armies: 5", 2),
      new Card("Night Village", "Flight", "Move Armies: 5", 2),
      new Card("Noble Hills", "Flight", "Move Armies: 5", 2),
      new Card("Noble Unicorn", "Flight", "Move Armies: 5", 2),
      new Card("Arcane Manticore", "Flight", "Move Armies: 5", 3),
      new Card("Arcane Sphinx", "Flight", "Move Armies: 5", 3),
      new Card("Arcane Temple", "Flight", "Move Armies: 5", 3),
      new Card("Mountain Dwarf", "Flight", "Move Armies: 5", 3),
      new Card("Mountain Treasury", "Flight", "Move Armies: 5", 3),
      new Card("Castle", "Flight", "Move Armies: 5", 4),
      new Card("Castle 2", "Flight", "Move Armies: 5", 4),

};

// Empty Constructor
Deck::Deck() {

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
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(std::begin(listOfCards), std::end(listOfCards), g );
}
