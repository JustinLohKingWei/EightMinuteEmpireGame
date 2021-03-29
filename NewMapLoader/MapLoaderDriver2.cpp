#include "MapLoader2.h"


int main() {
	MapLoader ml1 = MapLoader();
	ml1.inputFileName = string("../../NewMapLoader/sampleMap.txt");
	ml1.readFile();
	return 0;
}

