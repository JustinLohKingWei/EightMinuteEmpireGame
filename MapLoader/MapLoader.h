#pragma once
#include <string>
#include <vector>
using namespace std;
#include "../Map/Map.h"

class MapLoader {

public:
	string inputFileName;
	vector<string> tilesArray;
	string mapShape;
	game_map* world_map;
	int numOfTiles;
	void createMap();
	MapLoader(string);
	MapLoader(const MapLoader &oldObject);
	MapLoader& operator=(const MapLoader&);
	MapLoader();
	~MapLoader();
private:
	bool readFile();
	bool validateInputTile(string);
	bool validateTilesArray();
};