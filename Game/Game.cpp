#include "Game.h"

Game::Game() : theGameHand(new Hand()) {
	cout << "Default game created" << endl;
	currentPlayer = 0;
	numOfPlayers = 2;
	turnNumber = 0;
	gameOver = false;
}

Game::Game(vector<Player*> players) : listOfPlayers(players), theGameHand(new Hand()), gameDeck(new Deck()){
	cout << "Game with " << listOfPlayers.size() <<" players created" << endl;
	currentPlayer = 0;
	numOfPlayers = listOfPlayers.size();
	turnNumber = 1;
	gameOver = false;
}

Player* Game::getCurrentPlayer() {
	return listOfPlayers.at(currentPlayer);
}


void Game::nextPlayer() {
	currentPlayer = (++turnNumber + (numOfPlayers-1)) % numOfPlayers;

	cout << "Play has been passed to player #" << currentPlayer+1 <<
		": " << listOfPlayers.at(currentPlayer)->getFirstName() << " "
		<< listOfPlayers.at(currentPlayer)->getLastName()<< endl;
}

int Game::getNumOfPlayers() {
	return numOfPlayers;
}

Hand* Game::getGameHand() {
	return theGameHand;
}

Deck* Game::getDeck() {
	return gameDeck;
}

//WorldMap* Game::getMap() {
//	return map;
//}

void Game::setGameHand(Hand* aHand) {
	theGameHand = aHand;
}


bool Game::getGameOver() {
	return gameOver;
}

void Game::setGameOver(bool value) {
	gameOver = value;
}

int Game::getTurnNumber() {
	return turnNumber;
}

void Game::initializeDeck()
{
	gameDeck = new Deck();
	gameDeck->filterDeck(numOfPlayers);
	gameDeck->shuffleDeck();
}

void Game::initializeHand() {
	gameDeck->fillHand(theGameHand);
}

