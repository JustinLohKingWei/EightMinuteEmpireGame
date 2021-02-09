#include "Map.h"

using namespace std;

game_map::game_map(string s) : map_name(s) {}

game_map::~game_map()
{
	// TODO clear memory leaks by creating better destuctor
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
	// TODO
}

void game_map::vaildate_map()
{
	//TODO Check for doubles and anything else I can think of... make sure all regions are connected?
}