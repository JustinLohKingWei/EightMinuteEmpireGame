
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
    static int copperPile;
    static int silverPile;
    int copperCoins;
    int silverCoins;
    int bidAmount; // amount in a bid object which will be assignned to a player
    string playerFirstName;
    string playerLastName;

public:
    Bid();
    Bid(string FirstName, string LastName);
    Bid(const Bid &b1);
    void pickUpCoins();
    void bidCoins();
    void putCoins();
    void displayBid();
    int getBidAmount();
};
#endif