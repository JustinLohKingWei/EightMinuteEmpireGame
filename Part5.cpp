#include "../EightMinuteEmpireGame/Player/Player.h"
#include "../EightMinuteEmpireGame/Card/Card.h"
#include "../EightMinuteEmpireGame/Game/Game.h"

#define MY_DEBUG // uncomment for memory leak dectetion

// partially from microsoft docs-> compile by using: cl /EHsc /W4 /D_DEBUG /MDd source.cpp
// mostly from TA's extra slides and adapted to assignment for memory debug
#ifdef MY_DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#endif


int main(){
#ifdef MY_DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    cout << "Start:" << endl;
    // Initialization of players
    vector<Player*> players;
    // Player1
    vector<region*> listOfRegions1;
    vector<Card*> cardsInHand1;
    vector<Army*> listOfArmies1;
    vector<City*> listOfCities1;
    Player* aPlayer1 = new Player("Alpha", "Apple", cardsInHand1, listOfRegions1, listOfArmies1, listOfCities1);


    // Player2
    vector<region*> listOfRegions2;
    vector<Card*> cardsInHand2;
    vector<Army*> listOfArmies2;
    vector<City*> listOfCities2;
    Player* aPlayer2 = new Player("Beta", "Banana", cardsInHand2, listOfRegions2, listOfArmies2, listOfCities2);

    //// Player3
    //vector<region*> listOfRegions3;
    //vector<Card*> cardsInHand3;
    //vector<Army*> listOfArmies3;
    //vector<City*> listOfCities3;
    //Player* aPlayer3 = new Player("Charlie", "Carrot", cardsInHand3, listOfRegions3, listOfArmies3, listOfCities3);

    players.push_back(aPlayer1);
    players.push_back(aPlayer2);
    //players.push_back(aPlayer3);

    
    // Initialization of game
    Game* part5Game = new Game(players);
    int numOfPlayers = part5Game->getNumOfPlayers();


    // Create some cards.
    Card* card1 = new Card("Ancient Phoenix", "Flight", "Move Armies: 5",numOfPlayers);
    Card* card2 = new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3",numOfPlayers);
    Card* card3 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2",numOfPlayers);
    Card* card4 = new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1",numOfPlayers);
    Card* card5 = new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City",numOfPlayers);
    Card* card6 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2",numOfPlayers);
 /*   Card* card7 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2",numOfPlayers);
    Card* card8 = new Card("Ancient Phoenix", "Flight", "Move Armies: 5",numOfPlayers);
    Card* card9 = new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3", numOfPlayers);
    Card* card10 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", numOfPlayers);
    Card* card11 = new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1", numOfPlayers);
    Card* card12 = new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City", numOfPlayers);
    Card* card13 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", numOfPlayers);
    Card* card14 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2", numOfPlayers);*/

    vector<Card*> initialCardsInHand { card1, card2, card3, card4, card5, card6 };

    // Create the hand object, which is used by all players.
    Hand* hand = new Hand(initialCardsInHand);
    cout << "Initial Hand:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Details of Hand Position " << i << "\n";
        hand->Hand::details(i);
    }
    part5Game->setGameHand(hand);
    cout << "\n\n\n" << endl;

    // Create deck object
    //vector<Card*> cardList{ card7, card8, card9, card10,card11,card12,card13, card14};
    Deck* deck = new Deck();


    // Prompt user to choose a card from the hand
    bool wrongInput = true;
    int chosenIndex = -1;
    cout << "Choose an index from which to take a card:" << endl;

    // User entry validation
    while (wrongInput) {
        cin >> chosenIndex;
        if (!cin || chosenIndex > 5 || chosenIndex < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please try again." << endl;
        }
        else {
            wrongInput = false;
        }
        
    }

    cout << "Taking the card in index " << chosenIndex << endl;
    
    (*part5Game->getGameHand()).getCardsInHand().push_back(hand->exchange(chosenIndex));

    cout << "\n\nBEFORE SLIDING CARDS TO THE LEFT\n\n" << endl;

    hand->viewHand();


    cout << "\n\nSLIDING CARDS TO THE LEFT" << endl;
  

    hand->slideCardsLeft();
    hand->viewHand();

    cout << "\n\n\nDRAWING CARD FROM TOP OF DECK" << endl;

    // Draw a new card and place it in the right-most space
    hand->setCard(deck->getTopCard(),5);
    hand->viewHand();


    // Passing the play to the next player
    part5Game->nextPlayer();
    part5Game->nextPlayer();

    delete deck;
    delete hand;
    delete part5Game;
    //delete aPlayer3;
    delete aPlayer2;
    delete aPlayer1;
 
    return 0; 
}


