#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <vector>

class Card {
    public:
        Card(std::string theGood, std::string theAction, std::string theCost);
        Card( );
        void action();
        void good();
        void cost();
        std::string getGood();
        std::string getAction();
        int getCost();

    private:
        std::string good;
        std::string action;
        int coinCost;
};

class Deck {
public:
    Deck(vector<Card> listOfCards)
    void draw(Hand *hand)

private:
    vector<Card> *listOfCards;
};

class Hand {
public:
    void exchange(int index);
    void details(int index);
private:
    Card[6] *cards;
};

#endif //CARD_H
