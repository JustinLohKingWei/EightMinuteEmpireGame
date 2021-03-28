//
//#include "Card.h"
//using namespace std;
//// using namespace std;
//
//int main()
//{
//
//    cout << "Start:" << endl;
//
//    // Create some cards.
//    // Card Shuffling and filling of deck.
//    Deck* deck = new Deck;
//    deck->filterDeck(2);
//    deck->shuffleDeck();
//    Hand* hand = new Hand;
//    deck->fillHand(hand);
//    hand->viewHand();
//
//
//    // Create the hand object, which is used by all players.
//    cout << "Initial Hand:\n";
//    hand->viewHand();
//
//    // Exchange function from hand.
//    cout << "Exchanging card 0...  \n";
//    Card* newCard = hand->Hand::exchange(0);
//
//    // Draw function from deck.
//    cout << "Drawing Card...  \n";
//    deck->Deck::draw(hand);
//
//    cout << "New Hand:\n";
//    hand->viewHand();
//
//    // input stream for Card.
//    Card* brandNewCard = new Card("Ancient Phoenix", "Flight", "Move Armies: 5", 4);
//    cout << "Testing Card Insertion: :\n";
//    cin >> *brandNewCard;
//    cout << *brandNewCard;
//
//    cout << "End:" << endl;
//
//    delete brandNewCard;
//    delete newCard;
//    delete deck;
//    delete hand;
//    return 0;
//}