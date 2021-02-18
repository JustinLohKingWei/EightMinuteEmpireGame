#pragma once
#include <string>
using namespace std;
#include "../Map/Map.h"

class MapLoader {

public:
	string* inputFileName;
	string* tilesArray;
	void createMap(string*);
	MapLoader(string*);
	~MapLoader();
private:
	string* readFile();
};