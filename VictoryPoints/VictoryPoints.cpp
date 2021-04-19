#include "VictoryPoints.h"

#include <iostream>
#include <vector>
#include <regex>
#include "../Player/Player.h"

using namespace std;

//int VPCounter::get_score(Player* player, WorldMap* world_map)
//{
//	int temp = compute_score(player, world_map);
//	auto iterator_p = scores_.find(player);
//	if (iterator_p != scores_.end())
//	{
//		return iterator_p->second;
//	}
//	else
//	{
//		cout << "The player could not be found!" << endl;
//		exit(-1);
//	}
//}

void VPCounter::add_player(Player* player)
{
	pair<Player*, int> temp(player, 0);
	scores_.insert(temp);
}
;

//void VPCounter::print_player_score(Player* player)
//{
//	auto iterator_p = scores_.find(player);
//	if (iterator_p != scores_.end())
//		cout << iterator_p->first->getFirstName() << " " << iterator_p->first->getLastName() << " has a score of " << iterator_p->second << endl;
//	else
//	{
//		cout << "The player could not be found!" << endl;
//		exit(-1);
//	}
//}

//void VPCounter::print_all_scores_()
//{
//	for (auto player : scores_)
//	{
//		auto iterator_p = scores_.find(player.first);
//		if (iterator_p != scores_.end())
//		{
//			cout << iterator_p->first->getFirstName() << " " << iterator_p->first->getLastName() << " has a score of " << iterator_p->second << endl;
//		}
//		else
//		{
//			cout << "The player could not be found!" << endl;
//			exit(-1);
//		}
//	}
//}

void VPCounter::reset_for_new_game()
{
	scores_.clear();
}

