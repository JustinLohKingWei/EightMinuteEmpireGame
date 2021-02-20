#include <fstream>
#include <iostream>
using namespace std;

#include "MapLoader.h"

MapLoader::MapLoader() : inputFileName(new string()), tilesArray(new string()), mapShape(new string()), world_map(new game_map())
{

}

MapLoader::MapLoader(string* fileWithMap) : inputFileName(new string()), tilesArray(new string()), mapShape(new string())
{
	inputFileName = fileWithMap;
	tilesArray = this->readFile();
	if (tilesArray == NULL) {
		cout << "\n****************************\nCould NOT load a valid map.\n****************************" << endl;
	}
	else {
		this->createMap(tilesArray);
		cout << "\n****************************\nLoaded a valid map.\n****************************" << endl;
	}
}

MapLoader::~MapLoader() {
	delete inputFileName;
	inputFileName = NULL;

	delete tilesArray;
	tilesArray = NULL;

	delete mapShape;
	mapShape = NULL;
};

// Instantiates a tile 
void MapLoader::createMap(string* arrayOfTiles) {
	game_map* tiles = new game_map[4];
	for (int i = 0; i < 4; i++) {
		cout << "Tile #" << i << ": " << arrayOfTiles[i] << endl;
	}

	for (int i = 0; i < 4; i++) {
		tiles[i] = new game_map(arrayOfTiles[i]);
	}

	if (*mapShape == string("Rectangle")) {
		world_map = new game_map(&tiles[0], &tiles[1], &tiles[2], &tiles[3]);
	}

	delete[] tiles;
	tiles = NULL;
}


// Input: object's text file name
// Output: array of strings representing the tiles
// Returns NULL if 
// - Invalid shape name
// - Duplicate tile names
// - Invalid tile name
// - Invalid number of tiles
string* MapLoader::readFile() {
	ifstream fileWithMap;
	fileWithMap.open(*(this->inputFileName));


	if (fileWithMap.is_open()) {
		cout << "\n\nFile is open" << endl;
		int lineNumber = 0;
		string* tiles = new string[4];
		string lineOfText;

		while (getline(fileWithMap, lineOfText)) {
			// Checks if first word is an accepted shape
			if (lineNumber == 0) {
				if (!lineOfText.find("Rectangle") || !lineOfText.find("LShape") ||
					!lineOfText.find("Long Rectangle")) {
					mapShape = new string(lineOfText);
				}
				else {
					cout << "Not a valid map file" << endl;
					fileWithMap.close();
					return NULL;
				}
				cout << "Shape of Island: " << *mapShape << endl;
			}

			// Checks if subsequent words are valid regions
			else {
				if (validateInputTile(lineOfText)) {
					tiles[lineNumber - 1] = lineOfText;
				}
				else {
					fileWithMap.close();
					cout << "Invalid region name" << endl;
					return NULL;
				}

			}
			cout << lineOfText << endl;
			lineNumber++;
		}
		fileWithMap.close();

		tilesArray = tiles;
		if (!this->validateTilesArray()) {
			return NULL;
		}

		return tiles;
	}
	else cout << "Couldn't open file";
	return NULL;
}

bool MapLoader::validateInputTile(string inputTileName) {
	if (inputTileName == string("Three Islands") || inputTileName == string("C Shape Island") ||
		inputTileName == string("Stone Pillars Island") || inputTileName == string("Valcano Island")){
		return true;
	}
	else {
		return false;
	}

}

bool MapLoader::validateTilesArray() {
	// depends on shape, 3 for LShape and LongRectangle, 4 for Rectangle
	bool validArray = true;
	int numOfTiles;
	if (*mapShape == string("Rectangle")) {
		numOfTiles = 4;
	}
	else if (*mapShape == string("Long Rectangle") ||
		*mapShape == string("LShape")) {
		numOfTiles = 3;
	}
	
	// Checks for duplicates
	for (int i = 0; i < numOfTiles; i++) {

		for (int j = i + 1; j < numOfTiles; j++) {
			if (this->tilesArray[i] == this->tilesArray[j] || tilesArray[i].empty() || tilesArray[j].empty()) {
				validArray = false;
			}
		}
	}
	cout << validArray << endl;
	return validArray;

}

