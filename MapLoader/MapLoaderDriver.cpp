
#include "MapLoader.h"

int main() {
	cout << "Map1 : ValidRectangle.txt" << endl;
	string * map1 = new string("UserMaps/ValidRectangle.txt");
	MapLoader ml1 = MapLoader(map1);
	delete map1;
	map1 = NULL;

	cout << "Map2 : ValidLongRectangle.txt" << endl;
	string* map2 = new string("UserMaps/ValidLongRectangle.txt");
	MapLoader ml2 = MapLoader(map2);
	delete map2;
	map2 = NULL;


	cout << "Map3 : ValidLShape.txt" << endl;
	string* map3 = new string("UserMaps/ValidLShape.txt");
	MapLoader ml3 = MapLoader(map3);
	delete map3;
	map3 = NULL;

	cout << "Map4 : InvalidLShape.txt" << endl;
	string* map4 = new string("UserMaps/InvalidLShape.txt");
	MapLoader ml4 = MapLoader(map4);
	delete map4;
	map4 = NULL;

	cout << "Map5 : InvalidLongRectangle.txt" << endl;
	string* map5 = new string("UserMaps/InvalidLongRectangle.txt");
	MapLoader ml5 = MapLoader(map5);
	delete map5;
	map5 = NULL;

	cout << "Map6 : InvalidRectangle.txt" << endl;
	string* map6 = new string("UserMaps/InvalidRectangle.txt");
	MapLoader ml6 = MapLoader(map6);
	delete map6;
	map6 = NULL;

	cout << "Map7 : InvalidShape.txt" << endl;
	string* map7 = new string("UserMaps/InvalidShape.txt");
	MapLoader ml7 = MapLoader(map7);
	delete map7;
	map7 = NULL;

	cout << "Map8 : DuplicateIslands.txt" << endl;
	string* map8 = new string("UserMaps/DuplicateIslands.txt");
	MapLoader ml8 = MapLoader(map8);
	delete map8;
	map8 = NULL;

	cout << "Map9 : EmptyLine.txt" << endl;
	string* map9 = new string("UserMaps/EmptyLine.txt");
	MapLoader ml9 = MapLoader(map9);
	delete map9;
	map9 = NULL;

	return 0;
}