/**
* List of VP increasing conditions tracked via counter:
* +1 VP for ea. region.
* +1 VP for each Island.
* +VP for certain cards.
*/
int VPCounter::compute_score(Player* player, WorldMap* world_map)
{
	int region_points = 0;
	int tile_points = 0;
	int points_from_cards = 0;
	int noble_count = 0; // 3 max
	int cursed_count = 0; // 5 max
	int mountain_count = 0; // 2 max
	int dire_count = 0;
	int night_count = 0;
	int forest_count = 0;
	int arcane_count = 0;
	int ancient_count = 0;
	int flying_count = 0;
	int coin_count = 0;
	int coin_vp = 0;
	int vp_counter = 0;

	bool has_graveyard = false;
	bool has_stronghold = false;
	bool has_lake = false;
	bool has_ancient_sage = false;
	bool has_arcane_temple = false;
	bool has_night_wizard = false;
	bool has_dire_ogre = false;
	bool has_cursed_tower = false;

	// VP per region control
	
	auto search_regions = world_map->m_map;
	for (auto r_region : search_regions)
	{
		r_region.second->update_victory_points_to_region(player);
		vector<Player*> v_player = r_region.second->get_controlling_victory_points();
		if (!v_player.empty() && v_player.size() == 1)
		{
			if (v_player[0]->getFirstName() == player->getFirstName() && v_player[0]->getLastName() == player->getLastName())
			{
				region_points++;
			}
		}
	}
	
	// VP per tile control
	// Tile 1
	auto search_regions_t1 = world_map->tile1_->m_map_;
	for (auto& r_region : search_regions_t1)
	{
		if (r_region.second != nullptr)
		{
			int control = 0;
			r_region.second->update_victory_points_to_region(player);
			vector<Player*> v_player = r_region.second->get_controlling_victory_points();
			if (!v_player.empty())
			{
				for (auto x : v_player)
				{
					if (x == player)
					{
						control++;
					}
				}
			}
			if (control >= (world_map->tile1_->get_region_num() / 2) + 1)
			{
				tile_points++;
			}
		}
	}

	// Tile 2
	auto search_regions_t2 = world_map->tile2_->m_map_;
	for (auto& r_region : search_regions_t2)
	{
		int control = 0;
		r_region.second->update_victory_points_to_region(player);
		vector<Player*> v_player = r_region.second->get_controlling_victory_points();
		if (!v_player.empty())
		{
			for (auto x : v_player)
			{
				if (x == player)
				{
					control++;
				}
			}
		}
		if (control >= (world_map->tile2_->get_region_num() / 2) + 1)
		{
			tile_points = tile_points + 1;
		}
	}

	// Tile 3
	auto search_regions_t3 = world_map->tile3_->m_map_;
	for (auto& r_region : search_regions_t3)
	{
		int control = 0;
		r_region.second->update_victory_points_to_region(player);
		vector<Player*> v_player = r_region.second->get_controlling_victory_points();
		if (!v_player.empty())
		{
			for (auto x : v_player)
			{
				if (x == player)
				{
					control++;
				}
			}
		}
		if (control >= (world_map->tile3_->get_region_num() / 2) + 1)
		{
			tile_points = tile_points + 1;
		}
	}

	// Tile 4
	if (world_map->tile4_ != nullptr)
	{
		auto search_regions_t4 = world_map->tile4_->m_map_;
		for (auto& r_region : search_regions_t4)
		{
			int control = 0;
			r_region.second->update_victory_points_to_region(player);
			vector<Player*> v_player = r_region.second->get_controlling_victory_points();
			if (!v_player.empty())
			{
				for (auto x : v_player)
				{
					if (x == player)
					{
						control++;
					}
				}
			}
			if (control >= (world_map->tile4_->get_region_num() / 2) + 1)
			{
				tile_points = tile_points + 1;
			}
		}
	}

	// special cards
	if (!player->get_my_list_of_used_cards().empty())
	{
		vector<Card*> card_temp = player->get_my_list_of_used_cards();
		for (auto* c_card : card_temp)
		{
			if (regex_match(c_card->getName(), regex("(Graveyard)(.*)")))
			{
				has_graveyard = true;
				points_from_cards++;
			}
			else if (regex_match(c_card->getName(), regex("(Stronghold)(.*)")))
			{
				has_stronghold = true;
				points_from_cards++;
			}
			else if (regex_match(c_card->getName(), regex("(Lake)(.*)")))
			{
				has_lake = true;
				points_from_cards++;
			}
			else if (regex_match(c_card->getName(), regex("(Night Wizard)(.*)")))
			{
				has_night_wizard = true;
			}
			else if (regex_match(c_card->getName(), regex("(Arcane Temple)(.*)")))
			{
				has_arcane_temple = true;
			}
			else if (regex_match(c_card->getName(), regex("(Ancient Sage)(.*)")))
			{
				has_ancient_sage = true;
			}
			else if (regex_match(c_card->getName(), regex("(Dire Ogre)(.*)")))
			{
				has_dire_ogre = true;
			}
			else if (regex_match(c_card->getName(), regex("(Cursed Tower)(.*)")))
			{
				has_cursed_tower = true;
			}
		}
	}
	
	if (!player->get_my_list_of_used_cards().empty())
	{
		vector<Card*> card_temp = player->get_my_list_of_used_cards();
		for (auto* c_card : card_temp)
		{
			if (regex_match(c_card->getName(), regex("(Mountain)(.*)")))
			{
				mountain_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Noble)(.*)")))
			{
				noble_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Cursed)(.*)")) && has_graveyard)
			{
				cursed_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Dire)(.*)")) && has_stronghold)
			{
				dire_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Night)(.*)")) && has_night_wizard)
			{
				night_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Forest)(.*)")) && has_lake)
			{
				forest_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Ancient)(.*)")) && has_ancient_sage)
			{
				ancient_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Arcane)(.*)")) && has_arcane_temple)
			{
				arcane_count++;
			}
		}
		if (mountain_count == 2)
		{
			points_from_cards += 3;
		}
		if (noble_count == 3)
		{
			points_from_cards += 4;
		}
		points_from_cards = points_from_cards + cursed_count + dire_count + night_count + forest_count + ancient_count + arcane_count;

	}

	// separate flying check
	if (!player->get_my_list_of_used_cards().empty() && has_cursed_tower)
	{
		vector<Card*> card_temp = player->get_my_list_of_used_cards();
		for (auto* c_card : card_temp)
		{
			if (regex_match(c_card->getName(), regex("(Ancient Phoenix)(.*)")))
			{
				flying_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Arcane Sphinx)(.*)")))
			{
				flying_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Dire Dragon)(.*)")))
			{
				flying_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Dire Eye)(.*)")))
			{
				flying_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Cursed Gargoyles)(.*)")))
			{
				flying_count++;
			}
		}
		points_from_cards += flying_count;
	}

	if (has_dire_ogre)
	{
		coin_count = player->getBidingFacility()->getCopperCoins();
		coin_vp = coin_count / 3;
	}
	
	vp_counter = region_points + tile_points + points_from_cards + coin_vp;
	return vp_counter;
}

