#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"
#include "Card/Card.h"

int main() {
	//TODO : Implement Driver of Part 2

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


    // Bidding process begins
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

    // Card Shuffling and filling of deck.
    Deck* deck = new Deck;
    deck->filterDeck(playernum);
    deck->shuffleDeck();
    Hand* hand = new Hand;
    deck->fillHand(hand);
    hand->viewHand();


	return 0;
}