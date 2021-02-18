#pragma once
#include <string>
using namespace std;
#include "../Map/Map.h"

class MapLoader {

public:
	string* inputFileName;
	string* tilesArray;
	string* mapShape;
	void createMap(string*);
	MapLoader(string*);
	MapLoader();
	~MapLoader();
private:
	string* readFile();
	bool validateInputTile(string);
	bool validateTilesArray();
};