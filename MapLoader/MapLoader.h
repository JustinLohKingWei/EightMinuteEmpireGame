#pragma once
#include <string>
using namespace std;
#include "../Map/Map.h"

class MapLoader {

public:
	string* inputFileName;
	string* tilesArray;
	string* mapShape;
	game_map* world_map;
	int* numOfTiles;
	void createMap(string*);
	MapLoader(string*);
	MapLoader(const MapLoader &oldObject);
	MapLoader& operator =(const MapLoader& mapLoader);
	MapLoader();
	~MapLoader();
private:
	string* readFile();
	bool validateInputTile(string);
	bool validateTilesArray();
};