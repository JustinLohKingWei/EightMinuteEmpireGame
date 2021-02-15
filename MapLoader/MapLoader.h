#pragma once
#include <string>
#include "../Map/Map.h"
using namespace std;

class MapLoader {

public:
	game_map mapFromFile;
	string inputFileName;
	string* readFile();
	MapLoader(string fileWithMap);
	~MapLoader();

	/*
	Syntax of map file is:
	Rectangle, TopLeft, TopRight, BottomRight, BottomLeft
	L, Top, Center, Right
	LongRectangle, Left, Center, Right
	*/
	//void checkFile(string fileName);
	

	// Create map object

private:
	string mapToLoad;
};