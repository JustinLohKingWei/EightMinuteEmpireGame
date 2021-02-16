#include "Map.h"

using namespace std;

game_map::game_map(string s) : map_name(s) {}

game_map::game_map(game_map* copy) // TODO
{
	if (!map_name.compare("World Map") || !map_name.compare("Copy of World Map")) // true, sub map copy
	{ 
		map_name = string("Copy of " + copy->map_name);
		for (auto& x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		cout << "\n" << "Map named : " << map_name << " copied!" << endl;
	}
	else // world map copy, only top level copies, bottom level links to original sub graphes, copy sub graphs with above!
	{
		if (!map_name.compare("Copy of World Map"))
		{
			map_name = string("Copy of " + copy->map_name);
		}
		// esle keep name of "Copy of World Map"

		for (auto& x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		cout << "\n" << "Map named : " << map_name << " copied!" << endl;
	}
}

game_map::game_map(game_map* tile1_, game_map* tile2_, game_map* tile3_) : // create world map
	map_name("World Map")
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

	cout << "\n" << "Map named : " << map_name << " created" << endl;
}

game_map::game_map(game_map* tile1_, game_map* tile2_, game_map* tile3_, game_map* tile4_) : // create world map
	map_name("World Map")
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
	cout << "\n" << "Map named : " << map_name << " created" << endl;
}

game_map::~game_map() // destruct all types maps // TODO
{
	if (!map_name.compare("World Map")) // true, sub map destruct
	{
		for (auto& x : m_map)
		{
			if (x.second != nullptr)
			{
				delete x.second;
			}
		}
		cout << "\n" << "Map named : " << map_name << " deleted!" << endl;
	}
	else // world map destruct, leaves sub graphs intact
	{
		for (auto& x : m_map)
		{
				x.second = nullptr;
		}
		cout << "\n" << "Map named : " << map_name << " deleted!" << endl;
	}
}

// adapted from graph slides from class
void game_map::add_region(const string& name)
{
	map<string, region*>::iterator itr;
	itr = m_map.find(name);
	if (itr == m_map.end())
	{
		region* r;
		r = new region(name);
		m_map[name] = r;
		return;
	}
	cout << "The region " << name << " already exists!" << endl;
}

// adapted from graph slides from class
// TODO add some error detection
void game_map::add_route(const string& start, const string& end)
{
	map<string, region*>::iterator itrS;
	map<string, region*>::iterator itrE;
	itrS = m_map.find(start);
	itrE = m_map.find(end);
	if (itrS == m_map.end() || itrE == m_map.end())
	{
		cout << "\nThe starting and/or ending region does not exists!" << endl;
		return;
	}
	else
	{
		itrS = m_map[start]->adj.find(start);
		itrE = m_map[end]->adj.find(end);

		if (itrS == m_map[start]->adj.end())
		{
			m_map[start]->adj.insert(pair<string,region*>(end,m_map[end]));
		}
		if (itrE == m_map[end]->adj.end())
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

void game_map::vaildate_map(game_map* my_map)
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a region to itself

	cout << "\nStarting map Validation ...";

	for (auto& x : my_map->m_map)
	{
		for (auto& y : x.second->adj)
		{
			if (!x.first.compare(y.first))
			{
				cout << "\nERROR: The regions " << x.first << " and " << y.first << " do not appear to have mutual connections!";
				cout << "\nThe map is invalid!" << endl;
			}
		}
	}
	cout << "\nIf no errors are printed, consider the regional listings of the map to be valid!" << endl << endl;
}
