#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Card {
    private:
        std::string name;
        std::string good;
        std::string action;
        int maxPlayerCount;

    public:
        Card();
        Card(std::string theName, std::string theGood, std::string theAction, int playerCount);
        Card(const Card& c);
        ~Card(){};
        Card& operator = (const Card& card);
        friend ostream& operator <<(ostream& out, const Card& c);
        friend istream& operator >>(istream& in, Card& c);
        void showAction();
        void showGood();
        std::string getName();
        std::string getGood();
        std::string getAction();
        int getMaxPlayerCount();
};

class Hand {
    public:
        Hand();
        Hand(vector<Card*> newCardsInHand);
        Hand(const Hand& h);
        ~Hand();
        friend ostream& operator << (ostream& out, const Hand& h);
        void viewHand();
        Card* exchange(int index);
        void details(int index);
        void setCard(Card* newCard, int index);
        Card* getCard(int index);
        int getCost(int index);
        void slideCardsLeft();
        vector<Card*> getCardsInHand();
    private:
        vector<Card*> cardsInHand;
};

class Deck {
    public:
        Deck();
        Deck(std::vector<Card*> listOfCards);
        Deck(const Deck& d);
        ~Deck();
        friend ostream& operator << (ostream& out, const Deck& d);
        void draw(Hand* aHand);
        void fillHand(Hand* aHand);
        Card* getTopCard();
        std::vector<Card*> getListOfCards();
        void filterDeck(int playerNumber);
        void shuffleDeck();

    private:
        static std::vector<Card*> listOfCards;
    };

