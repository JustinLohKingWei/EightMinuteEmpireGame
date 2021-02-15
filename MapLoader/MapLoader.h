#pragma once
#include <string>

using namespace std;

class MapLoader {

public:

	MapLoader(string fileWithMap);


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