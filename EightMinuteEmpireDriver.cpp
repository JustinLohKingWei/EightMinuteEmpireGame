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
    string* fName;
    string* lName;
    string first, last;
    cin >> playernum;
    vector<Player> players;
    for (int i = 0; i < playernum; i++) {
        cout << "Please enter first name" << endl;
        cin >> first;
        cout << "Please enter last name" << endl;
        cin >> last;
        fName = &first;
        lName = &last;
        Player aPlayer = Player(*fName, *lName);
        players.push_back(aPlayer);
    }

    for (int i = 0; i < players.size(); i++) {
        players.at(i).getBidingFacility().pickUpCoins();
    }

    for (int i = 0; i < players.size(); i++) {
        players.at(i).getBidingFacility().bidCoins();
    }

    /*for (int i = 0; i < players.size(); i++) {

    }*/

    

        ////card init
        //// xxxx
        ////card init

    // Map Initialization

    MapLoader ml1(new MapLoader("/MapLoader/UserMaps/ValidRectangle.txt"));
    delete ml1;

}