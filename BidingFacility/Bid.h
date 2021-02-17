#pragma once

#ifndef BID_H
#define BID_H
#include <vector>
#include <string>
#include "../Player/Player.h"
#include <iostream>
using namespace std;

class Bid
{

private:
    vector<Player> players;
    int coins[];

public:
    Bid();
    // Bid(vector<Player> playerInput);
    void bidCoins();
    bool comparator(string a, string b)
    {
        return a > b;
    };
    vector<string> getPlayers() { return players; };
    string findLastNameOrder();
};
#endif