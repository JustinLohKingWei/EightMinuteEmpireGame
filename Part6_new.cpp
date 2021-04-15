//#define MY_DEBUG // uncomment for memory leak detection

#ifdef MY_DEBUG // THIS WAS IN LAB!
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#endif

#include <iostream>

#include "Card/Card.h"
#include "Map/Map.h"
#include "Player/Player.h"
#include "VictoryPoints/VictoryPoints.h"

using namespace std;

int main() {

	#ifdef MY_DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	auto* tile1 = new game_map("C Shape Island");
	cout << "\nC Shape Island map tile has been created." << endl;

	for (auto i = 0; i < 5; ++i)
	{
		string s = "C Shape Island Region " + to_string(i + 1);

		if (i == 1)
		{
			tile1->add_connection_region(s, BOTTOM);
		}
		else if (i == 2)
		{

			tile1->add_connection_region(s, RIGHT);
		}
		else if (i == 3)
		{
			tile1->add_connection_region(s, LEFT);
		}
		else if (i == 4)
		{
			tile1->add_connection_region(s, TOP);
		}
		else
		{
			tile1->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

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

	auto* tile2 = new game_map("Three Islands");
	cout << "\n\nThree Islands map tile has been created." << endl;

	for (auto i = 0; i < 3; ++i)
	{
		string s = "Three Islands Region " + to_string(i + 1);
		if (i == 1)
		{
			tile2->add_connection_region(s, BOTTOM);
			tile2->add_connection_region(s, RIGHT);
		}
		else if (i == 2)
		{
			tile2->add_connection_region(s, TOP);
			tile2->add_connection_region(s, LEFT);
		}
		else
		{
			tile2->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	tile2->add_route("Three Islands Region 1", "Three Islands Region 2");
	tile2->add_route("Three Islands Region 2", "Three Islands Region 1");
	tile2->add_route("Three Islands Region 2", "Three Islands Region 3");
	tile2->add_route("Three Islands Region 3", "Three Islands Region 2");

	auto* tile3 = new game_map("Stone Pillars Island");
	cout << "\n\nStone Pillars Island map tile has been created." << endl;

	for (auto i = 0; i < 5; ++i)
	{
		string s = "Stone Pillars Island Region " + to_string(i + 1);

		if (i == 1)
		{
			tile3->add_connection_region(s, BOTTOM);
		}
		else if (i == 2)
		{

			tile3->add_connection_region(s, LEFT);
		}
		else if (i == 3)
		{
			tile3->add_connection_region(s, RIGHT);
		}
		else if (i == 5)
		{
			tile3->add_connection_region(s, TOP);
		}
		else
		{
			tile3->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	tile3->add_route("Stone Pillars Island Region 1", "Stone Pillars Island Region 2");
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 1");
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 3");
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 4");
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 2");
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 4");
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 5");
	tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 2");
	tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 5");
	tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 3");
	tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 4");

	auto* tile4 = new game_map("Volcano Island");
	cout << "\n\nVolcano Island Island map tile has been created." << endl;

	for (auto i = 0; i < 7; ++i)
	{
		string s = "Volcano Island Region " + to_string(i + 1);

		if (i == 1)
		{
			tile4->add_connection_region(s, BOTTOM);
		}
		else if (i == 2)
		{

			tile4->add_connection_region(s, LEFT);
		}
		else if (i == 4)
		{
			tile4->add_connection_region(s, RIGHT);
		}
		else if (i == 7)
		{
			tile4->add_connection_region(s, TOP);
		}
		else
		{
			tile4->add_region(s);
		}
	}

	tile4->add_route("Volcano Island Region 1", "Volcano Island Region 2");
	tile4->add_route("Volcano Island Region 2", "Volcano Island Region 1");
	tile4->add_route("Volcano Island Region 2", "Volcano Island Region 3");
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 2");
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 4");
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 5");
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 5");
	tile4->add_route("Volcano Island Region 4", "Volcano Island Region 3");
	tile4->add_route("Volcano Island Region 4", "Volcano Island Region 5");
	tile4->add_route("Volcano Island Region 5", "Volcano Island Region 3");
	tile4->add_route("Volcano Island Region 5", "Volcano Island Region 4");
	tile4->add_route("Volcano Island Region 6", "Volcano Island Region 3");
	tile4->add_route("Volcano Island Region 6", "Volcano Island Region 7");
	tile4->add_route("Volcano Island Region 7", "Volcano Island Region 6");

	auto* world_map = new game_map("Rectangle", tile1, tile2, tile3, tile4);

	//
	
	cout << "This is a demonstration of the score calculation..." << endl;
	cout << "We will start with two players! Bob B and Tod T" << endl;

	vector<Card*> bob_used_cards = {};
	vector<region*> bob_list_of_regions = {};
	vector<Army*> bob_list_of_armies = {};
	vector<City*> bob_list_of_cities = {};
	auto* bob = new Player("Bob", "B", bob_used_cards, bob_list_of_regions, bob_list_of_armies, bob_list_of_cities);

	vector<Card*> tod_used_cards = {};
	vector<region*> tod_list_of_regions = {};
	vector<Army*> tod_list_of_armies = {};
	vector<City*> tod_list_of_cities = {};
	auto* tod = new Player("Tod", "T", tod_used_cards, tod_list_of_regions, tod_list_of_armies, tod_list_of_cities);


	cout << "Looking at the score before everything is setup shows this: " << endl;

	cout << "\n" << " Player " << bob->getFirstName() << " has " << VPCounter::instance()->compute_score(bob, world_map) << " victory points!" << endl;

	// Ran out of time
	// Singleton instance not working as hoped...
	// 
	// Severity	Code	Description	Project	File	Line	Suppression State
	// Error	LNK2001	unresolved external symbol "private: static class VPCounter * VPCounter::s_instance" (? s_instance@VPCounter@@0PEAV1@EA)	VP	C : \Users\Alex\source\repos\JustinLohKingWei\EightMinuteEmpireGame\VictoryPoints\Part6.obj	1
	//
	// Severity	Code	Description	Project	File	Line	Suppression State
	// Error	LNK1120	1 unresolved externals	VP	C : \Users\Alex\source\repos\JustinLohKingWei\EightMinuteEmpireGame\VictoryPoints\x64\Debug\VP.exe	1
	//
	// Not enough time to change, great sadness! Alex S

	

	
	#ifdef MY_DEBUG
	_CrtDumpMemoryLeaks(); // call before exit if debug is enabled
	#endif
	return 0;
}