#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "../Map/Map.h"

class MapLoader {

public:
	string inputFileName;
	game_map* world_map;
	bool validity;
	void createMap();
	friend ostream& operator<<(ostream& outstream, const MapLoader& ml);
	MapLoader& operator=(const MapLoader&);
	MapLoader(string);
	MapLoader(const MapLoader& oldObject);
	MapLoader();
	~MapLoader();
	void readFile();
private:
	
	//bool validateInputTile(string);
	//bool validateTilesArray();
};