// #define MAPDEBUG // comment out for no more text readouts

// code adapter from examples of graphs given out as part of COMP 345 slides
#pragma once

#ifndef MAP_H
#define MAP_H
#endif

#include <map>
#include <regex>
#include <string>
#include "../Player/Player.h"

class Route;
using namespace std;
class Player;
class Region;

enum map_shape { L_SHAPE, RECTANGLE, LONG_RECTANGLE };
enum region_connection { TOP, BOTTOM, LEFT, RIGHT };
enum route_type { LAND, WATER };

class Region // vertex
{
public:
	typedef map<string, Region*> adjacency;
	// constructors and destructor
	Region(string);
	// Region(Region&);
	// Region& operator=(Region const&);
	~Region();
	
	// Getters
	adjacency get_adjacency() { return adj_; }
	string get_name() const { return name_; }

	void add_adjacency(string, Region*);
	
//#ifdef PLAYER_H
	vector<Player*> get_controlling_player() const { return controlling_player_; };
	vector<pair<Player*, int>> get_occupying_armies() const { return occupying_armies_; };

	// Functions
	int get_number_of_armies(Player*);
	void set_player_with_most_armies();
	void update_armies_to_region(Player*);
//#endif
	adjacency adj_;

private:
//#ifdef PLAYER_H
	vector<pair<Player*, int>> occupying_armies_;
	vector<Player*> controlling_player_;
//#endif
	string name_;
	// Function
//#ifdef PLAYER_H
	void add_controlling_player(Player*);
//#endif
};

class MapTile
{
public:
	//data
	typedef map<string, Region*> v_map;
	typedef map<region_connection, Region*> connection_regions;
	typedef map<Region*, pair<Region*, route_type>> map_route;
	map_route m_route_;
	string tile_name;
	v_map m_map_;
	connection_regions c_regions_;

	// constructors and destructor
	MapTile(string);
	MapTile(MapTile&);
	MapTile& operator=(MapTile const&);
	~MapTile() = default;
	
	// functions
	void add_region(string); // add an vertex
	void add_connection_region(string, region_connection); // add an vertex
	void add_route(string, string, route_type); // add an edge
	bool validate();	
};

class WorldMap
{
public:
	// data
	enum map_shape m_shape;
	typedef map<string, Region*> v_map;
	typedef map<region_connection, Region*> connection_regions;
	typedef map<Region*, pair<Region*, route_type>> map_route;

	map_route m_route;
	v_map m_map;
	connection_regions c_regions;

	// constructors and destructor
	WorldMap();
	WorldMap(const map_shape, MapTile&, MapTile&, MapTile&);
	WorldMap(const map_shape, MapTile&, MapTile&, MapTile&, MapTile&);
	// WorldMap(WorldMap&);
	// WorldMap& operator=(WorldMap const&);
	~WorldMap();

	//getters
	MapTile* get_tile1() const { return tile1_; }
	MapTile* get_tile2() const { return tile2_; }
	MapTile* get_tile3() const { return tile3_; }
	MapTile* get_tile4() const { return tile4_; }

	
	// functions
	void print_world_map();
	void print_world_adjacency_map();
	void add_route(string, string, route_type); // add an edge
	bool validate();

private:
	MapTile* tile1_;
	MapTile* tile2_;
	MapTile* tile3_;
	MapTile* tile4_;
};
