#include <algorithm>
#include "Map.h"

using namespace std;

region::region(string s) : name(s) {}

region::~region()
{
	for (auto &x : adj)
	{
		x.second = nullptr;
	}
	std::cout << "\n"
			  << "Region named : " << name << " deleted!" << endl;
}

int region::get_number_of_armies(Player *player)
{
	for (auto &p : occuping_armies)
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

vector<pair<Player *, int>> region::get_occuping_armies()
{
	return occuping_armies;
}

void region::set_player_with_most_armies()
{
	occuping_armies.clear(); // reset be for use
	vector<pair<Player *, int>> temp;

	if (occuping_armies.size() == 2) // number of players is 2 on the region
	{
		if (occuping_armies[0].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[0].second > occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else // equal army numbers
		{
			add_controlling_player(occuping_armies[0].first);
			add_controlling_player(occuping_armies[1].first);
		}
	}
	else if (occuping_armies.size() == 3) // number of players is 3 on the region
	{
		if (occuping_armies[0].second < occuping_armies[1].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[0].second < occuping_armies[2].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[0].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[1].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[1].second < occuping_armies[2].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[0].second < occuping_armies[1].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[2].second < occuping_armies[0].second == occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[0].second == occuping_armies[1].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else
		{
			std::cout << "Something went wrong in set_player_with_most_armies(), size 3!" << endl;
			std::exit(-1);
		}
	}
	else if (occuping_armies.size() == 4) // Why no for loop, because! that's why!
	{
		if (occuping_armies[0].second < occuping_armies[1].second < occuping_armies[2].second < occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second < occuping_armies[2].second < occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
		}
		else if (occuping_armies[0].second < occuping_armies[2].second < occuping_armies[1].second < occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
		}
		else if (occuping_armies[2].second < occuping_armies[0].second < occuping_armies[1].second < occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
		}
		else if (occuping_armies[2].second < occuping_armies[1].second < occuping_armies[0].second < occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
		}
		else if (occuping_armies[1].second < occuping_armies[2].second < occuping_armies[0].second < occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
		}
		else if (occuping_armies[0].second < occuping_armies[1].second < occuping_armies[3].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second < occuping_armies[3].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[0].second < occuping_armies[3].second < occuping_armies[1].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[3].second < occuping_armies[0].second < occuping_armies[1].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[3].second < occuping_armies[1].second < occuping_armies[0].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[1].second < occuping_armies[3].second < occuping_armies[0].second < occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[0].second < occuping_armies[2].second < occuping_armies[3].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[0].second < occuping_armies[3].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[0].second < occuping_armies[3].second < occuping_armies[2].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[3].second < occuping_armies[0].second < occuping_armies[2].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[3].second < occuping_armies[2].second < occuping_armies[0].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[3].second < occuping_armies[0].second < occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[3].second < occuping_armies[1].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[3].second < occuping_armies[2].second < occuping_armies[1].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[2].second < occuping_armies[1].second < occuping_armies[3].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[1].second < occuping_armies[2].second < occuping_armies[3].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[1].second < occuping_armies[3].second < occuping_armies[2].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[3].second < occuping_armies[1].second < occuping_armies[2].second < occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[0].second < occuping_armies[1].second < occuping_armies[2].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second < occuping_armies[2].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[2].first);
		}
		else if (occuping_armies[2].second < occuping_armies[0].second < occuping_armies[1].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[0].second < occuping_armies[2].second < occuping_armies[1].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[1].second < occuping_armies[0].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[1].second < occuping_armies[2].second < occuping_armies[0].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[0].second < occuping_armies[1].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[0].second < occuping_armies[2].second < occuping_armies[1].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[2].second < occuping_armies[1].second < occuping_armies[0].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[1].second < occuping_armies[2].second < occuping_armies[0].second == occuping_armies[2].second)
		{
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[2].second < occuping_armies[3].second < occuping_armies[0].second == occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[3].second < occuping_armies[2].second < occuping_armies[0].second == occuping_armies[1].second)
		{
			add_controlling_player(occuping_armies[1].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[0].second < occuping_armies[1].second == occuping_armies[2].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[1].second < occuping_armies[0].second == occuping_armies[2].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[0].first);
		}
		else if (occuping_armies[2].second < occuping_armies[1].second == occuping_armies[0].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[0].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[3].second < occuping_armies[1].second == occuping_armies[2].second == occuping_armies[0].second)
		{
			add_controlling_player(occuping_armies[0].first);
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
		}
		else if (occuping_armies[0].second == occuping_armies[1].second == occuping_armies[2].second == occuping_armies[3].second)
		{
			add_controlling_player(occuping_armies[3].first);
			add_controlling_player(occuping_armies[2].first);
			add_controlling_player(occuping_armies[1].first);
			add_controlling_player(occuping_armies[0].first);
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

void region::set_armies_to_region(Player *player, int armies)
{
	pair<Player *, int> temp{player, armies};

	if (occuping_armies.empty())
	{
		occuping_armies.push_back(temp);
	}
	else
	{
		for (auto &p : occuping_armies)
		{
			if (p.first->getFirstName() == player->getFirstName() && p.first->getLastName() == player->getLastName())
			{
				p.second = armies;
			}
			else
			{
				if (occuping_armies.size() < 4)
				{
					occuping_armies.push_back(temp);
				}
				else
				{
					std::cout << "Something went wrong in set_player_with_most_armies(), size 3!" << endl;
					std::exit(-1);
				}
			}
		}
	}
}

vector<Player *> region::get_controlling_player()
{
	return controlling_player;
}

void region::add_controlling_player(Player *player)
{
	controlling_player.push_back(player);
}

game_map::game_map(string s) : map_name(s) {}

game_map::game_map(game_map *copy) // TODO
{
	if (map_name != "World Map" || map_name != "Copy of World Map")
	{
		map_name = ("Copy of " + copy->map_name);
		for (auto &x : copy->m_map)
		{
			m_map.emplace(x);
		}
		std::cout << "\n"
				  << "Map named : " << map_name << " copied!" << endl;
	}
	else // world map copy, only top level copies, bottom level links to original sub graphs, copy sub graphs with above!
	{
		if (map_name != "Copy of World Map") // != Suggested by clang-tidy
		{
			map_name = "Copy of " + copy->map_name;
			map_shape = copy->map_shape;
		}
		// else keep name of "Copy of World Map"

		for (auto &x : copy->m_map)
		{
			m_map.emplace(x); // emplace is a deep copy
		}
		std::cout << "\n"
				  << "Map named : " << map_name << " copied!" << endl;
	}
}

game_map::game_map(string map_shape_, game_map *tile1_, game_map *tile2_, game_map *tile3_) : // create world map
																							  map_name("World Map"), map_shape(std::move(map_shape_))
{
	for (auto &x : tile1_->m_map)
	{
		m_map.insert(x);
	}

	for (auto &x : tile2_->m_map)
	{
		m_map.insert(x);
	}

	for (auto &x : tile3_->m_map)
	{
		m_map.insert(x);
	}

	if (map_shape == "Long Rectangle")
	{
		auto itr_1 = tile1_->c_map.find(RIGHT);
		auto itr_2 = tile2_->c_map.find(LEFT);

		if (itr_1 != tile1_->c_map.end() && itr_2 != tile2_->c_map.end())
		{
			add_route(itr_1->second->name, itr_2->second->name);
			add_route(itr_2->second->name, itr_1->second->name);
			itr_1 = tile2_->c_map.find(RIGHT);
			itr_2 = tile3_->c_map.find(LEFT);

			if (itr_1 != tile2_->c_map.end() && itr_2 != tile3_->c_map.end())
			{
				add_route(itr_1->second->name, itr_2->second->name);
				add_route(itr_2->second->name, itr_1->second->name);
				std::cout << "\n"
						  << "Map named : " << map_name << " created" << endl;
			}
		}
	}
	else if (map_shape == "LShape")
	{
		auto itr_1 = tile1_->c_map.find(BOTTOM);
		auto itr_2 = tile2_->c_map.find(TOP);

		if (itr_1 != tile1_->c_map.end() && itr_2 != tile2_->c_map.end())
		{
			add_route(itr_1->second->name, itr_2->second->name);
			add_route(itr_2->second->name, itr_1->second->name);
			itr_1 = tile2_->c_map.find(RIGHT);
			itr_2 = tile3_->c_map.find(LEFT);

			if (itr_1 != tile2_->c_map.end() && itr_2 != tile3_->c_map.end())
			{
				add_route(itr_1->second->name, itr_2->second->name);
				add_route(itr_2->second->name, itr_1->second->name);
				std::cout << "\n"
						  << "Map named : " << map_name << " created" << endl;
			}
		}
		else
		{
		}
		std::cout << "The connection regions have not been set up in the sub graphs!" << endl;
		std::exit(-1);
	}
}

game_map::game_map(string map_shape_, game_map *tile1_, game_map *tile2_, game_map *tile3_, game_map *tile4_) : // create world map
																												map_name("World Map"), map_shape(std::move(map_shape_))
{
	for (auto &x : tile1_->m_map)
	{
		m_map.insert(x);
	}

	for (auto &x : tile2_->m_map)
	{
		m_map.insert(x);
	}

	for (auto &x : tile3_->m_map)
	{
		m_map.insert(x);
	}

	for (auto &x : tile4_->m_map)
	{
		m_map.insert(x);
	}

	if (map_shape == "Rectangle")
	{
		auto itr_1 = tile1_->c_map.find(RIGHT);
		auto itr_2 = tile2_->c_map.find(LEFT);
		if (itr_1 != tile1_->c_map.end() && itr_2 != tile2_->c_map.end())
		{
			add_route(itr_1->second->name, itr_2->second->name);
			add_route(itr_2->second->name, itr_1->second->name);
			itr_1 = tile2_->c_map.find(RIGHT);
			itr_2 = tile3_->c_map.find(LEFT);

			if (itr_1 != tile2_->c_map.end() && itr_2 != tile3_->c_map.end())
			{
				add_route(itr_1->second->name, itr_2->second->name);
				add_route(itr_2->second->name, itr_1->second->name);
				itr_1 = tile3_->c_map.find(RIGHT);
				itr_2 = tile4_->c_map.find(LEFT);

				if (itr_1 != tile3_->c_map.end() && itr_2 != tile4_->c_map.end())
				{
					add_route(itr_1->second->name, itr_2->second->name);
					add_route(itr_2->second->name, itr_1->second->name);
					std::cout << "\n"
							  << "Map named : " << map_name << " created" << endl;
				}
			}
		}
	}
	else
	{
		std::cout << "The connection regions have not been set up in the sub graphs!" << endl;
		std::exit(-1);
	}
}

game_map::~game_map()
{
	if (map_name != "World Map")
	{
		for (auto &x : m_map)
		{
			if (x.second != nullptr)
			{
				std::cout << "Not world map" << endl;
				delete x.second;
			}
		}
		std::cout << "\n"
				  << "Map named : " << map_name << " deleted!" << endl;
	}
	else
	{
		for (auto &x : m_map)
		{
			x.second = nullptr;
		}
		for (auto &x : c_map)
		{
			x.second = nullptr;
		}
		std::cout << "\n"
				  << "Map named : " << map_name << " deleted!" << endl;
	}
}

// adapted from graph slides from class
void game_map::add_region(const string &name)
{
	const auto itr = m_map.find(name);
	if (itr == m_map.end())
	{
		auto *r = new region(name);
		m_map[name] = r;
		return;
	}
	std::cout << "The region " << name << " already exists!" << endl;
}

void game_map::add_connection_region(const string &name, region_connection direction) // replace add_region when region has a outside connection!!!
{
	const auto itr = m_map.find(name);

	if (itr == m_map.end())
	{
		auto *r = new region(name);
		m_map[name] = r;
		c_map[direction] = r;
		return;
	}
	else
	{
		c_map[direction] = itr->second; // some regions have double outside connections
	}
	std::cout << "The region " << name << " already exists!" << endl;
}

// adapted from graph slides from class
// TODO add some error detection
void game_map::add_route(const string &start, const string &end)
{
	auto itr_s = m_map.find(start);
	auto itr_e = m_map.find(end);

	if (itr_s == m_map.end() || itr_e == m_map.end())
	{
		std::cout << "\nThe starting and/or ending region does not exists!" << endl;
		return;
	}
	else
	{
		itr_s = m_map[start]->adj.find(start);
		itr_e = m_map[end]->adj.find(end);

		if (itr_s == m_map[start]->adj.end())
		{
			m_map[start]->adj.insert(pair<string, region *>(end, m_map[end]));
		}
		if (itr_e == m_map[end]->adj.end())
		{
			m_map[end]->adj.insert(pair<string, region *>(start, m_map[start]));
		}
	}
}

void game_map::print_map()
{
	for (auto &x : m_map)
	{
		std::cout << "\n"
				  << x.first << endl;
	}
}

void game_map::print_map_adjacency()
{
	for (auto &x : m_map)
	{
		std::cout << "\n"
				  << x.first << " has the following adjacency: " << endl;
		for (auto &y : x.second->adj)
		{
			std::cout << y.first << endl;
		}
		std::cout << endl;
	}
}

void game_map::validate_map(game_map *my_map)
{
	// check that regional to and from connections are present in both regions
	// this will also finds connections from a region to itself

	std::cout << "\nStarting map Validation ...";

	for (auto &x : my_map->m_map)
	{
		for (auto &y : x.second->adj)
		{
			if (x.first != y.first) // != Suggested by clang-tidy
			{
				std::cout << "\nERROR: The regions " << x.first << " and " << y.first << " do not appear to have mutual connections!";
				std::cout << "\nThe map is invalid!" << endl;
			}
		}
	}
	std::cout << "\nIf no errors are printed, consider the regional listings of the map to be valid!" << endl
			  << endl;
}

// DUDE! NOT COOL!
void game_map::populateTile(string tileName)
{
	if (tileName.compare("C Shape Island"))
	{
		std::cout << "\nC Shape Island map tile has been created." << endl;

		// initialize "tile1" the center tile as depected on the first page of the rules
		for (auto i = 0; i < 5; ++i)
		{
			string s = "C Shape Island Region " + to_string(i + 1);
			this->add_region(s);
			std::cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, top to bottom, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("C Shape Island Region 1", "C Shape Island Region 2");
		this->add_route("C Shape Island Region 2", "C Shape Island Region 1");
		this->add_route("C Shape Island Region 2", "C Shape Island Region 3");
		this->add_route("C Shape Island Region 2", "C Shape Island Region 5");
		this->add_route("C Shape Island Region 3", "C Shape Island Region 2");
		this->add_route("C Shape Island Region 3", "C Shape Island Region 4");
		this->add_route("C Shape Island Region 4", "C Shape Island Region 3");
		this->add_route("C Shape Island Region 4", "C Shape Island Region 5");
		this->add_route("C Shape Island Region 5", "C Shape Island Region 4");
		this->add_route("C Shape Island Region 5", "C Shape Island Region 2");
	}
	else if (tileName.compare("Three Islands"))
	{
		std::cout << "\n\nThree Islands map tile has been created." << endl;

		// initialize "tile2" the right tile as depected on the first page of the rules
		for (auto i = 0; i < 3; ++i)
		{
			string s = "Three Islands Region " + to_string(i + 1);
			this->add_region(s);
			std::cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, top to bottom, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("Three Islands Region 1", "Three Islands Region 2");
		this->add_route("Three Islands Region 2", "Three Islands Region 1");
		this->add_route("Three Islands Region 2", "Three Islands Region 3");
		this->add_route("Three Islands Region 3", "Three Islands Region 2");
	}
	else if (tileName.compare("Stone Pillars Islands"))
	{
		std::cout << "\n\nStone Pillars Island map tile has been created." << endl;

		// initialize "tile3" the left tile as depected on the first page of the rules
		for (auto i = 0; i < 5; ++i)
		{
			string s = "Stone Pillars Island Region " + to_string(i + 1);
			this->add_region(s);
			std::cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, bottom to top, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("Stone Pillars Island Region 1", "Stone Pillars Island Region 2");
		this->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 1");
		this->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 3"); // 3 is region with houses
		this->add_route("Stone Pillars Island Region 2", "Stone Pillars Island Region 4"); // 4 is region with the pillars
		this->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 2");
		this->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 4");
		this->add_route("Stone Pillars Island Region 3", "Stone Pillars Island Region 5");
		this->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 2");
		this->add_route("Stone Pillars Island Region 4", "Stone Pillars Island Region 5");
		this->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 3");
		this->add_route("Stone Pillars Island Region 5", "Stone Pillars Island Region 4");
	}
	else if (tileName.compare("Valcano Island"))
	{
		std::cout << "\n\nValcano Island Island map tile has been created." << endl;

		// initialize "tile4" the top tile as depected on the first page of the rules
		for (auto i = 0; i < 7; ++i)
		{
			string s = "Valcano Island Region " + to_string(i + 1);
			this->add_region(s);
			std::cout << "\n Added a new area has been added: " << s << "." << endl;
		}

		// edges are initilized left to right, top to bottom, but they can be done in any way
		// edges added in both directions so that they appear in single reagion adjacency lists
		this->add_route("Valcano Island Region 1", "Valcano Island Region 2");
		this->add_route("Valcano Island Region 2", "Valcano Island Region 1");
		this->add_route("Valcano Island Region 2", "Valcano Island Region 3");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 2");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 4");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 5");
		this->add_route("Valcano Island Region 3", "Valcano Island Region 5");
		this->add_route("Valcano Island Region 4", "Valcano Island Region 3"); // region 4 is the furthest east(or south as it appears in the game manual) region
		this->add_route("Valcano Island Region 4", "Valcano Island Region 5");
		this->add_route("Valcano Island Region 5", "Valcano Island Region 3");
		this->add_route("Valcano Island Region 5", "Valcano Island Region 4");
		this->add_route("Valcano Island Region 6", "Valcano Island Region 3"); // region 6 is the bottom region on the disconnected smaller island
		this->add_route("Valcano Island Region 6", "Valcano Island Region 7");
		this->add_route("Valcano Island Region 7", "Valcano Island Region 6");
	}
