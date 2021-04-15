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
	for (auto & [x, y] : adj_)
	{
		y.first = nullptr;
	}
}

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
	return 0;
}

vector<pair<Player*, int >> Region::get_occupying_armies()
{
	return occupying_armies_;
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
		Region * r_region = nullptr;
		r_region = p_region->aRegion;
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

vector<Player *> Region::get_controlling_player() const
{
	return controlling_player_;
}

void Region::add_controlling_player(Player *player)
{
	controlling_player_.push_back(player);
}

//=======================================================================================================

MapTile::MapTile()
{
	tile_name = " ";
}

MapTile::MapTile(string& s) : tile_name(move(s)) {}

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

MapTile::~MapTile()
{
	for(auto [x, y] : m_map_)
	{
		delete y;
		y = nullptr;
	}
}

// adapted from graph slides from class
void MapTile::add_region(string& name)
{
	if (const auto itr = m_map_.find(name); itr == m_map_.end())
	{
		auto* r = new Region(name);
		m_map_[name] = r;
		return;
	}
	std::cout << "The Region " << name << " already exists!" << endl;
}

void MapTile::add_connection_region(string& name, region_connection direction) // replace add_region when Region has a outside connection!!!
{
	if (const auto itr = m_map_.find(name); itr == m_map_.end())
	{
		auto* r = new Region(name);
		m_map_[name] = r;
		c_regions_[direction] = r;
	}
	else
	{
		c_regions_[direction] = itr->second; // some regions have double outside connections
	}
}

// adapted from graph slides from class
void MapTile::add_route(string& start, string& end, enum route_type type)
{
	const auto itr_s = m_map_.find(start);

	if (const auto itr_e = m_map_.find(end); itr_s == m_map_.end() || itr_e == m_map_.end())
	{
		std::cout << "\nThe starting and/or ending Region does not exists!" << endl;
	}
	else
	{	
		if (itr_s->second->get_adjacency().find(start) == m_map_[start]->get_adjacency().end())
		{
			m_map_[start]->get_adjacency().insert(make_pair(end, make_pair(m_map_[end], type)));
		}
		if (itr_e->second->get_adjacency().find(end) == m_map_[end]->get_adjacency().end())
		{
			m_map_[end]->get_adjacency().insert(make_pair(start, make_pair(m_map_[start], type)));
		}
	}
}

bool MapTile::validate()
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a Region to itself

	std::cout << "\nStarting map Validation ...";
	bool check = true;
	
	// check back and fourth connections
	for (auto& [m_name, m_pointer] : m_map_)
	{
		for (auto& [p_name, p_pair]: m_pointer->get_adjacency())
		{
			if(p_pair.first->get_adjacency().find(m_name) == p_pair.first->get_adjacency().end())
			{
				cout << "\nERROR: Could not find back and fourth connection between the regions " << m_name << " and " << p_name << endl;
				cout << "MapTile is validate!" << endl;
				check = false;
			}
		}
	}

	if (c_regions_.size() != 4)
	{
		cout << "\nERROR: The connection_regions data is of incorrect size: " << c_regions_.size() << endl;
		cout << "MapTile is validate!" << endl;
		check = false;
	}

	// TODO
	// BFS connection search
	
	return check;
}

//=======================================================================================================

WorldMap::WorldMap()
{
	m_shape = L_SHAPE;
}

WorldMap::WorldMap(const enum map_shape shape, MapTile& t1, MapTile& t2, MapTile& t3) : m_shape(shape)
{
	if (t1.validate() && t2.validate() && t3.validate())
	{
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
	}
	else
	{
		cout << "\nERROR: A MapTile is invalidate!" << endl;
		exit(-1);
	}
	
	if (shape == LONG_RECTANGLE)
	{
		auto itr_1 = t1.get_connections().find(RIGHT);
		auto itr_2 = t2.get_connections().find(LEFT);

		if (itr_1 != t1.get_connections().end() && itr_2 != t2.get_connections().end())
		{
			add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
			add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
			itr_1 = t2.get_connections().find(RIGHT);
			itr_2 = t3.get_connections().find(LEFT);

			if (itr_1 != t2.get_connections().end() && itr_2 != t3.get_connections().end())
			{
				add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
				add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
			}
		}
	}
	else if (shape == L_SHAPE)
	{
		auto itr_1 = t1.get_connections().find(BOTTOM);
		auto itr_2 = t2.get_connections().find(TOP);

		if (itr_1 != t1.get_connections().end() && itr_2 != t2.get_connections().end())
		{
			add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
			add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
			itr_1 = t2.get_connections().find(RIGHT);
			itr_2 = t3.get_connections().find(LEFT);
			if (itr_1 != t2.get_connections().end() && itr_2 != t3.get_connections().end())
			{
				add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
				add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
			}
		}
	}
	else
	{
		std::cout << "ERROR: The connection regions have not been set up in the sub graphs!" << endl;
		std::exit(-1);
	}
}

WorldMap::WorldMap(const enum map_shape shape, MapTile &t1, MapTile &t2, MapTile &t3, MapTile &t4) :  m_shape(shape)
{
	if (t1.validate() && t2.validate() && t3.validate() && t4.validate())
	{
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
	}
	if (shape == RECTANGLE)
	{
		auto itr_1 = t1.get_connections().find(RIGHT);
		auto itr_2 = t2.get_connections().find(LEFT);
		if (itr_1 != t1.get_connections().end() && itr_2 != t2.get_connections().end())
		{
			add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
			add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
			itr_1 = t2.get_connections().find(RIGHT);
			itr_2 = t3.get_connections().find(LEFT);

			if (itr_1 != t2.get_connections().end() && itr_2 != t3.get_connections().end())
			{
				add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
				add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
				itr_1 = t3.get_connections().find(RIGHT);
				itr_2 = t4.get_connections().find(LEFT);

				if (itr_1 != t3.get_connections().end() && itr_2 != t4.get_connections().end())
				{
					add_route(itr_1->second->get_name(), itr_2->second->get_name(), WATER);
					add_route(itr_2->second->get_name(), itr_1->second->get_name(), WATER);
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
		if (x.second != nullptr)
		{
			std::cout << "Not world map" << endl;
			delete x.second;
		}
	}
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
void WorldMap::add_route(string& start, string& end, enum route_type type)
{
	const auto itr_s = m_map.find(start);

	if (const auto itr_e = m_map.find(end); itr_s == m_map.end() || itr_e == m_map.end())
	{
		std::cout << "\nThe starting and/or ending Region does not exists!" << endl;
	}
	else
	{
		if (itr_s->second->get_adjacency().find(start) == m_map[start]->get_adjacency().end())
		{
			m_map[start]->get_adjacency().insert(make_pair(end, make_pair(m_map[end], type)));
		}
		if (itr_e->second->get_adjacency().find(end) == m_map[end]->get_adjacency().end())
		{
			m_map[end]->get_adjacency().insert(make_pair(start, make_pair(m_map[start], type)));
		}
	}
}

bool WorldMap::validate()
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a Region to itself

	std::cout << "\nStarting map Validation ...";

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
