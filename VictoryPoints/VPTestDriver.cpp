#include <vector>
#include "VictoryPoints.h"
#include "../Player/Player.h"
#include "../Card/Card.h"
#include "../Map/Map.h"
#include "../MapLoader/MapLoader.h"

using namespace std;

int main()
{
	auto* tile1 = new MapTile("C Shape Island");
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

	// edges are initialized left to right, top to bottom, but they can be done in any way
	// edges added in both directions so that they appear in single region adjacency lists
	tile1->add_route("C Shape Island Region 1", "C Shape Island Region 2", LAND);
	tile1->add_route("C Shape Island Region 2", "C Shape Island Region 1", LAND);
	tile1->add_route("C Shape Island Region 2", "C Shape Island Region 3", LAND);
	tile1->add_route("C Shape Island Region 2", "C Shape Island Region 5", WATER);
	tile1->add_route("C Shape Island Region 3", "C Shape Island Region 2", LAND);
	tile1->add_route("C Shape Island Region 3", "C Shape Island Region 4", LAND);
	tile1->add_route("C Shape Island Region 4", "C Shape Island Region 3", LAND);
	tile1->add_route("C Shape Island Region 4", "C Shape Island Region 5", LAND);
	tile1->add_route("C Shape Island Region 5", "C Shape Island Region 4", LAND);
	tile1->add_route("C Shape Island Region 5", "C Shape Island Region 2", WATER);

	auto* tile2 = new MapTile("Three Islands");
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

	// edges are initialized left to right, top to bottom, but they can be done in any way
	// edges added in both directions so that they appear in single region adjacency lists
	tile2->add_route("Three Islands Region 1", "Three Islands Region 2", WATER);
	tile2->add_route("Three Islands Region 2", "Three Islands Region 1", WATER);
	tile2->add_route("Three Islands Region 2", "Three Islands Region 3", WATER);
	tile2->add_route("Three Islands Region 3", "Three Islands Region 2", WATER);

	auto* tile3 = new MapTile("Stone Pillars Island");
	cout << "\n\nStone Pillars Island map tile has been created." << endl;

	// initialize "tile3" the left tile as depicted on the first page of the rules
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

	// edges are initialized left to right, bottom to top, but they can be done in any way
	// edges added in both directions so that they appear in single region adjacency lists
	tile3->add_route("Stone Pillars Island Region 1", "Stone Pillars Island Region 2", LAND);
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 1", LAND);
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 3", LAND); // 3 is region with houses
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 4", LAND); // 4 is region with the pillars
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 2", LAND);
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 4", LAND);
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 5", LAND);
	tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 2", LAND);
	tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 5", LAND);
	tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 3", LAND);
	tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 4", LAND);


	auto* tile4 = new MapTile("Volcano Island");
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
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	// edges are initialized left to right, top to bottom, but they can be done in any way
	// edges added in both directions so that they appear in single reagion adjacency lists
	tile4->add_route("Volcano Island Region 1", "Volcano Island Region 2", LAND);
	tile4->add_route("Volcano Island Region 2", "Volcano Island Region 1", LAND);
	tile4->add_route("Volcano Island Region 2", "Volcano Island Region 3", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 2", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 4", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 5", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 6", WATER);
	tile4->add_route("Volcano Island Region 4", "Volcano Island Region 3", LAND); // region 4 is the furthest east(or south as it appears in the game manual) region
	tile4->add_route("Volcano Island Region 4", "Volcano Island Region 5", LAND);
	tile4->add_route("Volcano Island Region 5", "Volcano Island Region 3", LAND);
	tile4->add_route("Volcano Island Region 5", "Volcano Island Region 4", LAND);
	tile4->add_route("Volcano Island Region 6", "Volcano Island Region 3", WATER); // region 6 is the bottom region on the disconnected smaller island
	tile4->add_route("Volcano Island Region 6", "Volcano Island Region 7", LAND);
	tile4->add_route("Volcano Island Region 7", "Volcano Island Region 6", LAND);

	// This is how I would normally like to construct the game map once all tiles are loaded from files and then selected and positioned
	// they could easily be combined into a "World Map" for game play with little effort and adding the last few connections between the Islands
	auto* world_map = new WorldMap(RECTANGLE, tile1, tile2, tile3, tile4);

	auto* p1 = new Player();
	auto* p2 = new Player();

	auto* deck = new Deck();

	auto deck_of_cards = deck->getListOfCards();

	//
	vector<Card*> p1_card{ deck_of_cards.at(0), deck_of_cards.at(1), deck_of_cards.at(13), deck_of_cards.at(14) };
	vector<Card*> p2_card{ deck_of_cards.at(10), deck_of_cards.at(9), deck_of_cards.at(30), deck_of_cards.at(29) };

	p1->setListOfCardsUsed(p1_card);
	p2->setListOfCardsUsed(p2_card);
	
	vector<Region*> p1_region { world_map->m_map["Stone Pillars Island Region 5"], world_map->m_map["Stone Pillars Island Region 4"] };
	vector<Region*> p2_region { world_map->m_map["Stone Pillars Island Region 5"], world_map->m_map["Stone Pillars Island Region 4"] };

	p1->setListOfRegions(p1_region);
	p2->setListOfRegions(p2_region);

	Army *a1 = new Army();
	a1->setRegion(p1_region.at(0));
	Army* a2 = new Army();
	a1->setRegion(p1_region.at(1));
	Army* a3 = new Army();
	a1->setRegion(p1_region.at(0));
	Army* a4 = new Army();
	a1->setRegion(p1_region.at(1));

	Army* a21 = new Army();
	a21->setRegion(p2_region.at(0));
	Army* a22 = new Army();
	a22->setRegion(p2_region.at(1));
	Army* a23 = new Army();
	a23->setRegion(p2_region.at(0));
	Army* a24 = new Army();
	a24->setRegion(p2_region.at(1));
	Army* a25 = new Army();
	a25->setRegion(p2_region.at(0));
	
	vector<Army*> p1_army { a1, a2, a3, a4 };
	vector<Army*> p2_army { a21, a22, a23, a24, a25 };

	p1->setListOfArmies(p1_army);
	p2->setListOfArmies(p2_army);

	int counter = 0;
	for (auto army : p1_army)
	{
		if(counter % 2 == 0)
		{
			army->setRegion(p1_region.at(0));
		}
		else
		{
			army->setRegion(p1_region.at(1));
		}
		counter++;
	}

	counter = 0;
	for (auto army : p2_army)
	{
		if (counter % 2 == 0)
		{
			army->setRegion(p2_region.at(0));
		}
		else
		{
			army->setRegion(p2_region.at(1));
		}
		counter++;
	}

	p1->setListOfArmies(p1_army);
	p2->setListOfArmies(p2_army);
	
	auto* vp = new VPCounter();

	int p1_score = vp->compute_score(p1, world_map);
	int p2_score = vp->compute_score(p2, world_map);

	cout << "\nPlayer " << p1->getFirstName() << " " << p1->getLastName() << " : " << p1_score << endl;
	cout << "\nPlayer " << p2->getFirstName() << " " << p2->getLastName() << " : " << p2_score << endl;
	
	
	auto end_scores = vp->compute_score_end_of_game(world_map);
	
	return 0;
}