
#include "Bid.h"
// #include "../Player/Player.h"
// using namespace std;

int main()
{

    cout << "Start:" << endl;
    Bid *b1 = new Bid("John", "King");
    Bid *b2 = new Bid("Jay", "Zee");
    b1->Bid::pickUpCoins();
    b2->Bid::pickUpCoins();
    b1->Bid::bidCoins();
    b1->Bid::putCoins()

        // vector<string> test{"John", "Zee", "Harry", "Bob", "Babk", "Bac"};
        // vector<Player> players;
        // Player *p = new Player();

        // Bid b(players);
        // std ::cout << " Biggest name is :" << b.findLastNameOrder(b.getPlayers()) << endl;
        cout
        << "End:" << endl;
    return 0;
}