#include <fstream>
#include <iostream>
using namespace std;



#include "MapLoader.h"

MapLoader::MapLoader() : inputFileName(string()), tilesArray(vector<string>()), mapShape(string()), world_map(new game_map(string("World Map"))), numOfTiles(int())
{

}

MapLoader& MapLoader::operator=(const MapLoader &mapLoader)
{
	this->inputFileName = mapLoader.inputFileName;
	this->tilesArray = mapLoader.tilesArray;
	this->mapShape = mapLoader.mapShape;
	this->world_map = mapLoader.world_map;
	this->numOfTiles = mapLoader.numOfTiles;

	return *this;
}

MapLoader::MapLoader(string fileWithMap) : inputFileName(fileWithMap), tilesArray(vector<string>()), 
	mapShape(string()), numOfTiles(int()), world_map(new game_map(string("World Map")))
{
	bool validFile = this->readFile();
	if (!validFile) {
		cout << "\n****************************\nCould NOT load a valid map.\n****************************" << endl;
	}
	else {
		this->createMap();
		cout << "\n****************************\nLoaded a valid map.\n****************************" << endl;
	}

}

MapLoader::MapLoader(const MapLoader& oldObject) {
	this->inputFileName = oldObject.inputFileName;
	this->tilesArray = oldObject.tilesArray;
	this->mapShape = oldObject.mapShape;
	this->world_map = oldObject.world_map;
	this->numOfTiles = oldObject.numOfTiles;
}



MapLoader::~MapLoader() {
	
	delete this->world_map;
};

// Instantiates a tile 
void MapLoader::createMap() {
	vector<game_map*> tiles= vector<game_map*>();
	// was initialized at construction, want to delete and replace with proper map
	delete this->world_map;
	for (int i = 0; i < numOfTiles; i++) {
		tiles.push_back(new game_map(tilesArray.at(i)));
	}

	if (mapShape == string("Rectangle")) {
		this->world_map = new game_map(tiles[0], tiles[1], tiles[2], tiles[3]);
	}
	else if (mapShape == string("Long Rectangle")) {
		this->world_map = new game_map(tiles[0], tiles[1], tiles[2]);
	}
	else if (mapShape == string("LShape")) {
		this->world_map = new game_map(tiles[0], tiles[1], tiles[2]);
	}



	for (game_map* index : tiles) {
		delete index;
	}
}


// Input: object's text file name
// Output: array of strings representing the tiles
// Returns NULL if 
// - Invalid shape name
// - Duplicate tile names
// - Invalid tile name
// - Invalid number of tiles
bool MapLoader::readFile() {
	ifstream fileWithMap;
	fileWithMap.open((this->inputFileName));

	if (fileWithMap.is_open()) {
		cout << "\n\nFile is open" << endl;
		int lineNumber = 0;
		string lineOfText;

		while (getline(fileWithMap, lineOfText)) {
			// Checks if first word is an accepted shape
			if (lineNumber == 0) {
				if (!lineOfText.find("Rectangle") || !lineOfText.find("LShape") ||
					!lineOfText.find("Long Rectangle")) {
					mapShape = lineOfText;
				}
				else {
					cout << "Not a valid map file" << endl;
					fileWithMap.close();
					return false;
				}
				cout << "Shape of Island: " << mapShape << endl;
			}

			// Checks if subsequent words are valid regions
			else {
				if (validateInputTile(lineOfText)) {
					tilesArray.push_back(lineOfText);
				}
				else {
					fileWithMap.close();
					cout << "Invalid region name" << endl;
					return false;
				}

			}
			cout << "Line #" << lineNumber+1 << ": " << lineOfText << endl;
			lineNumber++;
		}
		fileWithMap.close();


		return(validateTilesArray());
	}
	else {
		cout << "Couldn't open file";
		fileWithMap.close();
		return false;
	}
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
	if (mapShape == string("Rectangle")) {
		numOfTiles = 4;
	}
	else if (mapShape == string("Long Rectangle") ||
		mapShape == string("LShape")) {
		numOfTiles = 3;
	}

	if (this->tilesArray.size() < this->numOfTiles) {
		return false;
	}
	
	// Checks for duplicates
	for (int i = 0; i < numOfTiles; i++) {

		for (int j = i + 1; j <  numOfTiles; j++) {
			if (this->tilesArray[i] == this->tilesArray[j] || this->tilesArray[i].empty() || this->tilesArray.empty()) {
				validArray = false;
			}
		}
	}
	return validArray;

}

