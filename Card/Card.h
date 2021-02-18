#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <deque>

class Card {
    public:
        Card(std::string theGood, std::string theAction);
        Card( );
        void action();
        void good();
        std::string getGood();
        std::string getAction();

    private:
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
        Hand(array<Card*, 6> newCardsInHand);
        void viewHand();
        void exchange(int index);
        void details(int index);
        void setCard(Card* newCard);
        Card* getCard(int index);
        int getCost(int index);
    private:
        array<Card*, 6> cardsInHand;
};

#endif //CARD_H
