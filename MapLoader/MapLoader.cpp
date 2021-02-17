#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "MapLoader.h"


MapLoader::MapLoader(string* fileWithMap)
{
	inputFileName = fileWithMap;
	string ** tilesArray;
	tilesArray = this->readFile();
}

MapLoader::~MapLoader() {};

game_map* MapLoader::createMap(string* arrayOfTiles) {
	game_map* aMap;
	aMap = new game_map(arrayOfTiles);
}


// Input: object's text file name
// Output: array of strings representing the tiles
string** MapLoader::readFile() {
	ifstream fileWithMap;
	fileWithMap.open(*(this->inputFileName));
	

	if (fileWithMap.is_open()) {
		cout << "\n\nFile is open" << endl;
		int lineNumber = 0;
		string shape;
		string* tiles[4];
		string lineOfText;

		while (getline(fileWithMap, lineOfText)) {
			// Checks if first word is an accepted shape
			if (lineNumber == 0) {
				if (!lineOfText.find("Rectangle")) {
					shape = lineOfText;
				}

				else if (!lineOfText.find("LShape")) {
					shape = lineOfText;
				}

				else if (!lineOfText.find("Long Rectangle")) {
					shape = lineOfText;
				}

				else {
					cout << "Not a valid map file" << endl;
					return NULL;
				}
				cout << "Shape of Island: " << shape << endl;
									

			}
			// Adds subsequent words to the tiles array
			else {
				tiles[lineNumber - 1] = new string(lineOfText);
			}
			cout << lineOfText << endl;
			lineNumber++;
		}
		return tiles;
		fileWithMap.close();
	}
	else cout << "Couldn't open file";
}

