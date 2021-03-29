#include <fstream>
#include <iostream>
#include<string>
using namespace std;
#include "MapLoader2.h"

MapLoader::MapLoader() : inputFileName(string()), world_map(new game_map(string("World Map"))), validity(false)
{

}


MapLoader& MapLoader::operator=(const MapLoader& mapLoader)
{
	this->inputFileName = mapLoader.inputFileName;
	this->world_map = mapLoader.world_map;

	return *this;
}

MapLoader::MapLoader(string fileWithMap) : inputFileName(fileWithMap), world_map(new game_map(string("World Map"))), validity(false)
{


}

MapLoader::MapLoader(const MapLoader& oldObject) {
	this->inputFileName = oldObject.inputFileName;
	this->world_map = oldObject.world_map;
}



MapLoader::~MapLoader() {

	delete this->world_map;
};

// Instantiates a tile 
void MapLoader::createMap() {
}


// Input: object's text file name
// Output: array of strings representing the tiles
// Returns NULL if 
// - Invalid shape name
// - Duplicate tile names
// - Invalid tile name
// - Invalid number of tiles
void MapLoader::readFile() {
	ifstream fileWithMap;
	fileWithMap.open(inputFileName, ios::in);
	if (fileWithMap.is_open()) {
		string lineOfText; 
		vector<game_map> mapsInFile;
		int currentMapNumber = 0;
		while (getline(fileWithMap, lineOfText)) {
			if (lineOfText.substr(0, string("mapname: ").length()) == "mapname: ") {
				string tileName = lineOfText.substr(9);
				mapsInFile.push_back(new game_map(tileName));
				cout << tileName << endl;
			} else if(lineOfText.substr(0, string("route: ").length()) == "route: "){
				string delimiter = " ";
				string routeText = lineOfText.substr(string("route: ").length());
				string start = routeText.substr(0, routeText.find(delimiter));
				cout << "this is start:" << start << "x" << endl;
				string end = routeText.substr(routeText.find(delimiter)+1);
				cout << "this is end:" << end << endl;
			}
			else if (lineOfText.substr(0,string("connection_region: ").length()) == "connection_region: ") {
				string delimiter = " ";
				string connectionText = lineOfText.substr(string("connection_region: ").length());
				string regionWithPossibleConnection = connectionText.substr(0, connectionText.find(delimiter));
				cout << "THIS IS REGION WITH POSS" << regionWithPossibleConnection << endl;
				string directionOfPossibleConnection = connectionText.substr(connectionText.find(delimiter) + 1);
				cout << "DIRECTION:" << directionOfPossibleConnection << endl;
			}
			else if (lineOfText.substr(0, string("world_map_shape: ").length()) == "world_map_shape: ") {
				string delimiter = " ";
				string shapeText = lineOfText.substr(string("world_map_shape: ").length());
				cout << shapeText << "x" << endl;
			}
		}
	}
}

//bool MapLoader::validateInputTile(string inputTileName) {
//	if (inputTileName == string("Three Islands") || inputTileName == string("C Shape Island") ||
//		inputTileName == string("Stone Pillars Island") || inputTileName == string("Valcano Island")) {
//		return true;
//	}
//	else {
//		return false;
//	}
//
//}
//
//bool MapLoader::validateTilesArray() {
//	
//}

ostream& operator<<(ostream& outstream, const MapLoader& ml)
{

	if (ml.validity) {
		outstream <<
			"******************************\n\n" <<
			"You have loaded a valid map.\n\n" <<
			"******************************" <<
			endl;
	}
	else {
		outstream <<
			"******************************\n\n" <<
			"You have NOT loaded a valid map.\n\n" <<
			"******************************" <<
			endl;
	}

	return outstream;
}
