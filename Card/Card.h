#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <deque>

class Card {
    public:
        Card(std::string theName, std::string theGood, std::string theAction);
        void showAction();
        void showGood();
        std::string getName();
        std::string getGood();
        std::string getAction();

    private:
        std::string name;
        std::string good;
        std::string action;
        int coinCost;
};

class Hand {
    public:
        Hand(Card* newCardsInHand[]);
        void viewHand();
        Card* exchange(int index);
        void details(int index);
        void setCard(Card* newCard, int index);
        Card* getCard(int index);
        int getCost(int index);
    private:
        Card* cardsInHand[6];
};

class Deck {
public:
    Deck(std::deque<Card*> listOfCards);
    void draw(Hand* aHand);
    Card* getTopCard();
    std::deque<Card*> getListOfCards();

private:
    std::deque<Card*> listOfCards;
};

#endif //CARD_H
