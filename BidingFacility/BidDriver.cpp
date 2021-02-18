#include "Bid.h"
#include <vector>
// #include "../Player/Player.h"
// using namespace std;

int main()
{

    cout << "Start:" << endl;
    vector<Bid> Bids;
    Bid *b1 = new Bid("John", "King");
    Bids.push_back(*b1);
    Bid *b2 = new Bid("Jay", "Zee");
    Bids.push_back(*b2);

    b1->Bid::pickUpCoins();
    b2->Bid::pickUpCoins();
    b1->Bid::bidCoins();
    b1->Bid::putCoins();

    cout << "End:" << endl;
    return 0;
}