#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "MapLoader.h"



MapLoader::MapLoader(string* fileWithMap)
{
	inputFileName = fileWithMap;
	tilesArray = this->readFile();
	this->createMap(tilesArray);
	delete[] tilesArray;
	tilesArray = NULL;
}

MapLoader::~MapLoader() {

	delete inputFileName;
	inputFileName = NULL;

	delete tilesArray;
	tilesArray = NULL;

};

// Instantiates a tile 
void MapLoader::createMap(string* arrayOfTiles) {
	game_map* tiles = new game_map[4];
	for (int i = 0; i < 4; i++) {
		tiles[i] = new game_map(arrayOfTiles[i]);
	}

	delete[] tiles;
	tiles = NULL;
}


// Input: object's text file name
// Output: array of strings representing the tiles
string* MapLoader::readFile() {
	ifstream fileWithMap;
	fileWithMap.open(*(this->inputFileName));
	

	if (fileWithMap.is_open()) {
		cout << "\n\nFile is open" << endl;
		int lineNumber = 0;
		string shape;
		string * tiles = new string[4];
		string lineOfText;

		while (getline(fileWithMap, lineOfText)) {
			// Checks if first word is an accepted shape
			if (lineNumber == 0) {
				if (!lineOfText.find("Rectangle") || !lineOfText.find("LShape") || 
					!lineOfText.find("Long Rectangle")) {
					shape = lineOfText;
				}
				else {
					cout << "Not a valid map file" << endl;
					fileWithMap.close();
					return NULL;
				}
				cout << "Shape of Island: " << shape << endl;
			}

			// Adds subsequent words to the tiles array
			else {
				tiles[lineNumber - 1] = *(new string(lineOfText));
			}
			cout << lineOfText << endl;
			lineNumber++;
		}
		fileWithMap.close();
		return tiles;
	}
	else cout << "Couldn't open file";
	return NULL;
}

