#include "Bid.h"
#include <vector>
#include <string>
// #include "../Player/Player.h"
// using namespace std;

int main()
{

    cout << "Start:" << endl;
    vector<Bid> Bids;
    string firstName1 = "John";
    string lastName1 = "King";
    string firstName2 = "Jay";
    string lastName2 = "Zee";
    Bid *b1 = new Bid(&firstName1, &lastName1);
    Bids.push_back(*b1);
    Bid *b2 = new Bid(&firstName2, &lastName2);
    Bids.push_back(*b2);

    b1->Bid::pickUpCoins();
    b2->Bid::pickUpCoins();
    b1->Bid::bidCoins();
    b1->Bid::putCoins();

    cout << "End:" << endl;
    return 0;
}