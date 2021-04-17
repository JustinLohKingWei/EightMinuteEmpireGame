#include <algorithm>
#include "Map.h"

using namespace std;

//=======================================================================================================

Region::Region()
{
	name_ = " ";
}


Region::Region(string& s) : name_(move(s)) {}

Region::~Region()
{
	for (auto& x : adj_)
	{
		x.second.first = nullptr;
	}
}

#ifdef PLAYER_H
int Region::get_number_of_armies(Player *player)
{
	for (auto &p : occupying_armies_)
	{
		if (p.first->getFirstName() == player->getFirstName() && p.first->getLastName() == player->getLastName())
		{
			return p.second;
		}
	}
	std::cout << "The player could not be found!" << endl;
	std::exit(-1);
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

void Region::update_armies_to_region(Player* player) // End of player's turn/End of Round
{
	int armies = 0;
	for (auto* p_region: player->getListOfArmy())
	{
		Region *r_region = nullptr;
		for (auto* count_region : player->getListOfArmy())
		{
			if (p_region->aRegion == count_region->aRegion)
			{
				armies++;
			}
		}
		if (armies > 0)
		{
			if (occupying_armies_.empty())
			{
				pair<Player*, int> temp(player, armies);
				occupying_armies_.emplace_back (temp);
			}
			else
			{
				for (auto& p_player : occupying_armies_)
				{
					if (p_player.first->getFirstName() == player->getFirstName() && p_player.first->getLastName() == player->getLastName())
					{
						p_player.second = armies;
					}
					else
					{
						std::cout << "The player could not be found!" << endl;
						std::exit(-1);
					}
				}
			}
		}
	}
}

void Region::add_controlling_player(Player *player)
{
	controlling_player_.push_back(player);
}
#endif PLAYER_H
//=======================================================================================================

MapTile::MapTile()
{
	tile_name = " ";
}

MapTile::MapTile(string s) : tile_name(move(s)) {}

MapTile::MapTile(MapTile& copy)
{
	this->tile_name = copy.tile_name;
	this->m_map_ = copy.get_map();
	this->c_regions_ = copy.get_connections();
}

MapTile& MapTile::operator=(MapTile const& copy)
{
	this->tile_name = copy.tile_name;
	this->m_map_ = copy.get_map();
	this->c_regions_ = copy.get_connections();
	return *this;
}

//MapTile::~MapTile()
//{
//	for(auto x : m_map_)
//	{
//		x.second = nullptr;
//	}
//	for(auto x: c_regions_)
//	{
//		x.second = nullptr;
//	}
//}

// adapted from graph slides from class
void MapTile::add_region(string name)
{
	const auto itr = m_map_.find(name);
	if (itr == m_map_.end())
	{
		auto* r = new Region(name);
		m_map_.emplace(r->get_name(), r);
	}
	else
	{
		std::cout << "The Region " << name << " already exists!" << endl;
	}
}

void MapTile::add_connection_region(string name, region_connection direction) // replace add_region when Region has a outside connection!!!
{
	const auto itr = m_map_.find(name);
	if (itr == m_map_.end())
	{
		auto* r = new Region(name);
		m_map_.emplace(r->get_name(), r);
		c_regions_.emplace(direction, r);
	}
	else
	{
		c_regions_.emplace(direction, m_map_[name]);
	}
}

// adapted from graph slides from class
void MapTile::add_route(string start, string end, route_type type)
{
	const auto itr_s = m_map_.find(start);
	const auto itr_e = m_map_.find(end);
	const auto itr_end = m_map_.end();

	if (itr_s == itr_end || itr_e == itr_end)
	{
		std::cout << "\nThe starting and/or ending Region does not exists!" << endl;
	}
	else
	{
		m_map_[start]->get_adjacency().insert(make_pair(end, make_pair(this->get_map()[end], type)));
		m_map_[end]->get_adjacency().insert(make_pair(start, make_pair(this->get_map()[start], type)));
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
		for (auto& y: x.second->get_adjacency())
		{
			if(y.second.first->get_adjacency().find(x.first) == y.second.first->get_adjacency().end())
			{
				cout << "\nERROR: Could not find back and fourth connection between the regions " << x.first << " and " << y.first << endl;
				cout << "MapTile is validate!" << endl;
				return false;
			}
		}
	}

	if (c_regions_.size() != 4)
	{
		cout << "\nERROR: The connection_regions data is of incorrect size: " << c_regions_.size() << endl;
		cout << "MapTile is validate!" << endl;
		return false;
	}

	// TODO
	// BFS connection search
	
	return true;
}

//=======================================================================================================

WorldMap::WorldMap()
{
	m_shape = L_SHAPE;
}

WorldMap::WorldMap(const map_shape shape, MapTile& t1, MapTile& t2, MapTile& t3) : m_shape(shape)
{
	//if (t1.validate() && t2.validate() && t3.validate())
	//{
		for (auto& x : t1.get_map())
		{
			m_map.insert(x);
		}

		for (auto& x : t2.get_map())
		{
			m_map.insert(x);
		}

		for (auto& x : t3.get_map())
		{
			m_map.insert(x);
		}
	//}
	//else
	//{
	//	cout << "\nERROR: A MapTile is invalidate!" << endl;
	//	exit(-1);
	//}
		
	if (shape == LONG_RECTANGLE)
	{
		if (t1.get_connections()[RIGHT] != nullptr && t2.get_connections()[LEFT] != nullptr)
		{
			add_route(t1.get_connections()[RIGHT]->get_name(), t2.get_connections()[LEFT]->get_name(), WATER);
			add_route(t2.get_connections()[LEFT]->get_name(), t1.get_connections()[RIGHT]->get_name(), WATER);

			if (t2.get_connections()[RIGHT] != nullptr && t3.get_connections()[LEFT] != nullptr)
			{
				add_route(t2.get_connections()[RIGHT]->get_name(), t3.get_connections()[LEFT]->get_name(), WATER);
				add_route(t3.get_connections()[LEFT]->get_name(), t2.get_connections()[RIGHT]->get_name(), WATER);
			}
		}
	}
	else if (shape == L_SHAPE)
	{
		if (t1.get_connections()[BOTTOM] != nullptr && t2.get_connections()[TOP] != nullptr)
		{
			add_route(t1.get_connections()[BOTTOM]->get_name(), t2.get_connections()[TOP]->get_name(), WATER);
			add_route(t2.get_connections()[TOP]->get_name(), t1.get_connections()[BOTTOM]->get_name(), WATER);
			
			if (t2.get_connections()[RIGHT] != nullptr && t3.get_connections()[LEFT] != nullptr)
			{
				add_route(t2.get_connections()[RIGHT]->get_name(), t3.get_connections()[LEFT]->get_name(), WATER);
				add_route(t3.get_connections()[LEFT]->get_name(), t2.get_connections()[RIGHT]->get_name(), WATER);
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
	//if (t1.validate() && t2.validate() && t3.validate() && t4.validate())
	//{
		for (auto& x : t1.get_map())
		{
			m_map.insert(x);
		}

		for (auto& x : t2.get_map())
		{
			m_map.insert(x);
		}

		for (auto& x : t3.get_map())
		{
			m_map.insert(x);
		}

		for (auto& x : t4.get_map())
		{
			m_map.insert(x);
		}
	//}
	//else
	//{
	//	cout << "\nERROR: A MapTile is invalidate!" << endl;
	//	exit(-1);
	//}
	
	if (shape == RECTANGLE)
	{
		if (t1.get_connections()[RIGHT] != nullptr && t2.get_connections()[LEFT] != nullptr)
		{
			add_route(t1.get_connections()[RIGHT]->get_name(), t2.get_connections()[LEFT]->get_name(), WATER);
			add_route(t2.get_connections()[LEFT]->get_name(), t1.get_connections()[RIGHT]->get_name(), WATER);
			if (t2.get_connections()[RIGHT] != nullptr && t3.get_connections()[LEFT] != nullptr)
			{
				add_route(t2.get_connections()[RIGHT]->get_name(), t3.get_connections()[LEFT]->get_name(), WATER);
				add_route(t3.get_connections()[LEFT]->get_name(), t2.get_connections()[RIGHT]->get_name(), WATER);

				if (t3.get_connections()[RIGHT] != nullptr && t4.get_connections()[LEFT] != nullptr)
				{
					add_route(t3.get_connections()[RIGHT]->get_name(), t4.get_connections()[LEFT]->get_name(), WATER);
					add_route(t4.get_connections()[LEFT]->get_name(), t3.get_connections()[RIGHT]->get_name(), WATER);
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

//void MapTile&::print_map()
//{
//	for (auto &x : m_map)
//	{
//		std::cout << "\n" << x.first << endl;
//	}
//}
//
//void MapTile&::print_map_adjacency()
//{
//	for (auto &x : m_map)
//	{
//		std::cout << "\n" << x.first << " has the following adjacency: " << endl;
//		for (auto &y : x.second->adj_)
//		{
//			std::cout << y.first << endl;
//		}
//		std::cout << endl;
//	}
//}

// adapted from graph slides from class
void WorldMap::add_route(string start, string end, route_type type)
{
	const auto itr_s = m_map.find(start);
	const auto itr_e = m_map.find(end);

	if ( itr_s == m_map.end() || itr_e == m_map.end())
	{
		std::cout << "\nThe starting and/or ending Region does not exists!" << endl;
	}
	else
	{
		m_map[start]->get_adjacency().insert(make_pair(end, make_pair(m_map[end], type)));
		m_map[end]->get_adjacency().insert(make_pair(start, make_pair(m_map[start], type)));
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
