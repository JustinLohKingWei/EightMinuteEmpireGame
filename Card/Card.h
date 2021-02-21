#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include <deque>
using namespace std;

class Card {
    private:
        std::string name;
        std::string good;
        std::string action;

    public:
        Card();
        Card(std::string theName, std::string theGood, std::string theAction);
        Card(const Card& c);
        Card& operator = (const Card& card);
        friend ostream& operator <<(ostream& out, const Card& c);
        friend istream& operator >>(istream& in, Card& c);
        void showAction();
        void showGood();
        std::string getName();
        std::string getGood();
        std::string getAction();
};

class Hand {
    public:
        Hand();
        Hand(Card* newCardsInHand[]);
        Hand(const Hand& h);
        friend ostream& operator << (ostream& out, const Hand& h);
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
        Deck();
        Deck(std::deque<Card*> listOfCards);
        Deck(const Deck& d);
        friend ostream& operator << (ostream& out, const Deck& d);
        void draw(Hand* aHand);
        Card* getTopCard();
        std::deque<Card*> getListOfCards();

    private:
        std::deque<Card*> listOfCards;
    };

#endif //CARD_H
