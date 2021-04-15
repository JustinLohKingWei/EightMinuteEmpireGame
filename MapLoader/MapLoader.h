#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "../Map/Map.h"

class MapLoader {

public:
	string inputFileName;
	vector<string> tilesArray;
	string mapShape;
	GameMap* world_map;
	bool validity;
	int numOfTiles;
	void createMap();
	friend ostream& operator<<(ostream& outstream, const MapLoader& ml);
	MapLoader& operator=(const MapLoader&);
	MapLoader(string);
	MapLoader(const MapLoader &oldObject);
	MapLoader();
	~MapLoader();
private:
	bool readFile();
	bool validateInputTile(string);
	bool validateTilesArray();
};