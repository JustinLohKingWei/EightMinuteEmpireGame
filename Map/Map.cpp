#include <algorithm>
#include "Map.h"

#include <iostream>

using namespace std;

//=======================================================================================================
Region::Region(string s) : name_(move(s)) {}

Region::~Region()
{
	for (auto& x : adj_)
	{
		x.second = nullptr;
	}
}

//#ifdef PLAYER_H
int Region::get_number_of_armies(Player *player)
{
	
	for (auto &p : occupying_armies_)
	{
		if (p.first->getFirstName() == player->getFirstName() && p.first->getLastName() == player->getLastName())
		{
			return p.second;
		}
	}
	if (occupying_armies_.empty()) {
		return 0;
	}
	else {
		std::cout << "The player could not be found!2" << endl;
		std::exit(-1);
	}
}
//PLEASE DO NOT CHANGE THIS CODE
void Region::update_armies_to_region(Player* player) // End of player's turn/End of Round
{
	int armies = 0;
	bool found = false;
	for (auto* p_region: player->getListOfArmy())
	{
		Region *r_region = nullptr;
		r_region = p_region->aRegion;
		
		if (this == r_region)
		{
			armies++;
		}
		
		if (armies > 0)
		{
			pair<Player*, int>temp(player, armies);
			occupying_armies_.push_back(temp);
			
			for (auto& p_player : occupying_armies_)
			{
				if (p_player.first->getFirstName() == player->getFirstName() && p_player.first->getLastName() == player->getLastName())
				{
					p_player.second = armies;
					found = true;
					break;
				}
			}
			if (found == false) {
				std::cout << "The player could not be found!1" << endl;
				std::exit(-1);
			}
		}
	}
}


