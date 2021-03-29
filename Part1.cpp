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
        vector<Card*>cards;
        vector<region*>listOfRegions;
        vector<Army*>listOfArmies;
        vector<City*>listOfCities;
        Player* aPlayer = new Player(fName, lName, cards, listOfRegions, listOfArmies, listOfCities);//Creating player
        players.push_back(aPlayer);
    }
    // Creating new deck
    Deck* deck = new Deck;
    deck->filterDeck(playernum);
    deck->shuffleDeck();
    Hand* hand = new Hand;
    deck->fillHand(hand);

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

    //Exchange Method
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
        payCoin = players.at(0)->PayCoin(cost, 'c');       // enter card payment cost here
    }
    Card* selectedCard = hand->exchange(cardPosition);
    deck->draw(hand);

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


