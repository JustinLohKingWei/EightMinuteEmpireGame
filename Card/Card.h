#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <deque>

class Card {
    public:
        Card(std::string theName, std::string theGood, std::string theAction);
        void action();
        void good();
        std::string getName();
        std::string getGood();
        std::string getAction();

    private:
        std::string name;
        std::string good;
        std::string action;
        int coinCost;
};

class Deck {
    public:
        Deck(deque<Card*> listOfCards);
        void draw(Hand *hand)
        Card* getTopCard();
        deque<Card*> getListOfCards();

    private:
        deque<Card*> listOfCards;
};

class Hand {
    public:
        Hand(Card* newCardsInHand[]);
        void viewHand();
        void exchange(int index);
        void details(int index);
        void setCard(Card* newCard, int index);
        int getCost(int index);
    private:
        Card* cardsInHand[6];
};

#endif //CARD_H
