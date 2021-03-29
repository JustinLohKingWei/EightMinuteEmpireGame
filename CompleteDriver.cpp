#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"
#include "Card/Card.h"

int main() {
    // Part 1

    int playernum = 2;			//2 player game based on instrunctions given
    string fName;
    string lName;
    string first, last;

    vector<Player*> players;		//Vector of players
    for (int i = 0; i < playernum; i++) {
        cout << "Please enter first name" << endl;
        cin >> first;
        cout << "Please enter last name" << endl;
        cin >> last;
        fName = string(first);
        lName = string(last);
        fName = string(first);
        lName = string(last);
        vector<Card*>cards;
        vector<region*>listOfRegions;
        vector<Army*>listOfArmies;
        vector<City*>listOfCities;
        Player* aPlayer = new Player(fName, lName, cards, listOfRegions, listOfArmies, listOfCities);//Creating player
        players.push_back(aPlayer);
    }
    // Card Shuffling and filling of deck.
    Deck* deck = new Deck;
    deck->filterDeck(playernum);
    deck->shuffleDeck();
    Hand* hand = new Hand;
    deck->fillHand(hand);

    // Bidding process begins (Part 2)
    for (int i = 0; i < players.size(); i++) {
        (*(*players.at(i)).getBidingFacility()).pickUpCoins(14);        //each player picks up 14 coins
    }

    for (int i = 0; i < players.size(); i++) {
        (*(*players.at(i)).getBidingFacility()).bidCoins();            //each player bids their coins
    }

    Player winner;
    int winnerAmount = 0;

    // finds winner with largest alphabetical last name
    for (int i = 0; i < players.size(); i++) {
        (*(*players.at(i)).getBidingFacility()).displayBid();
        if (winnerAmount < (*(*players.at(i)).getBidingFacility()).getBidAmount()) {
            winner = *players.at(i);
            winnerAmount = (*(*players.at(i)).getBidingFacility()).getBidAmount();
        }

        if (winnerAmount == (*(*players.at(i)).getBidingFacility()).getBidAmount()) {
            string a = winner.getLastName();
            string b = (*players.at(i)).getLastName();
            if (a > b) {
                winner = *players.at(i);
            }
        }

    }

    // if all players bid 0
    if (winnerAmount == 0) {
        winner = *players.at(0);
        for (int i = 1; i < players.size(); i++) {
            string a = winner.getLastName();
            string b = (*players.at(i)).getLastName();
            if (a > b) {
                winner = *players.at(i);
            }
        }
    }

    cout << "Winner is " << winner.getFirstName() << " With Bidding Amount :" << winnerAmount << endl;
    winner.getBidingFacility()->putCoins();

    cout << "Main Game Loop Begins" << endl; // (Part 3)

    for (int i = 0; i < players.size(); i++) {
        cout << "Player " << i << " :" << (*players.at(i)).getFirstName() << "'s turn" << endl;
        bool payCoin = false;
        int cardPosition = -1;
        cout << "This is the current hand: " << endl;
        hand->viewHand();
        cout << "Index 0-1 Costs 0 coins, 1-2 Costs 1 Coin, 2-3 Costs 2 Coins, 4-5 Costs 3 Coins" << endl;
        while (!payCoin) {                                  // checks if player can pay for the card
            cout << "Please enter the position for the card: ";
            bool incorrect = true;
            do {
                std::cin >> cardPosition;
                if (cardPosition < 0 || hand->getCard(cardPosition) == NULL || cardPosition > 5) {
                    cout << "Incorrect input, please try again. \n";
                }
                else {
                    incorrect = false;
                }
            } while (incorrect);
            int cost = hand->getCost(cardPosition);
            cout << "This card costs: " << cost << endl;
            payCoin = players.at(i)->PayCoin(cost, 'c');       // enter card payment cost here
        }
        Card* selectedCard = hand->exchange(cardPosition);

        // Insert Part 4 Here

        // Part 5
        cout << "\n\nBEFORE SLIDING CARDS TO THE LEFT\n\n" << endl;

        hand->viewHand();


        cout << "\n\nSLIDING CARDS TO THE LEFT" << endl;


        hand->slideCardsLeft();
        hand->viewHand();

        cout << "\n\n\nDRAWING CARD FROM TOP OF DECK" << endl;

        // Draw a new card and place it in the right-most space
        hand->setCard(deck->getTopCard(), 5);
        hand->viewHand();

        // Insert Part 6 Here
    }

    return 0;
}