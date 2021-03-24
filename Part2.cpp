#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"

int main() {
	//TODO : Implement Driver of Part 2

	int playernum = 2;			//2 player game based on instrunctions given
    string fName;
    string lName;
    string first, last;

    vector<Card*>listOfCards = {//list of cards
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
	vector<Player*> players;		//Vector of players
    for (int i = 0; i < playernum; i++) {
        cout << "Please enter first name" << endl;
        cin >> first;
        cout << "Please enter last name" << endl;
        cin >> last;
        fName = string(first);
        lName = string(last);
        vector<Card*>cardsInHand;
        vector<region*>listOfRegions;
        for (int j = 0; j < listOfCards.size(); j++) {//Distributing cards
            if (j >= cardsInEachHand) {
                break;
            }
            cardsInHand.push_back(listOfCards.at(j));

        }
        listOfCards.erase(listOfCards.begin(), listOfCards.begin() + cardsInEachHand);
        Player* aPlayer = new Player(fName, lName, cardsInHand, listOfRegions);//Creating player
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




	return 0;
}