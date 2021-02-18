
#include "MapLoader.h"

int main() {
	string * map1 = new string("UserMaps/ValidRectangle.txt");
	MapLoader ml1 = MapLoader(map1);
	delete map1;
	map1 = NULL;

	string* map2 = new string("UserMaps/ValidLongRectangle.txt");
	MapLoader ml2 = MapLoader(map2);
	delete map2;
	map2 = NULL;

	string* map3 = new string("UserMaps/ValidLShape.txt");
	MapLoader ml3 = MapLoader(map3);
	delete map3;
	map3 = NULL;

	string* map4 = new string("UserMaps/InvalidLShape.txt");
	MapLoader ml4 = MapLoader(map4);
	delete map4;
	map4 = NULL;

	string* map5 = new string("UserMaps/InvalidLongRectangle.txt");
	MapLoader ml5 = MapLoader(map5);
	delete map5;
	map5 = NULL;

	string* map6 = new string("UserMaps/InvalidRectangle.txt");
	MapLoader ml6 = MapLoader(map6);
	delete map6;
	map6 = NULL;

	string* map7 = new string("UserMaps/InvalidShape.txt");
	MapLoader ml7 = MapLoader(map7);
	delete map7;
	map7 = NULL;
}