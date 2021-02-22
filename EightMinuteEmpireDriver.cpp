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
    vector<Card*>listOfCards = {
         new Card("Ancient Phoenix", "Flight", "Move Armies: 5"),
         new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3"),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2"),
         new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1"),
         new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City"),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2"),
         new Card("Ancient Phoenix", "Flight", "Move Armies: 5"),
         new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3"),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2"),
         new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1"),
         new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City"),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2"),
         new Card("Ancient Phoenix", "Flight", "Move Armies: 5"),
         new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3"),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2"),
         new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1"),
         new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City"),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2")
    };
    int cardsInEachHand = 0;
    if (playernum == 2) {
        cardsInEachHand = 4;
    }
    else {
        cardsInEachHand = 2;
    }
    //int currentIndex = 0;

    for (int i = 0; i < playernum; i++) {
        cout << "Please enter first name" << endl;
        cin >> first;
        cout << "Please enter last name" << endl;
        cin >> last;
        fName = string(first);
        lName = string(last);
        vector<Card*>cardsInHand;
        vector<region*>listOfRegions;
        for (int j = 0; j < listOfCards.size(); j++) {
            if (j >= cardsInEachHand) {
                break;
            }
            cardsInHand.push_back(listOfCards.at(j));
            
        }
        listOfCards.erase(listOfCards.begin(), listOfCards.begin() + cardsInEachHand);
        Player* aPlayer = new Player(fName, lName, cardsInHand, listOfRegions);
        players.push_back(aPlayer);
        
    }
    //Testing if each player have the right amount of cards 
    for (int i = 0; i < players.size(); i++) {
        for (int j = 0; j < players.at(i)->getHand().size(); j++) {
            cout << "============================="<< endl;
            cout << players.at(i)->getHand().at(j)->getName() << endl;
            players.at(i)->getHand().at(j)->showAction();
            players.at(i)->getHand().at(j)->getGood();
        }
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

    // Map Initialization

    MapLoader ml1(new MapLoader("/MapLoader/UserMaps/ValidRectangle.txt"));
    delete ml1;

}

};

