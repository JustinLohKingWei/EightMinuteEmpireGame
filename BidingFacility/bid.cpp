
#ifndef BID_CPP
#define BID_CPP

#include <vector>
#include <string>
#include "Bid.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::string;

int Bid::numberOfPlayers = 0;
int Bid::copperPile = 24;
int Bid::silverPile = 12;

Bid::Bid()
{
    copperCoins = 0;
    silverCoins = 0;
    bidAmount = 0;
    numberOfPlayers++;
    cout << "A new player is created!" << endl;
}


Bid::Bid(string FirstName, string LastName) : playerFirstName(FirstName), playerLastName(LastName)
{
    copperCoins = 0;
    silverCoins = 0;
    bidAmount = 0;
    numberOfPlayers++;
    cout << "A new player is created!" << endl;
    cout << "Player Name: " << playerFirstName << endl;
}

Bid::Bid(const Bid &b1)
{
    //TODO ADD ALL ATTRIBUTES TO COPY CONSTRUCTOR
}

void Bid::pickUpCoins()
{
    cout << playerFirstName << " is picking up coins :" << endl;
    if (numberOfPlayers == 2)
    {
        do
        {
            while ((silverCoins + copperCoins) != 12)
            {
                cout << "Two player game! Each Player selects 12 coins" << endl;
                cout << "Enter amount of Silver coins   :" << Bid::silverPile << " remaining" << endl;
                cin >> silverCoins;
                cout << "Enter amount of Copper coins   :" << Bid::copperPile << " remaining" << endl;
                cin >> copperCoins;
                if ((silverCoins + copperCoins) != 12)
                {
                    cout << "You must select 12 coins! Try again." << endl;
                }
                if (silverCoins > silverPile || copperCoins > copperPile)
                {
                    cout << "Not enough coins in pile. Try again." << endl;
                }
            }
        } while (silverCoins > silverPile || copperCoins > copperPile);

        silverPile = silverPile - silverCoins;
        copperPile = copperPile - copperCoins;
    }
    else if (numberOfPlayers == 3)
    {
        do
        {
            while ((silverCoins + copperCoins) != 11)
            {
                cout << "Three player game! Each Player selects 11 coins" << endl;
                cout << "Enter amount of Silver coins   :" << Bid::silverPile << " remaining" << endl;
                cin >> silverCoins;
                cout << "Enter amount of Copper coins   :" << Bid::copperPile << " remaining" << endl;
                cin >> copperCoins;
                if ((silverCoins + copperCoins) != 11)
                {
                    cout << "You must select 11 coins! Try again." << endl;
                }
                if (silverCoins > silverPile || copperCoins > copperPile)
                {
                    cout << "Not enough coins in pile. Try again." << endl;
                }
            }
        } while (silverCoins > silverPile || copperCoins > copperPile);
        silverPile = silverPile - silverCoins;
        copperPile = copperPile - copperCoins;
    }
    else if (numberOfPlayers == 4)
    {
        do
        {
            while ((silverCoins + copperCoins) != 9)
            {
                cout << "Four player game! Each Player selects 9 coins" << endl;
                cout << "Enter amount of Silver coins   :" << Bid::silverPile << " remaining" << endl;
                cin >> silverCoins;
                cout << "Enter amount of Copper coins   :" << Bid::copperPile << " remaining" << endl;
                cin >> copperCoins;
                if ((silverCoins + copperCoins) != 9)
                {
                    cout << "You must select 9 coins! Try again." << endl;
                }
                if (silverCoins > silverPile || copperCoins > copperPile)
                {
                    cout << "Not enough coins in pile. Try again." << endl;
                }
            }
        } while (silverCoins > silverPile || copperCoins > copperPile);
        silverPile = silverPile - silverCoins;
        copperPile = copperPile - copperCoins;
    }
    else
    {
        cout << "Invalid amount of players detected" << endl;
    }
}

void Bid::bidCoins()
{
    cout << playerFirstName << " is bidding coins :" << endl;
    int x, y;
    do
    {
        cout << "Please enter amount of silver coins to bid :" << Bid::silverCoins << " remaining" << endl;
        cin >> x;
        cout << "Please enter amount of copper coins to bid :" << Bid::copperCoins << " remaining" << endl;
        cin >> y;
        if (x > silverCoins || y > copperCoins)
        {
            cout << "You do not have that many coins!" << endl;
        }
    } while (x > silverCoins || y > copperCoins);
    bidAmount = (3 * x) + y;
}

void Bid::putCoins()
{
    silverPile = silverPile + silverCoins;
    copperPile = copperPile + copperCoins;
    silverCoins = 0;
    copperCoins = 0;
}

void Bid::displayBid()
{
    cout << Bid::playerFirstName << " has bidded :" << Bid::bidAmount << " coin points" << endl;
}


int Bid::getBidAmount()
{
    return  bidAmount;
}
#endif
