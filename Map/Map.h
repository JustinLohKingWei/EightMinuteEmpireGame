// code adapter from examples of graphs given out as part of COMP 345 slides
#pragma once

#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;
class Player;

enum region_connection { TOP, BOTTOM, LEFT, RIGHT };

class region // vertex
{
public:
	typedef map<string, region*> adjacency;
	adjacency adj;
	string name;
	region(string);
	~region();
	int get_number_of_armies(Player*);
	void set_player_with_most_armies();
	void update_armies_to_region(Player*);
	vector<Player*> get_controlling_player();
	vector<pair<Player*, int>> get_occuping_armies();
private:
	vector<pair<Player*, int>> occuping_armies;
	vector<Player*> controlling_player;
	void add_controlling_player(Player*);
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

};