void Region::set_player_with_most_armies()
{
	occupying_armies_.clear(); // reset be for use
	vector<pair<Player *, int>> temp;

	if (occupying_armies_.size() == 2) // number of players is 2 on the Region
	{
		if (occupying_armies_[0].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[0].second > occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else // equal army numbers
		{
			add_controlling_player(occupying_armies_[0].first);
			add_controlling_player(occupying_armies_[1].first);
		}
	}
	else if (occupying_armies_.size() == 3) // number of players is 3 on the Region
	{
		if (occupying_armies_[0].second < occupying_armies_[1].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[1].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[0].second == occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[0].second == occupying_armies_[1].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else
		{
			std::cout << "Something went wrong in set_player_with_most_armies(), size 3!" << endl;
			std::exit(-1);
		}
	}
	else if (occupying_armies_.size() == 4) // Why no for loop, because! that's why!
	{
		if (occupying_armies_[0].second < occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[1].second < occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[0].second < occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[1].second < occupying_armies_[3].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second < occupying_armies_[3].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[3].second < occupying_armies_[1].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[0].second < occupying_armies_[1].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[1].second < occupying_armies_[0].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[3].second < occupying_armies_[0].second < occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[3].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[3].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[3].second < occupying_armies_[2].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[3].second < occupying_armies_[0].second < occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[3].second < occupying_armies_[1].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[3].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[3].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[3].second < occupying_armies_[2].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[1].second < occupying_armies_[2].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second < occupying_armies_[2].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[2].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[1].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[1].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[0].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[0].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[0].second < occupying_armies_[1].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[2].second < occupying_armies_[1].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[1].second < occupying_armies_[0].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[2].second < occupying_armies_[0].second == occupying_armies_[2].second)
		{
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[3].second < occupying_armies_[0].second == occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[2].second < occupying_armies_[0].second == occupying_armies_[1].second)
		{
			add_controlling_player(occupying_armies_[1].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[0].second < occupying_armies_[1].second == occupying_armies_[2].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[1].second < occupying_armies_[0].second == occupying_armies_[2].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else if (occupying_armies_[2].second < occupying_armies_[1].second == occupying_armies_[0].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[0].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[3].second < occupying_armies_[1].second == occupying_armies_[2].second == occupying_armies_[0].second)
		{
			add_controlling_player(occupying_armies_[0].first);
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
		}
		else if (occupying_armies_[0].second == occupying_armies_[1].second == occupying_armies_[2].second == occupying_armies_[3].second)
		{
			add_controlling_player(occupying_armies_[3].first);
			add_controlling_player(occupying_armies_[2].first);
			add_controlling_player(occupying_armies_[1].first);
			add_controlling_player(occupying_armies_[0].first);
		}
		else
		{
			std::cout << "Something went wrong in set_player_with_most_armies(), size 4!" << endl;
			std::exit(-1);
		}
	}
	else
	{
		std::cout << "Something went wrong in set_player_with_most_armies(), size unknown!" << endl;
		std::exit(-1);
	}
}

void Region::add_controlling_player(Player *player)
{
	controlling_player_.push_back(player);
}
//#endif

void Region::add_adjacency(string s, Region* r)
{
	adj_.emplace(make_pair(s, r));
}


//=======================================================================================================


MapTile::MapTile(string s) : tile_name(move(s)) {}

MapTile::MapTile(MapTile& copy)
{
	this->tile_name = copy.tile_name;
	this->m_map_ = copy.m_map_;
	this->c_regions_ = copy.c_regions_;
}

MapTile& MapTile::operator=(MapTile const& copy)
{
	this->tile_name = copy.tile_name;
	this->m_map_ = copy.m_map_;
	this->c_regions_ = copy.c_regions_;
	return *this;
}

// adapted from graph slides from class
void MapTile::add_region(string name)
{
	const auto itr = m_map_.find(name);
	if (itr == m_map_.end())
	{
		auto* r = new Region(name);
		m_map_.insert(make_pair(r->get_name(), r));
//#ifdef MAPDEBUG
		cout << "The Region " << name << " has been created!" << endl;
//#endif
		
	}
	else
	{
		cout << "The Region " << name << " already exists!" << endl;
	}
}

void MapTile::add_connection_region(string name, region_connection direction) // replace add_region when Region has a outside connection!!!
{
	const auto itr = m_map_.find(name);
	if (itr == m_map_.end())
	{
		auto* r = new Region(name);
		m_map_.insert(make_pair(r->get_name(), r));
		c_regions_.insert(make_pair(direction, r));
//#ifdef MAPDEBUG
		cout << "The Region " << name << " has been created!" << endl;
//#endif
	}
	else
	{
		c_regions_.insert(make_pair(direction, m_map_[name]));
//#ifdef MAPDEBUG
		cout << "\nThe Region " << name << " has been created!" << endl;
//#endif
	}
}

//=======================================================================================================

// adapted from graph slides from class
void MapTile::add_route(string start, string end, route_type type)
{
	const auto itr_s = m_map_.find(start);
	const auto itr_e = m_map_.find(end);
	const auto itr_end = m_map_.end();

//#ifdef MAPDEBUG
	cout << "\nTrying to add the Route from " << start << " to " << end << "!" << endl;
//#endif
	
	if (itr_s == itr_end || itr_e == itr_end)
	{
		std::cout << "\nThe starting and/or ending Region does not exists!" << endl;
	}
	else
	{
		itr_s->second->add_adjacency(end, m_map_[end]);
		itr_e->second->add_adjacency(start, m_map_[start]);
		m_route_.insert(make_pair(m_map_[start], make_pair(m_map_[end], type)));
		m_route_.insert(make_pair(m_map_[end], make_pair(m_map_[start], type)));
		
//#ifdef MAPDEBUG
		cout << "\nThe Route from " << start << " to " << end << " has been created!" << endl;
//#endif
	}
}

bool MapTile::validate()
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a Region to itself

	std::cout << "\nStarting map Validation ...";
	
	// check back and fourth connections
	
	for (auto& x : m_map_)
	{
		for (auto& y: x.second->adj_)
		{
			auto itr = y.second->adj_.find(x.first);
			if(itr == y.second->adj_.end())
			{
				cout << "\nERROR: Could not find back and fourth connection between the regions " << x.first << " and " << y.first << endl;
				cout << "MapTile is validate!" << endl;
				return false;
			}
		}
	}

	// TODO
	// BFS connection search, skipping for time
	
	return true;
}

//=======================================================================================================

WorldMap::WorldMap()
{
	m_shape = L_SHAPE;
}

WorldMap::WorldMap(const map_shape shape, MapTile& t1, MapTile& t2, MapTile& t3) : m_shape(shape)
{
	if (t1.validate() && t2.validate() && t3.validate())
	{
		for (auto& x : t1.m_map_)
		{
			m_map.insert(x);
		}
		for (auto& x : t2.m_map_)
		{
			m_map.insert(x);
		}
		for (auto& x : t3.m_map_)
		{
			m_map.insert(x);
		}
		
		for (auto& x : t1.m_route_)
		{
			m_route.emplace(x);
		}
		for (auto& x : t2.m_route_)
		{
			m_route.emplace(x);
		}
		for (auto& x : t3.m_route_)
		{
			m_route.emplace(x);
		}
	}
	else
	{
		cout << "\nERROR: A MapTile is invalidate!" << endl;
		exit(-1);
	}
		
	if (shape == LONG_RECTANGLE)
	{
		if (t1.c_regions_[RIGHT] != nullptr && t2.c_regions_[LEFT] != nullptr)
		{
			add_route(t1.c_regions_[RIGHT]->get_name(), t2.c_regions_[LEFT]->get_name(), WATER);
			add_route(t2.c_regions_[LEFT]->get_name(), t1.c_regions_[RIGHT]->get_name(), WATER);

			if (t2.c_regions_[RIGHT] != nullptr && t3.c_regions_[LEFT] != nullptr)
			{
				add_route(t2.c_regions_[RIGHT]->get_name(), t3.c_regions_[LEFT]->get_name(), WATER);
				add_route(t3.c_regions_[LEFT]->get_name(), t2.c_regions_[RIGHT]->get_name(), WATER);
			}
		}
	}
	else if (shape == L_SHAPE)
	{
		if (t1.c_regions_[BOTTOM] != nullptr && t2.c_regions_[TOP] != nullptr)
		{
			add_route(t1.c_regions_[BOTTOM]->get_name(), t2.c_regions_[TOP]->get_name(), WATER);
			add_route(t2.c_regions_[TOP]->get_name(), t1.c_regions_[BOTTOM]->get_name(), WATER);
			
			if (t2.c_regions_[RIGHT] != nullptr && t3.c_regions_[LEFT] != nullptr)
			{
				add_route(t2.c_regions_[RIGHT]->get_name(), t3.c_regions_[LEFT]->get_name(), WATER);
				add_route(t3.c_regions_[LEFT]->get_name(), t2.c_regions_[RIGHT]->get_name(), WATER);
			}
		}
	}
	else
	{
		std::cout << "ERROR: The connection regions have not been set up in the sub graphs!" << endl;
		std::exit(-1);
	}
}

WorldMap::WorldMap(const map_shape shape, MapTile &t1, MapTile &t2, MapTile &t3, MapTile &t4) :  m_shape(shape)
{
	if (t1.validate() && t2.validate() && t3.validate() && t4.validate())
	{
		for (auto& x : t1.m_map_)
		{
			m_map.insert(x);
		}
		for (auto& x : t2.m_map_)
		{
			m_map.insert(x);
		}
		for (auto& x : t3.m_map_)
		{
			m_map.insert(x);
		}
		for (auto& x : t4.m_map_)
		{
			m_map.insert(x);
		}

		for (auto& x : t1.m_route_)
		{
			m_route.emplace(x);
		}
		for (auto& x : t2.m_route_)
		{
			m_route.emplace(x);
		}
		for (auto& x : t3.m_route_)
		{
			m_route.emplace(x);
		}
		for (auto& x : t4.m_route_)
		{
			m_route.emplace(x);
		}
	}
	else
	{
		cout << "\nERROR: A MapTile is invalidate!" << endl;
		exit(-1);
	}
	if (shape == RECTANGLE)
	{
		if (t1.c_regions_[RIGHT] != nullptr && t2.c_regions_[LEFT] != nullptr)
		{
			add_route(t1.c_regions_[RIGHT]->get_name(), t2.c_regions_[LEFT]->get_name(), WATER);
			add_route(t2.c_regions_[LEFT]->get_name(), t1.c_regions_[RIGHT]->get_name(), WATER);
			if (t2.c_regions_[RIGHT] != nullptr && t3.c_regions_[LEFT] != nullptr)
			{
				add_route(t2.c_regions_[RIGHT]->get_name(), t3.c_regions_[LEFT]->get_name(), WATER);
				add_route(t3.c_regions_[LEFT]->get_name(), t2.c_regions_[RIGHT]->get_name(), WATER);

				if (t3.c_regions_[RIGHT] != nullptr && t4.c_regions_[LEFT] != nullptr)
				{
					add_route(t3.c_regions_[RIGHT]->get_name(), t4.c_regions_[LEFT]->get_name(), WATER);
					add_route(t4.c_regions_[LEFT]->get_name(), t3.c_regions_[RIGHT]->get_name(), WATER);
				}
			}
		}
	}
	else
	{
		std::cout << "ERROR: The connection regions have not been set up in the sub graphs!" << endl;
		std::exit(-1);
	}
}

WorldMap::~WorldMap()
{
	for (auto &x : m_map)
	{
		delete x.second;
	}
	tile1_ = nullptr;
	tile2_ = nullptr;
	tile3_ = nullptr;
	tile4_ = nullptr;
}

// TODO
// Stream operator

void WorldMap::print_world_map()
{
	cout << "Regions in the world map:" << endl;
	
	for (auto &x : m_map)
	{
		std::cout << "\n" << x.first << endl;
	}
}

void WorldMap::print_world_adjacency_map()
{
	for (auto &x : m_map)
	{
		std::cout << "\n" << x.first << " has the following adjacency:" << endl;
		for (auto &y : x.second->get_adjacency())
		{
			std::cout << "Adjacent Region - " << y.first << endl;
		}
		std::cout << endl;
		std::cout << endl;
	}
}

// adapted from graph slides from class
void WorldMap::add_route(string start, string end, route_type type)
{
	const auto itr_s = m_map.find(start);
	const auto itr_e = m_map.find(end);

//#ifdef MAPDEBUG
	cout << "\nTrying to add the Route from " << start << " to " << end << "!" << endl;
//#endif
	
	if ( itr_s == m_map.end() || itr_e == m_map.end())
	{
		std::cout << "\nThe starting and/or ending Region does not exists!" << endl;
	}
	{
		m_map[start]->adj_.insert(make_pair(end, m_map[end]));
		m_map[end]->adj_.insert(make_pair(start, m_map[start]));
		m_route.insert(make_pair(m_map[start],make_pair(m_map[end], type)));
		m_route.insert(make_pair(m_map[end], make_pair(m_map[start], type)));
//#ifdef MAPDEBUG
		cout << "\nThe Route from " << start << " to " << end << " has been created!" << endl;
//#endif
	}
}

bool WorldMap::validate()
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a Region to itself

	//std::cout << "\nStarting map Validation ...";

	if ((get_tile1()->validate()&& get_tile2()->validate() && get_tile3()->validate() && get_tile4()->validate()) == false)
	{
		return false;
	}

	// TODO
	// shape check

	// TODO
	// connection check
	
	return true;
}

//=======================================================================================================
