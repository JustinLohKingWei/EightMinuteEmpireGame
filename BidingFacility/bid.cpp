#include <iostream>
#include <vector>
#include <string>
using namespace std;

class bid
{
private:
    vector<string> players;
    int coins[];

public:
    bid(vector<string> playerInput)
    {
        std ::cout << "Players who have joined the bidding are : \n"
                   << endl;

        for (int i = 0; i < playerInput.size(); i++)
        {
            players.push_back(playerInput.at(i));
            std ::cout << " Initlializing bidding for :" << players.at(i) << endl;
        }
    }

    void bidCoins()
    {
    }

    //Function returns name with largest alphabetical order
    string findLastNameOrder(vector<string> playerInput)
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
    bool comparator(string a, string b)
    {
        return a > b;
    }

    vector<string> getPlayers()
    {
        return players;
    }
};

int main()
{
    bid b({"John", "Zee", "Harry", "Bob", "Babk", "Bac"});
    std ::cout << " Biggest name is :" << b.findLastNameOrder(b.getPlayers()) << endl;
    return 0;
}
