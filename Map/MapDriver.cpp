#define MY_DEBUG // uncomment for memory leak dectetion

// partially from microsoft docs-> compile by using: cl /EHsc /W4 /D_DEBUG /MDd source.cpp
// mostly from TA's extra slides and adapted to assignment for memory debug
#ifdef MY_DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#endif

#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
#ifdef MY_DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    game_map *tile1 = new game_map("C Shape Island");
    (*tile1).populateTile("C Shape Island");

    game_map *tile2 = new game_map("Three Islands");
    (*tile2).populateTile("Three Islands");

    game_map *tile3 = new game_map("Stone Pillars Island");
    (*tile3).populateTile("Stone Pillars Islands");

    game_map *tile4 = new game_map("Valcano Island");
    (*tile4).populateTile("Stone Pillars Islands");

    game_map *world_map = new game_map(tile1, tile2, tile3, tile4);

    // connect the Islands
    world_map->add_route("C Shape Island Region 2", "Three Islands Region 2");
    world_map->add_route("Three Islands Region 2", "C Shape Island Region 2");
    world_map->add_route("C Shape Island Region 4", "Valcano Island Region 4");
    world_map->add_route("Valcano Island Region 4", "C Shape Island Region 4");
    world_map->add_route("C Shape Island Region 3", "Stone Pillars Island Region 3");
    world_map->add_route("Stone Pillars Island Region 3", "C Shape Island Region 3");

    world_map->print_map();
    world_map->print_map_adjacency();

    game_map::vaildate_map(world_map);

    delete world_map;
    delete tile4;
    delete tile3;
    delete tile2;
    delete tile1;

    _CrtDumpMemoryLeaks(); // call before exit if debug is enabled
    return 0;
}