/**
* List of VP increasing conditions tracked via counter:
* +1 VP for each region. Control of a region counts if a players has the most armies (cities included) on a region, same amount of armies means no one controls the region
* (N/A Time limited) +1 VP for each Island. A Player controls an island if they control the most regions on that island.
* Ignoring some cards with +1vp for each addition card of same type condition due to time constrains (Arcane, Ancient, Dire, Night)
* Cursed Tower +1vp per flying ignored due to unsupported feature, to little time to implement.
*
*/
map<Player*, int> VPCounter::compute_score_end_of_game(WorldMap* world_map)
{
	int vp_counter = 0;

	// update elixirs
	for (auto player : scores_) {
		if (!player.first->get_my_list_of_used_cards().empty())
		{
			vector<Card*> card_temp = player.first->get_my_list_of_used_cards();
			for (auto* c_card : card_temp)
			{
				if (regex_match(c_card->getName(), regex("(Mountain Treasury)(.*)")))
				{
					if (elixirs.empty())
					{
						elixirs.insert(make_pair(player.first, 1));
					}
					else
					{
						elixirs[player.first] += 1;
					}
				}
				else if (regex_match(c_card->getName(), regex("(Cursed King)(.*)")))
				{
					if (elixirs.empty())
					{
						elixirs.insert(make_pair(player.first, 1));
					}
					else
					{
						elixirs[player.first] += 1;
					}
				}
				else if (regex_match(c_card->getName(), regex("(Cursed Banshee)(.*)")))
				{
					if (elixirs.empty())
					{
						elixirs.insert(make_pair(player.first, 2));
					}
					else
					{
						elixirs[player.first] += 2;
					}
				}
				else if (regex_match(c_card->getName(), regex("(Dire Goblin)(.*)")))
				{
					if (elixirs.empty())
					{
						elixirs.insert(make_pair(player.first, 1));
					}
					else
					{
						elixirs[player.first] += 1;
					}
				}
				else if (regex_match(c_card->getName(), regex("(Forest Gnome)(.*)")))
				{
					if (elixirs.empty())
					{
						elixirs.insert(make_pair(player.first, 3));
					}
					else
					{
						elixirs[player.first] += 3;
					}
				}
				else if (regex_match(c_card->getName(), regex("(Castle)(.*)")))
				{
					if (elixirs.empty())
					{
						elixirs.insert(make_pair(player.first, 1));
					}
					else
					{
						elixirs[player.first] += 1;
					}
				}
			}
		}
	}

	//elixirs
	for (auto &p1 : elixirs)
	{
		for (auto &p2 : elixirs)
		{
			if (elixirs.size() >= 3)
			{
				for (auto &p3 : elixirs)
				{
					if (elixirs.size() == 4)
					{
						for (auto &p4 : elixirs)
						{
							if (p4.first != p3.first && p3.first != p2.first && p2.first != p1.first && p4.first != p1.first && p4.first != p2.first && p3.first != p1.first)
							{
								if (p4.second > p3.second >= p2.second >= p1.second ||
									p4.second > p3.second >= p1.second >= p2.second ||
									p4.second > p2.second >= p3.second >= p1.second ||
									p4.second > p2.second >= p1.second >= p3.second ||
									p4.second > p1.second >= p3.second >= p2.second ||
									p4.second > p1.second >= p2.second >= p3.second)
								{
									vp_counter = compute_score(p4.first, world_map) + 2;
									change_score(p4.first, vp_counter);
								}
								else if (p3.second > p4.second >= p2.second >= p1.second ||
									p3.second > p4.second >= p1.second >= p2.second ||
									p3.second > p2.second >= p4.second >= p1.second ||
									p3.second > p2.second >= p1.second >= p4.second ||
									p3.second > p1.second >= p4.second >= p2.second ||
									p3.second > p1.second >= p2.second >= p4.second)
								{
									vp_counter = compute_score(p3.first, world_map) + 2;
									change_score(p3.first, vp_counter);
								}
								else if (p2.second > p4.second >= p3.second >= p1.second ||
									p2.second > p4.second >= p1.second >= p3.second ||
									p2.second > p3.second >= p4.second >= p1.second ||
									p2.second > p3.second >= p1.second >= p4.second ||
									p2.second > p1.second >= p4.second >= p3.second ||
									p2.second > p1.second >= p3.second >= p4.second)
								{
									vp_counter = compute_score(p2.first, world_map) + 2;
									change_score(p2.first, vp_counter);
								}
								else if (p1.second > p4.second >= p3.second >= p2.second ||
									p1.second > p4.second >= p2.second >= p3.second ||
									p1.second > p3.second >= p4.second >= p2.second ||
									p1.second > p3.second >= p2.second >= p4.second ||
									p1.second > p2.second >= p4.second >= p3.second ||
									p1.second > p2.second >= p3.second >= p4.second)
								{
									vp_counter = compute_score(p1.first, world_map) + 2;
									change_score(p1.first, vp_counter);
								}
								else
								{
									vp_counter = compute_score(p1.first, world_map) + 1;
									change_score(p1.first, vp_counter);
									vp_counter = compute_score(p2.first, world_map) + 1;
									change_score(p2.first, vp_counter);
									vp_counter = compute_score(p3.first, world_map) + 1;
									change_score(p3.first, vp_counter);
									vp_counter = compute_score(p4.first, world_map) + 1;
									change_score(p4.first, vp_counter);
								}
							}
						}
					}
					else
					{
						if (p3.first != p2.first && p3.first != p1.first && p2.first != p1.first)
						{
							if (p3.second > p2.second >= p1.second || p3.second > p1.second >= p2.second)
							{
								vp_counter = compute_score(p3.first, world_map) + 2;
								change_score(p3.first, vp_counter);
							}
							else if (p3.second <= p2.second < p1.second || p2.second <= p3.second < p1.second)
							{
								vp_counter = compute_score(p1.first, world_map) + 2;
								change_score(p1.first, vp_counter);
							}
							else if (p3.second <= p1.second < p2.second || p1.second <= p3.second < p2.second)
							{
								vp_counter = compute_score(p2.first, world_map) + 2;
								change_score(p2.first, vp_counter);
							}
							else
							{
								vp_counter = compute_score(p1.first, world_map) + 1;
								change_score(p1.first, vp_counter);
								vp_counter = compute_score(p2.first, world_map) + 1;
								change_score(p2.first, vp_counter);
								vp_counter = compute_score(p3.first, world_map) + 1;
								change_score(p3.first, vp_counter);
							}
						}
					}
				}
			}
			else
			{
				if (p2.first != p1.first)
				{
					if (p2.second > p1.second)
					{
						vp_counter = compute_score(p2.first, world_map) + 2;
						change_score(p2.first, vp_counter);
					}
					else if (p2.second < p1.second)
					{
						vp_counter = compute_score(p1.first, world_map) + 2;
						change_score(p1.first, vp_counter);
					}
					else
					{
						vp_counter = compute_score(p1.first, world_map) + 1;
						change_score(p1.first, vp_counter);
						vp_counter = compute_score(p2.first, world_map) + 1;
						change_score(p2.first, vp_counter);
					}
				}
			}
		}
	}
	return scores_;
}

void VPCounter::change_score(Player* player, int new_score)
{
	auto iterator_p = scores_.find(player);
	if (iterator_p != scores_.end())
	{
		iterator_p->second = new_score;
	}
	else
	{
		cout << "The player could not be found!" << endl;
		exit(-1);
	}
}