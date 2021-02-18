
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

Bid::Bid(string FirstName, string LastName)
{
    copperCoins = 0;
    silverCoins = 0;
    bidAmount = 0;
    playerFirstName = FirstName;
    playerLastName = LastName;
    numberOfPlayers++;
    cout << "A new player is created!" << endl;
    cout << "Player Name: " << Bid::playerFirstName << endl;
}

void Bid::pickUpCoins()
{ //TODO : IMPLEMENT CHECK THAT PLAYERS ARE CHOOSING CORRECT AMOUNT OF COINS
    cout << Bid::playerFirstName << " is picking up coins :" << endl;
    if (numberOfPlayers == 2)
    {
        cout << "Each Player selects 12 coins" << endl;
        cout << "Enter amount of Silver coins   :" << Bid::silverPile << " remaining" << endl;
        cin >> silverCoins;
        silverPile = silverPile - silverCoins;
        cout << "Enter amount of Copper coins   :" << Bid::copperPile << " remaining" << endl;
        cin >> copperCoins;
        copperPile = copperPile - copperCoins;
    }
    else if (numberOfPlayers == 3)
    {
        cout << "Each Player selects 11 coins" << endl;
        cout << "Enter amount of Silver coins   :" << Bid::silverPile << " remaining" << endl;
        cin >> silverCoins;
        silverPile = silverPile - silverCoins;
        cout << "Enter amount of Copper coins   :" << Bid::copperPile << " remaining" << endl;
        cin >> copperCoins;
        copperPile = copperPile - copperCoins;
    }
    else if (numberOfPlayers == 4)
    {
        cout << "Each Player selects 9 coins" << endl;
        cout << "Enter amount of Silver coins   :" << Bid::silverPile << " remaining" << endl;
        cin >> silverCoins;
        silverPile = silverPile - silverCoins;
        cout << "Enter amount of Copper coins   :" << Bid::copperPile << " remaining" << endl;
        cin >> copperCoins;
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

// Bid::Bid(vector<Player> playerInput)
// {
//     // cout << "Players who have joined the bidding are : \n"
//     //      << endl;

//     // for (int i = 0; i < playerInput.size(); i++)
//     // {
//     //     players.push_back(playerInput.at(i));
//     //     cout << " Initlializing bidding for :" << players.at(i) << endl;
//     // }
// }

// Bid::Bid(vector<string> *playerInput)
// {
//     cout << "Players who have joined the bidding are : \n"
//          << endl;

//     for (int i = 0; i < playerInput.size(); i++)
//     {
//         players.push_back(playerInput.at(i));
//         cout << " Initlializing bidding for :" << players.at(i) << endl;
//     }
// }

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