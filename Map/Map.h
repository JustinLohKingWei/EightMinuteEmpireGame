// code adapter from examples of graphs given out as part of COMP 345 slides
#pragma once

#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

enum region_connection { TOP, BOTTOM, LEFT, RIGHT };

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
	typedef map<region_connection, region*> connection_regions;
	v_map m_map;
	string map_name;
	string map_shape;
	connection_regions c_map;
	void add_region(const string&); // add an vertex
	void add_connection_region(const string&, region_connection); // add an vertex
	void add_route(const string&, const string&); // add an edge
	void print_map();
	void print_map_adjacency();
	static void validate_map(game_map*);
	game_map(string);
	game_map(game_map*); // copy a map
	game_map(string, game_map*, game_map*, game_map*); // create world map with 3 submaps
	game_map(string, game_map*, game_map*, game_map*, game_map*); // create world map with 4 submaps
	~game_map();

private:
	void populateTile(string);
};

