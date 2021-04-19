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

using namespace std;

class WorldMap;
class Route;
class Region;
class Player;

enum map_shape { L_SHAPE, RECTANGLE, LONG_RECTANGLE };
enum region_connection { TOP, BOTTOM, LEFT, RIGHT };
enum route_type { LAND, WATER };

class Region // vertex
{
public:
	typedef map<string, Region*> adjacency;
	adjacency adj_;
	
	// constructors and destructor
	Region(string);
	// Region(Region&);
	// Region& operator=(Region const&);
	~Region();
	
	// Getters
	adjacency get_adjacency() { return adj_; }
	string get_name() const { return name_; }

	void add_adjacency(string, Region*);
	
#ifdef PLAYER_H
	vector<Player*> get_controlling_player() const { return controlling_player_; }
	vector<Player*> get_controlling_victory_points() const { return controlling_victory_points_; }
	vector<pair<Player*, int>> get_occupying_armies() const { return occupying_armies_; }
	vector<pair<Player*, int>> get_occupying_victory_points() const { return occupying_victory_points_; }

	// Functions
	int get_number_of_armies(Player*);
	int get_number_of_army_points(Player*);
	void set_player_with_most_armies();
	void set_player_with_most_army_points();
	void update_armies_to_region(Player*);
	void update_victory_points_to_region(Player*);
#endif
	
private:
#ifdef PLAYER_H
	vector<pair<Player*, int>> occupying_armies_;
	vector<pair<Player*, int>> occupying_victory_points_;
	vector<Player*> controlling_player_;
	vector<Player*> controlling_victory_points_;
#endif
	string name_;
	// Function
#ifdef PLAYER_H
	void add_controlling_player(Player*);
	void add_controlling_victory_points(Player*);
#endif
};

class MapTile
{
public:
	friend WorldMap;
	//data
	typedef map<string, Region*> v_map;
	typedef map<region_connection, Region*> connection_regions;
	typedef map<Region*, pair<Region*, route_type>> map_route;
	map_route m_route_;
	string tile_name;
	v_map m_map_;
	connection_regions c_regions_;

	// getters
	int get_region_num() const { return num_regions; }
	
	// constructors and destructor
	MapTile(string);
	MapTile(MapTile&);
	// MapTile& operator=(MapTile const&);
	~MapTile() = default;
	
	// functions
	void add_region(string); // add an vertex
	void add_connection_region(string, region_connection); // add an vertex
	void add_route(string, string, route_type); // add an edge
	bool validate();
private:
	int num_regions = 0;
	// setter
	void add_to_region_num() { num_regions++; }
	
};

class WorldMap
{
public:
	friend MapTile;
	// data
	enum map_shape m_shape;
	typedef map<string, Region*> v_map;
	typedef map<region_connection, Region*> connection_regions;
	typedef map<Region*, pair<Region*, route_type>> map_route;

	map_route m_route;
	v_map m_map;
	connection_regions c_regions;

	MapTile* tile1_;
	MapTile* tile2_;
	MapTile* tile3_;
	MapTile* tile4_;

	// constructors and destructor
	WorldMap();
	WorldMap(const map_shape, MapTile*, MapTile*, MapTile*);
	WorldMap(const map_shape, MapTile*, MapTile*, MapTile*, MapTile*);
	// WorldMap(WorldMap&);
	// WorldMap& operator=(WorldMap const&);
	~WorldMap();

	// functions
	void print_world_map();
	void print_world_adjacency_map();
	void add_route(string, string, route_type); // add an edge
	bool validate();
};
