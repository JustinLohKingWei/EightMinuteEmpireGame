#include "MapLoader.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;



MapLoader::MapLoader(string fileWithMap)
{
	
	inputFileName = fileWithMap;
	string * tilesArray;
	tilesArray = this->readFile();
	

}

MapLoader::~MapLoader() {};

string* MapLoader::readFile() {
	ifstream fileWithMap;
	fileWithMap.open(this->inputFileName);
	string textLine;

	if (fileWithMap.is_open()) {
		cout << "File is open" << endl;
		int lineNumber = 0;
		string shape;
		string tiles[4];

		while (getline(fileWithMap, textLine)) {
			// Checks if first word is an accepted shape
			if (lineNumber == 0) {
				if (!textLine.find("Rectangle")) {
					cout << "Found rectangle" << endl;
				}

				else if (!textLine.find("LShape")) {
					cout << "Found LShape" << endl;
				}

				else if (!textLine.find("Long Rectangle")) {
					cout << "Found Long Rectangle" << endl;
				}

				else {
					cout << "No shape found" << endl;
					return;
				}

			}
			// Adds subsequent words to the tiles array
			else {
				tiles[lineNumber - 1] = textLine;
			}
			cout << textLine << endl;
			lineNumber++;
		}

		return tiles;

		/*	for (int i = 0; i < 4; i++) {
				cout << "Tile #" << i << " " << tiles[i] << endl;
			}*/


		fileWithMap.close();
	}

	else cout << "Couldn't open file";


}

