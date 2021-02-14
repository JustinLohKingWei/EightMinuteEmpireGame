#include "Map.h"

using namespace std;

game_map::game_map(string s) : map_name(s) {}

game_map::game_map(game_map* copy)
{
	if (tile1 == nullptr) // true, sub map copy
	{ 
		map_name = string(copy->map_name);
		for (auto& x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		cout << "\n" << "Map named : " << map_name << " copied!" << endl;
	}
	else // world map copy, only top level copies, bottom level links to original sub graphes, copy sub graphs with above!
	{
		map_name = string(copy->map_name);
		for (auto& x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		tile1 = copy->tile1;
		tile2 = copy->tile2;
		tile3 = copy->tile3;
		tile4 = copy->tile4;
		cout << "\n" << "Map named : " << map_name << " copied!" << endl;
	}
}

game_map::game_map(game_map* tile1_, game_map* tile2_, game_map* tile3_, game_map* tile4_) : // create world map
	map_name("World Map"), tile1(tile1_), tile2(tile2_), tile3(tile3_), tile4(tile4_) {}

game_map::~game_map() // destruct all types maps
{
	if (tile1 == nullptr) // true, sub map destruct
	{
		for (auto& x : m_map)
		{
			delete x.second;
		}
		cout << "\n" << "Map named : " << map_name << " deleted!" << endl;
	}
	else // world map destruct, leaves sub graphs intact
	{
		for (auto& x : m_map)
		{
			delete x.second;
		}
		tile1 = nullptr;
		tile2 = nullptr;
		tile3 = nullptr;
		tile4 = nullptr;
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
			m_map[start]->adj.emplace(pair<string,region*>(end,m_map[end]));
		}
		if (itrE == m_map[end]->adj.end())
		{
			m_map[end]->adj.emplace(pair<string, region*>(start, m_map[start]));
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

void game_map::vaildate_map()
{
	//TODO Check for doubles and anything else I can think of... make sure all regions are connected?
}
