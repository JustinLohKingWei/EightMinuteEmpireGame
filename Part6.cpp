#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"
#include "Card/Card.h"

int main() {
    //TODO : Implement Driver of Part 6
    cout << "Start Game:" << endl;

    //section where we ask how many players
    int playernum = 2;
    string fName;
    string lName;
    string first, last;
    vector<Player*> players;//Vector of players
    vector<Card*>listOfCards = {//list of cards
         new Card("Ancient Phoenix", "Flight", "Move Armies: 5", 2),
         new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3", 2),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", 2),
         new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1", 2),
         new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City", 2),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", 2),
         new Card("Ancient Phoenix", "Flight", "Move Armies: 5", 2),
         new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3", 2),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", 2),
         new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1", 2),
         new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City", 2),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", 2),
         new Card("Ancient Phoenix", "Flight", "Move Armies: 5", 2),
         new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3", 2),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", 2),
         new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1", 2),
         new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City", 2),
         new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", 2)
    };
    int cardsInEachHand = 0;
    if (playernum == 2) {
        cardsInEachHand = 4;
    }
    else {
        cardsInEachHand = 2;
    }


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

    cout << "Main Game Loop Begins" << endl;

    Player winner;
    bool hasWinner = false;
    char in;
    while (!hasWinner) {                                     // loops until a winner is selected
        for (int i = 0; i < players.size(); i++) {
            cout << "Player " << i << " :" << (*players.at(i)).getFirstName() << "'s turn" << endl;

            // delete this and implement main game loop here
            cout << "is it time?(enter y for winner)";
            cin >> in;

            if (in == 'y') {                                    // enter win condition here
                hasWinner = true;
                winner = *players.at(i);
                break;
            }
        }
    }
    cout << "Winner is " << winner.getFirstName();
    return 0;
}