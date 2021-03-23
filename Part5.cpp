#include "../EightMinuteEmpireGame/Card/Card.h"

int main()
{

    cout << "Start:" << endl;

    // Create some cards.
    Card* card1 = new Card("Ancient Phoenix", "Flight", "Move Armies: 5");
    Card* card2 = new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3");
    Card* card3 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    Card* card4 = new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1");
    Card* card5 = new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City");
    Card* card6 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    Card* card7 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    Card* card8 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");

    Card* initialCardsInHand[6] = { card1, card2, card3, card4, card5, card6 };

    // Create the hand object, which is used by all players.
    Hand* hand = new Hand(initialCardsInHand);
    cout << "Initial Hand:\n";
    for (int i = 0; i < 6; i++) {
        cout << "Details of Hand Position " << i << "\n";
        hand->Hand::details(i);
    }
    cout << "\n\n\n" << endl;

    // Create deck object
    vector<Card*> cardList = { card1, card2, card3, card4,card5,card6,card7, card8 };
    Deck* deck = new Deck(cardList);

    bool wrongInput = true;
    int chosenIndex = -1;
    cout << "Choose an index from which to take a card:" << endl;

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
    hand->exchange(chosenIndex);

    cout << "\n\nSLIDING CARDS TO THE LEFT" << endl;
  

    hand->slideCardsLeft();
    hand->viewHand();

    cout << "\n\nAFTER SLIDING\n\nDraw new card and place on top" << endl;

    // Draw a new card and place it in the right-most space
    hand->setCard(deck->getTopCard(),5);
    hand->viewHand();
    return 0;
}


