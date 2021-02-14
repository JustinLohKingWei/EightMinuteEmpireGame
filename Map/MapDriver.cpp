#define _DEBUG // uncomment for memory leak dectetion

// partially from microsoft docs-> compile by using: cl /EHsc /W4 /D_DEBUG /MDd source.cpp
// mostly from TA's extra slides and adapted to assignment for memory debug
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#endif

#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    game_map* tile1 = new game_map("C Shape Island");
    cout << "\nC Shape Island map tile has been created." << endl;

    // initialize "tile1" the center tile as depected on the first page of the rules
    for (auto i = 0; i < 5; ++i)
    {
        string s = "C Shape Island Region " + to_string(i + 1);
        tile1->add_region(s);
        cout << "\n Added a new area has been added: " << s << "." << endl;
    }

    // edges are initilized left to right, top to bottom, but they can be done in any way
    // edges added in both directions so that they appear in single reagion adjacency lists
    tile1->add_route("C Shape Island Region 1", "C Shape Island Region 2");
    tile1->add_route("C Shape Island Region 2", "C Shape Island Region 1");
    tile1->add_route("C Shape Island Region 2", "C Shape Island Region 3");
    tile1->add_route("C Shape Island Region 2", "C Shape Island Region 5");
    tile1->add_route("C Shape Island Region 3", "C Shape Island Region 2");
    tile1->add_route("C Shape Island Region 3", "C Shape Island Region 4");
    tile1->add_route("C Shape Island Region 4", "C Shape Island Region 3");
    tile1->add_route("C Shape Island Region 4", "C Shape Island Region 5");
    tile1->add_route("C Shape Island Region 5", "C Shape Island Region 4");
    tile1->add_route("C Shape Island Region 5", "C Shape Island Region 2");

    game_map* tile2 = new game_map("Three Islands");
    cout << "\n\nThree Islands map tile has been created." << endl;

    // initialize "tile2" the right tile as depected on the first page of the rules
    for (auto i = 0; i < 3; ++i)
    {
        string s = "Three Islands Region " + to_string(i + 1);
        tile2->add_region(s);
        cout << "\n Added a new area has been added: " << s << "." << endl;
    }

    // edges are initilized left to right, top to bottom, but they can be done in any way
    // edges added in both directions so that they appear in single reagion adjacency lists
    tile2->add_route("Three Islands Region 1", "Three Islands Region 2");
    tile2->add_route("Three Islands Region 2", "Three Islands Region 1");
    tile2->add_route("Three Islands Region 2", "Three Islands Region 3");
    tile2->add_route("Three Islands Region 3", "Three Islands Region 2");

    game_map* tile3 = new game_map("Stone Pillars Island");
    cout << "\n\nStone Pillars Island map tile has been created." << endl;

    // initialize "tile3" the left tile as depected on the first page of the rules
    for (auto i = 0; i < 5; ++i)
    {
        string s = "Stone Pillars Island Region " + to_string(i + 1);
        tile3->add_region(s);
        cout << "\n Added a new area has been added: " << s << "." << endl;
    }

    // edges are initilized left to right, bottom to top, but they can be done in any way
    // edges added in both directions so that they appear in single reagion adjacency lists
    tile3->add_route("Stone Pillars Island Region 1", "Stone Pillars Island Region 2");
    tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 1");
    tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 3"); // 3 is region with houses
    tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 4"); // 4 is region with the pillars
    tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 2");
    tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 4");
    tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 5");
    tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 2");
    tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 4");
    tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 5");
    tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 3");
    tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 4");

    game_map* tile4 = new game_map("Valcano Island");
    cout << "\n\nValcano Island Island map tile has been created." << endl;

    // initialize "tile4" the top tile as depected on the first page of the rules
    for (auto i = 0; i < 7; ++i)
    {
        string s = "Valcano Island Region " + to_string(i + 1);
        tile4->add_region(s);
        cout << "\n Added a new area has been added: " << s << "." << endl;
    }
    
    // edges are initilized left to right, top to bottom, but they can be done in any way
    // edges added in both directions so that they appear in single reagion adjacency lists
    tile4->add_route("Valcano Island Region 1", "Valcano Island Region 2");
    tile4->add_route("Valcano Island Region 2", "Valcano Island Region 1");
    tile4->add_route("Valcano Island Region 2", "Valcano Island Region 3");
    tile4->add_route("Valcano Island Region 3", "Valcano Island Region 2");
    tile4->add_route("Valcano Island Region 3", "Valcano Island Region 4");
    tile4->add_route("Valcano Island Region 3", "Valcano Island Region 5");
    tile4->add_route("Valcano Island Region 3", "Valcano Island Region 5");
    tile4->add_route("Valcano Island Region 4", "Valcano Island Region 3"); // region 4 is the furthest east(or south as it appears in the game manual) region
    tile4->add_route("Valcano Island Region 4", "Valcano Island Region 5");
    tile4->add_route("Valcano Island Region 5", "Valcano Island Region 3");
    tile4->add_route("Valcano Island Region 5", "Valcano Island Region 4");
    tile4->add_route("Valcano Island Region 6", "Valcano Island Region 3"); // region 6 is the bottom region on the disconnected smaller island
    tile4->add_route("Valcano Island Region 6", "Valcano Island Region 7");
    tile4->add_route("Valcano Island Region 7", "Valcano Island Region 6");

    // This is how I would normally like to construct the game map once all tiles are loaded from files and then selected and positioned
    // they could easily be combinded into a "World Map" for game play with little effort and adding the last fewconnections between the Islands
    game_map* world_map = new game_map(tile1, tile2, tile3, tile4);

    // connect the Islands
    world_map->add_route("C Shape Island Region 2", "Three Islands Region 2");
    world_map->add_route("Three Islands Region 2", "C Shape Island Region 2");
    world_map->add_route("C Shape Island Region 4", "Valcano Island Region 4");
    world_map->add_route("Valcano Island Region 4", "C Shape Island Region 4");
    world_map->add_route("C Shape Island Region 3", "Stone Pillars Island Region 3");
    world_map->add_route("Stone Pillars Island Region 3", "C Shape Island Region 3");

    delete world_map;
    delete tile4;
    delete tile3;
    delete tile2;
    delete tile1;

    _CrtDumpMemoryLeaks(); // call before exit if debug is enabled
    return 0;
}