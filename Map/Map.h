// code adapter from examples of graphs given out as part of COMP 345 slides
#pragma once

#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

enum map_shape { RECTANGLE, L_SHAPE };

struct region // vertex
{
	typedef map<string, region*> adjacency;
	adjacency adj;
	string name;
	region(string s) : name(s) {}
	/*region(region* copy) // This should be restricted and handled when creating a map copy!
	{
		name = string(copy->name);
		for (auto& x: copy->adj)
		{
			adj.emplace(x); // emplace is a deep copy
		}
		cout << "\n" << "Region named : " << name << " copied!" << endl;
	}*/
	~region() 
	{
		for (auto& x : adj)
		{
			x.second = nullptr;
		}
		cout << "\n" << "Region named : " << name << " deleted!" << endl;
	}
};

class game_map // graph, island, or world map
{
public:
	typedef map<string, region*> v_map;
	v_map m_map;
	string map_name;
	vector<string, region*> connectable_regions;
	void add_region(const string& string); // add an vertex
	void add_route(const string& start, const string& end); // add an edge
	void print_map();
	void print_map_adjacency();
	static void vaildate_map(game_map* my_map);
	game_map();
	game_map(string s);
	game_map(game_map *copy); // copy a map
	game_map(game_map* tile1_, game_map* tile2_, game_map* tile3_); // create world map with 3 submaps
	game_map(game_map* tile1_, game_map* tile2_, game_map* tile3_, game_map* tile4_); // create world map with 4 submaps
	~game_map();

private:
	void populateTile(string);
	void defineConnectableRegions();
	void connectTiles();
};
