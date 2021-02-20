
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


Bid::Bid(string *FirstName, string *LastName)
{
    copperCoins = 0;
    silverCoins = 0;
    bidAmount = 0;
    playerFirstName = FirstName;
    playerLastName = LastName;
    numberOfPlayers++;
    cout << "A new player is created!" << endl;
    cout << "Player Name: " << *playerFirstName << endl;
}

Bid::Bid(const Bid &b1)
{
    //TODO ADD ALL ATTRIBUTES TO COPY CONSTRUCTOR
}

void Bid::pickUpCoins()
{ //TODO : IMPLEMENT CHECK THAT PLAYERS ARE CHOOSING CORRECT AMOUNT OF COINS
cout << *playerFirstName << " is picking up coins :" << endl;
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
    int x, y;
    cout << "Please enter amount of silver coins to bid :" << Bid::silverCoins << " remaining" << endl;
    cin >> x;
    cout << "Please enter amount of copper coins to bid :" << Bid::copperCoins << " remaining" << endl;
    cin >> y;
    bidAmount = (3 * x) + y;
    cout << Bid::playerFirstName << " has bidded :" << Bid::bidAmount << " coin points" << endl;
}

void Bid::putCoins()
{
    silverPile = silverPile + silverCoins;
    copperPile = copperPile + copperCoins;
    silverCoins = 0;
    copperCoins = 0;
    cout << Bid::playerFirstName << " has returned ALL his coins" << endl;
}

#endif

//Function returns name with largest alphabetical order
// Player Bid::findLastNameOrder(vector<string> playerInput)
// {
//     Player winner = playerInput.at(0);
//     for (int i = 1; i < playerInput.size(); i++)
//     {
//         if (comparator(winner.getName(), playerInput.at(i).getName()))
//         {
//             winner = playerInput.at(i);
//         }
//     }
//     return winner;
// }