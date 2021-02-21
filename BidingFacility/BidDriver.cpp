#include "Bid.h"
#include <vector>
#include <string>

int main()
{

    cout << "Start:" << endl;
    //some mock names
    string firstName1 = "John";
    string lastName1 = "King";
    string firstName2 = "Jay";
    string lastName2 = "Zee";

    //demonstration of bid creation
    cout << "******Bid Creation Demonstration******\n";
    Bid *b1 = new Bid(firstName1, lastName1);
    Bid *b2 = new Bid(firstName2, lastName2);

    //Demonstration of stream output operator
    cout << "****** Stream Output Demonstration******\n";
    cout << *b1;
    cout << *b2;

    //Demonstration of stream input operator
    cout << "******Stream Input Demonstration******\n";
    cin >> *b2;
    cout << *b2;

    //Demonstration of copy constructor
    cout << "******Copy Constructor Demonstration******\n";
    Bid* b3 = new Bid(*b1);
    cout << *b3;

    // Demonstration of assignment operator
    cout << "******Assignment Operator Demonstration******\n";
    b3 = b2;
    cout << *b3;

    cout << "******Functionality Demonstration******\n";

    //demonstration on picking up coins
    b1->Bid::pickUpCoins();
    b2->Bid::pickUpCoins();

    //demonstration on bidding coins
    b1->Bid::bidCoins();

    //demonstration on putting coins back into supply
    b1->Bid::putCoins();

    cout << "End:" << endl;
    return 0;
}