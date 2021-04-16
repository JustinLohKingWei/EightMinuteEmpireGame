// code adapter from examples of graphs given out as part of COMP 345 slides
#pragma once

#include <map>
#include <regex>
#include <string>
#include <vector>
#include "../Player/Player.h"

using namespace std;
class Player;
class Region;

enum map_shape { L_SHAPE, RECTANGLE, LONG_RECTANGLE };
enum region_connection { TOP, BOTTOM, LEFT, RIGHT };
enum route_type { LAND, WATER };

class Region // vertex
{
public:
	typedef map<string, pair<Region*, route_type>> adjacency;
	// constructors and destructor
	Region();
	Region(string&);
	// Region(Region&);
	// Region& operator=(Region const&);
	~Region();
	
	// Getters
	adjacency get_adjacency() const { return adj_; }
	string get_name() const { return name_; }
	#ifdef PLAYER_H
	vector<Player*> get_controlling_player() const { return controlling_player_; };
	vector<pair<Player*, int>> get_occupying_armies() const { return occupying_armies_; };

	// Functions
	int get_number_of_armies(Player*);
	void set_player_with_most_armies();
	void update_armies_to_region(Player*);
	#endif PLAYER_H
	
private:
	#ifdef PLAYER_H
	vector<pair<Player*, int>> occupying_armies_;
	vector<Player*> controlling_player_;
	#endif
	adjacency adj_;
	string name_;
	
	// Function
	#ifdef PLAYER_H
	void add_controlling_player(Player*);
	#endif PLAYER_H
};

class MapTile // graph, island, or world map
{
public:
	//data
	typedef map<string, Region*> v_map;
	typedef map<region_connection, Region*> connection_regions;
	string tile_name;
	v_map m_map_;
	connection_regions c_regions_;

	// constructors and destructor
	MapTile();
	MapTile(string);
	MapTile(MapTile&);
	MapTile& operator=(MapTile const&);
	~MapTile() = default;
	
	// getters
	v_map get_map() const { return m_map_; }
	connection_regions get_connections() const { return c_regions_;  }
	
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
	void add_route(string, string, route_type); // add an edge
	bool validate();

private:
	MapTile* tile1_;
	MapTile* tile2_;
	MapTile* tile3_;
	MapTile* tile4_;
};