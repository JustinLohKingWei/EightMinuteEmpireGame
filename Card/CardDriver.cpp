#include "Card.h"
// using namespace std;

int main()
{

    cout << "Start:" << endl;
    Card card1 = new Card("Ancient Phoenix", "Flight", "Move Armies: 5");
    Card card2 = new Card("Arcane Temple", "+1VP per Arcane", "Move Armies: 3");
    Card card3 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    Card card4 = new Card("Night Hydra", "+1 Army", "Move Armies: 5 OR Destroy Army: 1");
    Card card5 = new Card("Castle", "+1 Elixer", "Move Armies: 3 AND Build City");
    Card card6 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    Card card7 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");
    Card card8 = new Card("Forest Elf", "+1 Army", "Place 3 Army OR Move Armies: 2");

    Card* initialCardsInHand[6] = [*card1, *card2, *card3, *card4, *card5, *card6];

    Hand* hand = new Hand(initialCardsInHand);
    hand->details();

    deque<Card*> cardList = [*card7, *card8];
    Deck* deck = newDeck(cardList);

    cout << "End:" << endl;
    return 0;
}