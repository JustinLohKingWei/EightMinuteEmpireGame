
#ifndef BID_CPP
#define BID_CPP

#include <vector>
#include <string>
#include "Bid.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;
using std::string;

Bid::Bid()
{
    cout << "Ha" << endl;
}

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
string Bid::findLastNameOrder(vector<string> playerInput)
{
    string winner = playerInput.at(0);
    for (int i = 1; i < playerInput.size(); i++)
    {
        if (comparator(winner, playerInput.at(i)))
        {
            winner = playerInput.at(i);
        }
    }
    return winner;
}

#endif
