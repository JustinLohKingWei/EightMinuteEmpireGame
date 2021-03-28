#include "Map.h"

using namespace std;


game_map::game_map(string s) : map_name(s) {
	/*cout << s << endl;*/
}

game_map::game_map(game_map* copy) // TODO
{
	if (map_name != "World Map" || map_name != "Copy of World Map") // true, sub map copy (!= Suggested by clang-tidy)
	{ 
		map_name = ("Copy of " + copy->map_name);
		for (auto& x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		//cout << "\n" << "Map named : " << map_name << " copied!" << endl;
	}
	else // world map copy, only top level copies, bottom level links to original sub graphs, copy sub graphs with above!
	{
		if (map_name != "Copy of World Map") // != Suggested by clang-tidy
		{
			map_name = "Copy of " + copy->map_name;
			map_shape = copy->map_shape;
			
		}
		// else keep name of "Copy of World Map"

		for (auto& x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		//cout << "\n" << "Map named : " << map_name << " copied!" << endl;
	}
}

game_map::game_map(string map_shape_, game_map* tile1_, game_map* tile2_, game_map* tile3_) : // create world map
	map_name("World Map"), map_shape(std::move(map_shape_))
{
	for (auto& x : tile1_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	for (auto& x : tile2_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	for (auto& x : tile3_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	if (map_shape == "Long Rectangle")
	{
		auto itr_1 = tile1_->c_map.find(RIGHT);
		auto itr_2 = tile2_->c_map.find(LEFT);
		
		if(itr_1 != tile1_->c_map.end() && itr_2 != tile2_->c_map.end())
		{
			add_route(itr_1->second->name, itr_2->second->name);
			add_route(itr_2->second->name, itr_1->second->name);
			itr_1 = tile2_->c_map.find(RIGHT);
			itr_2 = tile3_->c_map.find(LEFT);
			
			if (itr_1 != tile2_->c_map.end() && itr_2 != tile3_->c_map.end())
			{
				add_route(itr_1->second->name, itr_2->second->name);
				add_route(itr_2->second->name, itr_1->second->name);
				//cout << "\n" << "Map named : " << map_name << " created" << endl;
			}
		}
	}
	else if (map_shape == "LShape")
	{
		auto itr_1 = tile1_->c_map.find(BOTTOM);
		auto itr_2 = tile2_->c_map.find(TOP);
		
		if (itr_1 != tile1_->c_map.end() && itr_2 != tile2_->c_map.end())
		{
			add_route(itr_1->second->name, itr_2->second->name);
			add_route(itr_2->second->name, itr_1->second->name);
			itr_1 = tile2_->c_map.find(RIGHT);
			itr_2 = tile3_->c_map.find(LEFT);

			if (itr_1 != tile2_->c_map.end() && itr_2 != tile3_->c_map.end())
			{
				add_route(itr_1->second->name, itr_2->second->name);
				add_route(itr_2->second->name, itr_1->second->name);
				//cout << "\n" << "Map named : " << map_name << " created" << endl;
			}
	}
	else
	{
		}
		cout << "The connection regions have not been set up in the sub graphs!" << endl;
	}
}

game_map::game_map(string map_shape_, game_map* tile1_, game_map* tile2_, game_map* tile3_, game_map* tile4_) : // create world map
	map_name("World Map"), map_shape(std::move(map_shape_))
{
	for (auto& x : tile1_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	for (auto& x : tile2_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	for (auto& x : tile3_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	for (auto& x : tile4_->m_map)
	{
		m_map.insert(x); // emplace is a deep copy
	}

	if (map_shape == "Rectangle")
	{
		auto itr_1 = tile1_->c_map.find(RIGHT);
		auto itr_2 = tile2_->c_map.find(LEFT);
		if (itr_1 != tile1_->c_map.end() && itr_2 != tile2_->c_map.end())
		{
			add_route(itr_1->second->name, itr_2->second->name);
			add_route(itr_2->second->name, itr_1->second->name);
			itr_1 = tile2_->c_map.find(RIGHT);
			itr_2 = tile3_->c_map.find(LEFT);

			if (itr_1 != tile2_->c_map.end() && itr_2 != tile3_->c_map.end())
			{
				add_route(itr_1->second->name, itr_2->second->name);
				add_route(itr_2->second->name, itr_1->second->name);
				itr_1 = tile3_->c_map.find(RIGHT);
				itr_2 = tile4_->c_map.find(LEFT);

				if (itr_1 != tile3_->c_map.end() && itr_2 != tile4_->c_map.end())
				{
					add_route(itr_1->second->name, itr_2->second->name);
					add_route(itr_2->second->name, itr_1->second->name);
					//cout << "\n" << "Map named : " << map_name << " created" << endl;
				}
			}
		}
	}
	else
	{
		cout << "The connection regions have not been set up in the sub graphs!" << endl;
	}
}

game_map::~game_map() // destruct all types maps // TODO
{
	if (map_name != "World Map") // true, sub map destruct (!= Suggested by clang-tidy)
	{
		for (auto& x : m_map)
		{
			if (x.second != nullptr)
			{
				//cout << "Not world map" << endl;
				delete x.second;
			}
		  }
		//cout << "\n" << "Map named : " << map_name << " deleted!" << endl;
	}
	else // world map destruct, leaves sub graphs intact
	{
		for (auto& x : m_map)
		{
				x.second = nullptr;
		}
		for (auto& x : c_map)
		{
			x.second = nullptr;
		}
		//cout << "\n" << "Map named : " << map_name << " deleted!" << endl;
	}
}

// adapted from graph slides from class
void game_map::add_region(const string& name)
{
	const auto itr = m_map.find(name);
	if (itr == m_map.end())
	{
		auto* r = new region(name);
		m_map[name] = r;
		return;
	}
	//cout << "The region " << name << " already exists!" << endl;
}

void game_map::add_connection_region(const string& name, region_connection direction) // replace add_region when region has a outside connection!!!
{
	const auto itr = m_map.find(name);

	if (itr == m_map.end())
	{
		auto* r = new region(name);
		m_map[name] = r;
		c_map[direction] = r;
		return;
	}
	else
	{
		c_map[direction] = itr->second; // some regions have double outside connections
	}
	//cout << "The region " << name << " already exists!" << endl;
}

// adapted from graph slides from class
// TODO add some error detection
void game_map::add_route(const string& start, const string& end)
{
	auto itr_s = m_map.find(start);
	auto itr_e = m_map.find(end);
	
	if (itr_s == m_map.end() || itr_e == m_map.end())
	{
		cout << "\nThe starting and/or ending region does not exists!" << endl;
		return;
	}
	else
	{
		itr_s = m_map[start]->adj.find(start);
		itr_e = m_map[end]->adj.find(end);

		if (itr_s == m_map[start]->adj.end())
		{
			m_map[start]->adj.insert(pair<string,region*>(end,m_map[end]));
		}
		if (itr_e == m_map[end]->adj.end())
		{
			m_map[end]->adj.insert(pair<string, region*>(start, m_map[start]));
		}
	}
}

void game_map::print_map()
{
	for (auto& x : m_map)
	{
		cout << "\n" << x.first << endl;
	}
}

void game_map::print_map_adjacency()
{
	for (auto& x : m_map)
	{
		cout << "\n" << x.first << " has the following adjacency: " << endl;
		for (auto& y : x.second->adj)
		{
			cout << y.first << endl;
		}
		cout << endl;
	}
}

void game_map::validate_map(game_map* my_map)
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a region to itself

	cout << "\nStarting map Validation ...";

	for (auto& x : my_map->m_map)
	{
		for (auto& y : x.second->adj)
		{
			if (x.first != y.first) // != Suggested by clang-tidy
			{
				cout << "\nERROR: The regions " << x.first << " and " << y.first << " do not appear to have mutual connections!";
				cout << "\nThe map is invalid!" << endl;
			}
		}
	}
	cout << "\nIf no errors are printed, consider the regional listings of the map to be valid!" << endl << endl;
}


void game_map::populateTile(string tileName) {
	if (tileName.compare("C Shape Island")) {
		cout << "\nC Shape Island map tile has been created." << endl;

		// initialize "tile1" the center tile as depected on the first page of the rules
		for (auto i = 0; i < 5; ++i)
		{
			string s = "C Shape Island Region " + to_string(i + 1);
			this->add_region(s);
			//cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, top to bottom, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("C Shape Island Region 1", "C Shape Island Region 2");
		this->add_route("C Shape Island Region 2", "C Shape Island Region 1");
		this->add_route("C Shape Island Region 2", "C Shape Island Region 3");
		this->add_route("C Shape Island Region 2", "C Shape Island Region 5");
		this->add_route("C Shape Island Region 3", "C Shape Island Region 2");
		this->add_route("C Shape Island Region 3", "C Shape Island Region 4");
		this->add_route("C Shape Island Region 4", "C Shape Island Region 3");
		this->add_route("C Shape Island Region 4", "C Shape Island Region 5");
		this->add_route("C Shape Island Region 5", "C Shape Island Region 4");
		this->add_route("C Shape Island Region 5", "C Shape Island Region 2");
	}
	else if (tileName.compare("Three Islands")) {
		//cout << "\n\nThree Islands map tile has been created." << endl;

		// initialize "tile2" the right tile as depected on the first page of the rules
		for (auto i = 0; i < 3; ++i)
		{
			string s = "Three Islands Region " + to_string(i + 1);
			this->add_region(s);
			//cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, top to bottom, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("Three Islands Region 1", "Three Islands Region 2");
		this->add_route("Three Islands Region 2", "Three Islands Region 1");
		this->add_route("Three Islands Region 2", "Three Islands Region 3");
		this->add_route("Three Islands Region 3", "Three Islands Region 2");
	}
	else if (tileName.compare("Stone Pillars Islands")) {
		//cout << "\n\nStone Pillars Island map tile has been created." << endl;

		// initialize "tile3" the left tile as depected on the first page of the rules
		for (auto i = 0; i < 5; ++i)
		{
			string s = "Stone Pillars Island Region " + to_string(i + 1);
			this->add_region(s);
			//cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, bottom to top, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("Stone Pillars Island Region 1", "Stone Pillars Island Region 2");
		this->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 1");
		this->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 3"); // 3 is region with houses
		this->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 4"); // 4 is region with the pillars
		this->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 2");
		this->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 4");
		this->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 5");
		this->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 2");
		this->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 5");
		this->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 3");
		this->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 4");
	}
	else if (tileName.compare("Valcano Island")) {
		//cout << "\n\nValcano Island Island map tile has been created." << endl;

		// initialize "tile4" the top tile as depected on the first page of the rules
		for (auto i = 0; i < 7; ++i)
		{
			string s = "Valcano Island Region " + to_string(i + 1);
			this->add_region(s);
			//cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, top to bottom, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("Valcano Island Region 1", "Valcano Island Region 2");
		this->add_route("Valcano Island Region 2", "Valcano Island Region 1");
		this->add_route("Valcano Island Region 2", "Valcano Island Region 3");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 2");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 4");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 5");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 5");
		this->add_route("Valcano Island Region 4", "Valcano Island Region 3"); // region 4 is the furthest east(or south as it appears in the game manual) region
		this->add_route("Valcano Island Region 4", "Valcano Island Region 5");
		this->add_route("Valcano Island Region 5", "Valcano Island Region 3");
		this->add_route("Valcano Island Region 5", "Valcano Island Region 4");
		this->add_route("Valcano Island Region 6", "Valcano Island Region 3"); // region 6 is the bottom region on the disconnected smaller island
		this->add_route("Valcano Island Region 6", "Valcano Island Region 7");
		this->add_route("Valcano Island Region 7", "Valcano Island Region 6");
	}




}
