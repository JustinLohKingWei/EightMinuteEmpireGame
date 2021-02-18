#pragma once
#include <string>
#include "../Map/Map.h"
using namespace std;

class MapLoader {

public:
	string* inputFileName;
	game_map* createMap(string*);
	MapLoader(string*);
	MapLoader();
	~MapLoader();

private:
	string** readFile();
};