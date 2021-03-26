#include <iostream>
#include "Player/Player.h"
#include "BidingFacility/Bid.h"
#include "Card/Card.h"

int main() {
	//TODO : Implement Driver of Part 3
    cout << "Start Game:" << endl;

    //section where we ask how many players
    cout << "How many players?" << endl;

    int playernum = 0;
    string fName;
    string lName;
    string first, last;
    cin >> playernum;
    vector<Player*> players;//Vector of players
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
                    if (cardPosition < 0 || hand->getCard(cardPosition) != NULL || cardPosition > 5) {
                        cout << "Incorrect input, please try again. \n";
                    }
                    else {
                        incorrect = false;
                    }
                } while (incorrect);
                int cost = hand->getCost(i);
                cout << "This card costs: " << cost << endl;
                payCoin = players.at(i)->PayCoin(cost, 'c');       // enter card payment cost here
            }
            Card* selectedCard = hand->exchange(cardPosition);
        }  
    
	return 0;
}