#include "../Player/Player.h"
#include "../BidingFacilty/Bid.h"
#include "../Map/BidMap.h"
//rough sketch

int main()
{

    cout << "Start Game:" << endl;

    //section where we ask how many players
    cout << "How many players?" << endl;
    cin << playernum;
    for (int i : playernum)
    {
        //bid & player init
    }
    //

    //card init
    // xxxx
    //card init

    //Map init//
    string *map1 = new string("UserMaps/ValidRectangle.txt");
    MapLoader ml1 = MapLoader(map1);
    delete map1;
    map1 = NULL;
    //map init
}