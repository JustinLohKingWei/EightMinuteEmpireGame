
#ifndef BID_H
#define BID_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Bid
{

private:
    static int numberOfPlayers;                  
    static int copperPile;                       //shared copper coin supply among all players
    static int silverPile;                       //shared silver coin supply among all players
    int copperCoins;                             // amount of copper coins that a player has
    int silverCoins;                             //amount of silver coins that a player has/
    int bidAmount;                               // point weightage of all the coins a player has , silver coin is 3 points ,copper is 1
    string playerFirstName;
    string playerLastName;

public:
    Bid();
    Bid(string FirstName, string LastName);
    Bid(const Bid &b1);
    ~Bid() {}                                       //destructor
    Bid& operator = (const Bid &bid);
    friend ostream& operator << (ostream& out, const Bid& b);
    friend istream& operator >> (istream& in, Bid& b);
    void pickUpCoins();
    void bidCoins();
    void putCoins();
    void displayBid();
    void payCoins(int payableAmount, char type);
    int getBidAmount();
    int getCopperCoins();
    int getSilverCoins();
};
#endif