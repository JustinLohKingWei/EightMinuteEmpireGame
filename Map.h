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
	void vaildate_map();
	game_map(string s);
	~game_map();
};
