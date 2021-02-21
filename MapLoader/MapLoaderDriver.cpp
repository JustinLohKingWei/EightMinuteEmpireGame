#define MY_DEBUG // uncomment for memory leak dectetion

// partially from microsoft docs-> compile by using: cl /EHsc /W4 /D_DEBUG /MDd source.cpp
// mostly from TA's extra slides and adapted to assignment for memory debug
#ifdef MY_DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#endif
#include "MapLoader.h"

int main() {
#ifdef MY_DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	cout << "Map1 : ValidRectangle.txt" << endl;
	MapLoader* ml1 (new MapLoader(string("UserMaps/ValidRectangle.txt")));
	delete ml1;

	cout << "Map2 : ValidLongRectangle.txt" << endl;
	MapLoader* ml2 = (new MapLoader(string("UserMaps/ValidLongRectangle.txt")));
	delete ml2;

	cout << "Map3 : ValidLShape.txt" << endl;
	MapLoader* ml3 = (new MapLoader(string("UserMaps/ValidLShape.txt")));
	delete ml3;

	cout << "Map4 : InvalidLShape.txt" << endl;
	MapLoader* ml4 = (new MapLoader(string("UserMaps/InvalidLShape.txt")));
	delete ml4;


	cout << "Map5 : InvalidLongRectangle.txt" << endl;
	MapLoader* ml5 = (new MapLoader(string("UserMaps/InvalidLongRectangle.txt")));
	delete ml5;

	cout << "Map6 : InvalidRectangle.txt" << endl;
	MapLoader* ml6 = (new MapLoader(string("UserMaps/InvalidRectangle.txt")));
	delete ml6;

	cout << "Map7 : InvalidShape.txt" << endl;
	MapLoader* ml7 = (new MapLoader(string("UserMaps/InvalidShape.txt")));
	delete ml7;

	cout << "Map9 : EmptyLine.txt" << endl;
	MapLoader* ml9 = (new MapLoader(string("UserMaps/EmptyLine.txt")));
	delete ml9;

	cout << "Map8 : DuplicateIslands.txt" << endl;
	MapLoader* ml8 = (new MapLoader(string("UserMaps/DuplicateIslands.txt")));
	delete ml8;
	
	_CrtDumpMemoryLeaks(); // call before exit if debug is enabled
	return 0;
}