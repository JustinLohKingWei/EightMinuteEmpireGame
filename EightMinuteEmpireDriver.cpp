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

    //initialize cards, deck and hand
    vector<Card*>cardList;
    Card* card1 = new Card("Ancient Phoenix", "Flight", "Move Armies: 5");
    cardList.push_back(card1);
    Card* card2 = new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3");
    cardList.push_back(card2);
    Card* card3 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    cardList.push_back(card3);
    Card* card4 = new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1");
    cardList.push_back(card4);
    Card* card5 = new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City");
    cardList.push_back(card5);
    Card* card6 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    cardList.push_back(card6);
    Card* card7 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    cardList.push_back(card7);
    Card* card8 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    cardList.push_back(card8);

    int numOfCardsInHand = 0;

    cin >> playernum;
<<<<<<< Updated upstream
    vector<Player> players;
=======
    vector<Player*> players;
    //Determine num of cards for each player
    if (playernum == 2) {
        numOfCardsInHand = 2;
    }
    else {
        numOfCardsInHand = 1;
    }

    
>>>>>>> Stashed changes
    for (int i = 0; i < playernum; i++) {
        cout << "Please enter first name" << endl;
        cin >> first;
        cout << "Please enter last name" << endl;
        cin >> last;
<<<<<<< Updated upstream
        fName = &first;
        lName = &last;
        Player aPlayer = Player(*fName, *lName);
=======
        fName = string(first);
        lName = string(last);

        //Distribute cards to each player
        //
        Player* aPlayer = new Player(fName, lName);
>>>>>>> Stashed changes
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

        ////Map init//
        //string *map1 = new string("UserMaps/ValidRectangle.txt");
        //MapLoader ml1 = MapLoader(map1);
        //delete map1;
        //map1 = NULL;
        ////map init
}