#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"
#include "Map/Map.h"
#include "MapLoader/MapLoader.h"

using namespace std;

int main()
{

    cout << "Start Game:" << endl;

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
        vector<region*>listOfRegions;

        Player* aPlayer = new Player(fName, lName, nullptr, listOfRegions, nullptr, nullptr);//Creating player
        players.push_back(aPlayer);
    }
    // Creating new deck
    Deck* deck = new Deck;
    deck->filterDeck(playernum);
    deck->shuffleDeck();
    Hand* hand = new Hand;
    deck->fillHand(hand);
    hand->viewHand(); 
    //Testing if each player have the right amount of cards 
    /*for (int i = 0; i < players.size(); i++) {
        for (int j = 0; j < players.at(i)->getHand().size(); j++) {
            cout << "============================="<< endl;
            cout << players.at(i)->getHand().at(j)->getName() << endl;
            players.at(i)->getHand().at(j)->showAction();
            players.at(i)->getHand().at(j)->getGood();
        }
    }*/

    for (int i = 0; i < players.size(); i++) {
        (*(*players.at(i)).getBidingFacility()).pickUpCoins();
    }

    for (int i = 0; i < players.size(); i++) {
        (*(*players.at(i)).getBidingFacility()).bidCoins();
    }

    Player winner;
    int winnerAmount = 0;
    for (int i = 0; i < players.size(); i++) {
        (*(*players.at(i)).getBidingFacility()).displayBid();
        if (winnerAmount< (*(*players.at(i)).getBidingFacility()).getBidAmount()) {
            winner = *players.at(i);
            winnerAmount = (*(*players.at(i)).getBidingFacility()).getBidAmount();
        }

        if (winnerAmount == (*(*players.at(i)).getBidingFacility()).getBidAmount()) {
            string a = winner.getLastName();
            string b = (*players.at(i)).getLastName();
            if (a>b) {
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

    cout << "Winner is "<< winner.getFirstName()<<" With Bidding Amount :"<< winnerAmount << endl;
    winner.getBidingFacility()->putCoins();


    // Map Initialization

    MapLoader* ml1(new MapLoader(string("../../../../Documents/GitHub/EightMinuteEmpireGame/MapLoader/UserMaps/ValidRectangle.txt")));  // may need editing per device
    cout << *ml1 << endl;
    delete ml1;


    //TODO
    //(b)create the two players with the implemented exchange () method that allows the player to select the card from its position 
    //    in the row and pay the coin cost listed at the top of the board (see the game rules for details);/
    //(d) assign biding facility to each player;
    //(e) create a deck of cards; and (f) create the game armies, token and cities.
}


