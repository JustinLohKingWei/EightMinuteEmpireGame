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
	void createMap(string*);
	MapLoader(string*);
	MapLoader();
	~MapLoader();
private:
	string* readFile();
	bool validateInputTile(string);
	bool validateTilesArray();
};