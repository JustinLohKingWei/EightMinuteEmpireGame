
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

//since requirements did not specify the initial amount of silver and copper coins respectively at game start
//we shall assume the ratio of silver to copper is 1:2 from 36 coins.
int Bid::copperPile = 24;              
int Bid::silverPile = 12;

// Empty constructor
Bid::Bid()
{
    copperCoins = 0;
    silverCoins = 0;
    bidAmount = 0;
    numberOfPlayers++;
    cout << "a nameless player is created!" << endl;
}


// Parameterized constructor
Bid::Bid(string FirstName, string LastName) : playerFirstName(FirstName), playerLastName(LastName)
{
    copperCoins = 0;
    silverCoins = 0;
    bidAmount = 0;
    numberOfPlayers++;
    cout << "A new player is created!" << endl;
    cout << "Player Name: " << playerFirstName << endl;
}

// copy constructor
Bid::Bid(const Bid& b1)
{
    playerFirstName = b1.playerFirstName;
    playerLastName = b1.playerLastName;
    copperCoins = b1.copperCoins;
    silverCoins = b1.silverCoins;
    bidAmount = b1.bidAmount;
    numberOfPlayers++;
    cout << "A copied player is created!" << endl;
    cout << "Player Name: " << playerFirstName << endl;
}

// Assignment Operator
Bid& Bid::operator = (const Bid& bid)
{
    Bid :: operator= (bid);
    playerFirstName = bid.playerFirstName;
    playerLastName = bid.playerLastName;
    copperCoins = bid.copperCoins;
    silverCoins = bid.silverCoins;
    bidAmount = bid.bidAmount;
    return *this;
}

// Stream output Operator
ostream& operator << (ostream& out, const Bid& b)
{
    out << "Player "<<b.playerFirstName<<" "<<b.playerLastName<<" has "<<b.silverCoins<<" silver coins and "<<b.copperCoins<<". They have bidded a total of "<<b.bidAmount<<". No of players:"<<b.numberOfPlayers <<endl;
    return out;
}

// Stream input operator
istream& operator >> (istream& in, Bid& b)
{
    cout << "Enter First name ";
    in >> b.playerFirstName;
    cout << "Enter Last name ";
    in >> b.playerLastName;
    return in;
}

// Method to prompt a player to pick up coins based on the amount of players playing
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

//Method to allow a player to bid an amount of coins based on the coins they have 
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

//returns ALL the player coins to the main coin supply
void Bid::putCoins()
{
    cout << playerFirstName << " has returned all their coins" << endl;
    silverPile = silverPile + silverCoins;
    copperPile = copperPile + copperCoins;
    silverCoins = 0;
    copperCoins = 0;
    cout <<  "Remaining silver coins in supply : "<<silverPile << " Remaining copper coins in supply : " << copperPile << endl;

}

//Display the amount of points a player has bidded based on the coins they have
void Bid::displayBid()
{
    cout << Bid::playerFirstName << " has bidded :" << Bid::bidAmount << " coin points" << endl;
}

//getter for bid amount
int Bid::getBidAmount()
{
    return  bidAmount;
}
#endif
