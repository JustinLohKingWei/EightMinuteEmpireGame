#include "MapLoader.h"

int main() {
	string * map1 = new string("UserMaps/ValidRectangle.txt");
	MapLoader ml1 = MapLoader(map1);

	string* map2 = new string("UserMaps/ValidLongRectangle.txt");
	MapLoader ml2 = MapLoader(map2);

	string* map3 = new string("UserMaps/ValidLShape.txt");
	MapLoader ml3 = MapLoader(map3);
}