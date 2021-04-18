#include "Player/Player.h"
//#include "Map/Map.h"
int main() {

//#ifdef MY_DEBUG
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//#endif

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
	auto* world_map = new WorldMap(RECTANGLE, *tile1, *tile2, *tile3, *tile4);



	vector<Card*>cardsUsed;
	vector<Card*>ennemyCards;
	vector<Region*>regionsOwned;
	vector<Region*>ennemyRegions;
	vector<Army*>armiesList;
	vector<Army*>ennemyArmyList;
	vector<City*>citiesList;
	vector<City*>ennemyCityList;

	vector<Region*>playersRegions;
	for (int i = 0; i < 10; i++) {
		City* newCity = new City();
		citiesList.push_back(newCity);
	}

	for (int i = 0; i < 10; i++) {
		City* newCity = new City();
		ennemyCityList.push_back(newCity);
	}

	Army* armyPiece1 = new Army();
	armyPiece1->setRegion(tile4->m_map_.at("Volcano Island Region 7"));
	armyPiece1->setOwner("Alpha", "Beta");
	armiesList.push_back(armyPiece1);
	regionsOwned.push_back(armyPiece1->getRegion());

	
	Army* armyPiece2 = new Army();
	armyPiece2->setRegion(tile4->m_map_.at("Volcano Island Region 7"));
	armyPiece2->setOwner("Alpha", "Beta");
	regionsOwned.push_back(armyPiece2->getRegion());
	armiesList.push_back(armyPiece2);



	Army* armyPiece3 = new Army();
	armyPiece3->setRegion(tile4->m_map_.at("Volcano Island Region 5"));
	armyPiece3->setOwner("Alpha", "Beta");
	armiesList.push_back(armyPiece3);
	regionsOwned.push_back(armyPiece3->getRegion());

	Army* armyPiece4 = new Army();
	armiesList.push_back(armyPiece4);
	for (int i = 0; i < 6; i++) {
		Army* x = new Army();
		armiesList.push_back(x);
	}
	//region starting = tileX.m_map.at(XYZ)
	//Add region to list of regions

	Army* a = new Army();
	a->setRegion(tile4->m_map_.at("Volcano Island Region 7"));
	a->setOwner("Ligma", "Balls");
	ennemyArmyList.push_back(a);
	ennemyRegions.push_back(a->getRegion());

	Army* b = new Army();
	b->setRegion(tile4->m_map_.at("Volcano Island Region 7"));
	b->setOwner("Ligma", "Balls");
	ennemyArmyList.push_back(b);
	ennemyRegions.push_back(b->getRegion());

	Army* c = new Army();
	c->setRegion(tile4->m_map_.at("Volcano Island Region 5"));
	c->setOwner("Ligma", "Balls");
	ennemyArmyList.push_back(c);
	ennemyRegions.push_back(c->getRegion());
	
	for (int i = 0; i < 6; i++) {
		Army* x = new Army();
		ennemyArmyList.push_back(x);
	}

	Player* aPlayer = new Player("Alpha", "Beta", cardsUsed, regionsOwned, armiesList, citiesList);
	
	Player* bPlayer = new Player("Ligma", "Balls", ennemyCards, ennemyRegions, ennemyArmyList, ennemyCityList);

	//Player* cPlayer = new Player("Legron", "Balls", ennemyCards, ennemyRegions, ennemyArmyList, ennemyCityList);
	/*aPlayer->MoveArmies(3);
	aPlayer->BuildCity(tile4->m_map.at("Volcano Island Region 7"));
	aPlayer->PayCoin(2, 's');*/
	//aPlayer->PlaceNewArmies(3);
	//aPlayer->BuildCity(3);
	
	//aPlayer->DestroyArmy(5);
	//aPlayer->PlaceNewArmies(3);
	aPlayer->MoveArmies(3);
	Card* test = new Card("Night Hydra", "+1 Army", "Move Armies: 5 AND Destroy Army: 2", 2);
	aPlayer->andOr(test);
	
	delete world_map;
	delete tile4;
	delete tile3;
	delete tile2;
	delete tile1;
//
//#ifdef MY_DEBUG
//	_CrtDumpMemoryLeaks(); // call before exit if debug is enabled
//#endif

	return 0;
}