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
    // Card Shuffling and filling of deck.
    Deck* deck = new Deck;
    deck->filterDeck(playernum);
    deck->shuffleDeck();
    Hand* hand = new Hand;
    deck->fillHand(hand);

    cout << "Main Game Loop Begins" << endl;

        for (int i = 0; i < players.size(); i++) {
            cout << "Player " << i << " :" << (*players.at(i)).getFirstName() << "'s turn" << endl;
            bool payCoin= false;
            int cardPosition = -1;
            cout << "This is the current hand: " << endl;
            hand->viewHand();
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
        }  
    
	return 0;
}