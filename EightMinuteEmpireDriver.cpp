#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"
#include "Map/Map.h"

using namespace std;
//rough sketch

int main()
{

    cout << "Start Game:" << endl;

    //section where we ask how many players
    cout << "How many players?" << endl;

    int playernum = 0;
    string fName;
    string lName;
    string first, last;
    cin >> playernum;
    vector<Player*> players;
    for (int i = 0; i < playernum; i++) {
        cout << "Please enter first name" << endl;
        cin >> first;
        cout << "Please enter last name" << endl;
        cin >> last;
        fName = string(first);
        lName = string(last);
        Player* aPlayer = new Player(fName, lName);
        players.push_back(aPlayer);
    }

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

    cout << "Winner is "<< winner.getFirstName()<<" With Bidding Amount :"<< winnerAmount << endl;
    winner.getBidingFacility()->putCoins();

    ////card init
    //// xxxx
    ////card init

    ////Map init//
    //string *map1 = new string("UserMaps/ValidRectangle.txt");
    //MapLoader ml1 = MapLoader(map1);
    //delete map1;
    //map1 = NULL;
    ////map init
};