//#include <iostream>
//#include "Player/Player.h"
//#include "BidingFacility/Bid.h"
//#include "Map/Map.h"
//#include "MapLoader/MapLoader.h"
//
//using namespace std;
//
//int main()
//{
//    cout << "Start Game:" << endl;
//
//    //section where we ask how many players
//    cout << "How many players?" << endl;
//
//    int playernum = 0;
//    string fName;
//    string lName;
//    string first, last;
//    cin >> playernum;
//    vector<Player*> players;		//Vector of players
//    for (int i = 0; i < playernum; i++) {
//        cout << "Please enter first name" << endl;
//        cin >> first;
//        cout << "Please enter last name" << endl;
//        cin >> last;
//        fName = string(first);
//        lName = string(last);
//        fName = string(first);
//        lName = string(last);
//        vector<Card*>cards;
//        vector<region*>listOfRegions;
//        vector<Army*>listOfArmies;
//        vector<City*>listOfCities;
//        Player* aPlayer = new Player(fName, lName, cards, listOfRegions, listOfArmies, listOfCities);//Creating player
//        players.push_back(aPlayer);
//    }
//
//    // Creating Deck and Hand
//    Deck* deck = new Deck;
//    deck->filterDeck(playernum);
//    deck->shuffleDeck();
//    Hand* hand = new Hand;
//    deck->fillHand(hand);
//    hand->viewHand();
//
//    for (int i = 0; i < players.size(); i++) {
//        (*(*players.at(i)).getBidingFacility()).pickUpCoins();
//    }
//
//    for (int i = 0; i < players.size(); i++) {
//        (*(*players.at(i)).getBidingFacility()).bidCoins();
//    }
//
//    Player winner;
//    int winnerAmount = 0;
//    for (int i = 0; i < players.size(); i++) {
//        (*(*players.at(i)).getBidingFacility()).displayBid();
//        if (winnerAmount< (*(*players.at(i)).getBidingFacility()).getBidAmount()) {
//            winner = *players.at(i);
//            winnerAmount = (*(*players.at(i)).getBidingFacility()).getBidAmount();
//        }
//
//        if (winnerAmount == (*(*players.at(i)).getBidingFacility()).getBidAmount()) {
//            string a = winner.getLastName();
//            string b = (*players.at(i)).getLastName();
//            if (a>b) {
//                winner = *players.at(i);
//            }
//        }
//
//    }
//    if (winnerAmount == 0) {
//        winner = *players.at(0);
//        for (int i = 1; i < players.size(); i++) {
//            string a = winner.getLastName();
//            string b = (*players.at(i)).getLastName();
//            if (a > b) {
//                winner = *players.at(i);
//            }
//        }
//    }
//
//    cout << "Winner is "<< winner.getFirstName()<<" With Bidding Amount :"<< winnerAmount << endl;
//    winner.getBidingFacility()->putCoins();
//
//
//    // Map Initialization
//
//    MapLoader* ml1(new MapLoader(string("../../../../Documents/GitHub/EightMinuteEmpireGame/MapLoader/UserMaps/ValidRectangle.txt")));  // may need editing per device
//    cout << *ml1 << endl;
//    delete ml1;
//}
//
//
