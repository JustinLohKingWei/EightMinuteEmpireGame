// code adapter from examples of graphs given out as part of COMP 345 slides
#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


struct region // vertex
{
	typedef map<string, region*> adjacency;
	adjacency adj;
	string name;
	region(string s) : name(s) {}
	region(region* copy)
	{
		name = string(copy->name);
		for (auto& x: copy->adj)
		{
			adj.emplace(x); // emplace is a deep copy
		}
		cout << "\n" << "Region named : " << name << " copied!" << endl;
	}
	~region() 
	{
		for (auto& x : adj)
		{
			if (x.second == nullptr) // a lot of regions are shared
			{
				delete x.second;
				x.second = nullptr;
			}
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
	void add_region(const string& string); // add a vertex
	void add_route(const string& start, const string& end); // add a edge
	void print_map();
	void print_map_adjacency();
	void vaildate_map();
	game_map(string s);
	game_map(game_map *copy); // copy a map
	game_map(game_map* tile1_, game_map* tile2_, game_map* tile3_, game_map* tile4_); // create worl map with submaps
	~game_map();
private:
	game_map* tile1;;
	game_map* tile2;
	game_map* tile3;
	game_map* tile4;
};