void Game::initializeMap() {
	//Hard coded map
	cout << "****Initializing map****" << endl;
	auto* tile1 = new MapTile("C Shape Island");
	cout << "\nC Shape Island map tile has been created." << endl;

	for (auto i = 0; i < 5; ++i)
	{
		string s = "C Shape Island Region " + to_string(i + 1);

		if (i == 1)
		{
			tile1->add_connection_region(s, BOTTOM);
		}
		else if (i == 2)
		{

			tile1->add_connection_region(s, RIGHT);
		}
		else if (i == 3)
		{
			tile1->add_connection_region(s, LEFT);
		}
		else if (i == 4)
		{
			tile1->add_connection_region(s, TOP);
		}
		else
		{
			tile1->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	// edges are initialized left to right, top to bottom, but they can be done in any way
	// edges added in both directions so that they appear in single region adjacency lists
	tile1->add_route("C Shape Island Region 1", "C Shape Island Region 2", LAND);
	tile1->add_route("C Shape Island Region 2", "C Shape Island Region 1", LAND);
	tile1->add_route("C Shape Island Region 2", "C Shape Island Region 3", LAND);
	tile1->add_route("C Shape Island Region 2", "C Shape Island Region 5", WATER);
	tile1->add_route("C Shape Island Region 3", "C Shape Island Region 2", LAND);
	tile1->add_route("C Shape Island Region 3", "C Shape Island Region 4", LAND);
	tile1->add_route("C Shape Island Region 4", "C Shape Island Region 3", LAND);
	tile1->add_route("C Shape Island Region 4", "C Shape Island Region 5", LAND);
	tile1->add_route("C Shape Island Region 5", "C Shape Island Region 4", LAND);
	tile1->add_route("C Shape Island Region 5", "C Shape Island Region 2", WATER);

	auto* tile2 = new MapTile("Three Islands");
	cout << "\n\nThree Islands map tile has been created." << endl;

	for (auto i = 0; i < 3; ++i)
	{
		string s = "Three Islands Region " + to_string(i + 1);
		if (i == 1)
		{
			tile2->add_connection_region(s, BOTTOM);
			tile2->add_connection_region(s, RIGHT);
		}
		else if (i == 2)
		{
			tile2->add_connection_region(s, TOP);
			tile2->add_connection_region(s, LEFT);
		}
		else
		{
			tile2->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	// edges are initialized left to right, top to bottom, but they can be done in any way
	// edges added in both directions so that they appear in single region adjacency lists
	tile2->add_route("Three Islands Region 1", "Three Islands Region 2", WATER);
	tile2->add_route("Three Islands Region 2", "Three Islands Region 1", WATER);
	tile2->add_route("Three Islands Region 2", "Three Islands Region 3", WATER);
	tile2->add_route("Three Islands Region 3", "Three Islands Region 2", WATER);

	auto* tile3 = new MapTile("Stone Pillars Island");
	cout << "\n\nStone Pillars Island map tile has been created." << endl;

	// initialize "tile3" the left tile as depicted on the first page of the rules
	for (auto i = 0; i < 5; ++i)
	{
		string s = "Stone Pillars Island Region " + to_string(i + 1);

		if (i == 1)
		{
			tile3->add_connection_region(s, BOTTOM);
		}
		else if (i == 2)
		{

			tile3->add_connection_region(s, LEFT);
		}
		else if (i == 3)
		{
			tile3->add_connection_region(s, RIGHT);
		}
		else if (i == 5)
		{
			tile3->add_connection_region(s, TOP);
		}
		else
		{
			tile3->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	// edges are initialized left to right, bottom to top, but they can be done in any way
	// edges added in both directions so that they appear in single region adjacency lists
	tile3->add_route("Stone Pillars Island Region 1", "Stone Pillars Island Region 2", LAND);
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 1", LAND);
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 3", LAND); // 3 is region with houses
	tile3->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 4", LAND); // 4 is region with the pillars
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 2", LAND);
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 4", LAND);
	tile3->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 5", LAND);
	tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 2", LAND);
	tile3->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 5", LAND);
	tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 3", LAND);
	tile3->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 4", LAND);


	auto* tile4 = new MapTile("Volcano Island");
	cout << "\n\nVolcano Island Island map tile has been created." << endl;

	for (auto i = 0; i < 7; ++i)
	{
		string s = "Volcano Island Region " + to_string(i + 1);

		if (i == 1)
		{
			tile4->add_connection_region(s, BOTTOM);
		}
		else if (i == 2)
		{

			tile4->add_connection_region(s, LEFT);
		}
		else if (i == 4)
		{
			tile4->add_connection_region(s, RIGHT);
		}
		else if (i == 7)
		{
			tile4->add_connection_region(s, TOP);
		}
		else
		{
			tile4->add_region(s);
		}
		cout << "\n Added a new area has been added: " << s << "." << endl;
	}

	// edges are initialized left to right, top to bottom, but they can be done in any way
	// edges added in both directions so that they appear in single reagion adjacency lists
	tile4->add_route("Volcano Island Region 1", "Volcano Island Region 2", LAND);
	tile4->add_route("Volcano Island Region 2", "Volcano Island Region 1", LAND);
	tile4->add_route("Volcano Island Region 2", "Volcano Island Region 3", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 2", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 4", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 5", LAND);
	tile4->add_route("Volcano Island Region 3", "Volcano Island Region 6", WATER);
	tile4->add_route("Volcano Island Region 4", "Volcano Island Region 3", LAND); // region 4 is the furthest east(or south as it appears in the game manual) region
	tile4->add_route("Volcano Island Region 4", "Volcano Island Region 5", LAND);
	tile4->add_route("Volcano Island Region 5", "Volcano Island Region 3", LAND);
	tile4->add_route("Volcano Island Region 5", "Volcano Island Region 4", LAND);
	tile4->add_route("Volcano Island Region 6", "Volcano Island Region 3", WATER); // region 6 is the bottom region on the disconnected smaller island
	tile4->add_route("Volcano Island Region 6", "Volcano Island Region 7", LAND);
	tile4->add_route("Volcano Island Region 7", "Volcano Island Region 6", LAND);

	// This is how I would normally like to construct the game map once all tiles are loaded from files and then selected and positioned
	// they could easily be combined into a "World Map" for game play with little effort and adding the last few connections between the Islands
	map = new WorldMap(RECTANGLE, tile1, tile2, tile3, tile4);
}

void Game::biddingPhase() {

	for (int i = 0; i < numOfPlayers; i++) {
		(*(*listOfPlayers.at(i)).getBidingFacility()).pickUpCoins();
	}

	for (int i = 0; i < numOfPlayers; i++) {
		(*(*listOfPlayers.at(i)).getBidingFacility()).bidCoins();
	}

	int winnerAmount = 0;
	Player winner;
	// finds winner with largest alphabetical last name
    for (int i = 0; i < listOfPlayers.size(); i++) {
        (*(*listOfPlayers.at(i)).getBidingFacility()).displayBid();
        if (winnerAmount < (*(*listOfPlayers.at(i)).getBidingFacility()).getBidAmount()) {
			currentPlayer = i;
            winner = *listOfPlayers.at(i);
            winnerAmount = (*(*listOfPlayers.at(i)).getBidingFacility()).getBidAmount();
        }

        if (winnerAmount == (*(*listOfPlayers.at(i)).getBidingFacility()).getBidAmount()) {
            string a = winner.getLastName();
            string b = (*listOfPlayers.at(i)).getLastName();
            if (a > b) {
				currentPlayer = i;
                winner = *listOfPlayers.at(i);
            }
        }
    }
	cout << "Winning player: " << listOfPlayers.at(currentPlayer)->getFirstName() << endl;
}

void Game::initializePlayers() {
	for (int i = 0; i < numOfPlayers; i++) {
		string first, last, fName, lName;
		cout << "Please enter first name" << endl;
		cin >> first;
		cout << "Please enter last name" << endl;
		cin >> last;
		fName = string(first);
		lName = string(last);
		fName = string(first);
		lName = string(last);
		vector<Card*>cards;
    vector<Region*>listOfRegions;
    vector<Army*>listOfArmies(18, new Army);
    vector<City*>listOfCities(3, new City);
		Player* aPlayer = new Player(fName, lName, cards, listOfRegions, listOfArmies, listOfCities, new GreedyComputerStrategy());//Creating player
		listOfPlayers.push_back(aPlayer);
	}
}