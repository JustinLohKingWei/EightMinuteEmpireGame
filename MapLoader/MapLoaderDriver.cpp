#include "MapLoader.h"

int main() {
	MapLoader ml1 = MapLoader("UserMaps/ValidRectangle.txt");
	ml1.readFile();
}