
#include <vector>
#include <regex>
#include "VictoryPoints.h"
#include "../Map/Map.h"
#include "../Player/Player.h"

void VPCounter::change_score(Player* player, int new_score)
{
	auto iterator_p = scores.find(player);
	if (iterator_p != scores.end())
	{
		iterator_p->second = new_score;
	}
	else
	{
		cout << "The player could not be found!" << endl;
		exit(-1);
	}
}

int VPCounter::get_score(Player* player)
{
	auto iterator_p = scores.find(player);
	if (iterator_p != scores.end())
	{
		return iterator_p->second;
	}
	else
	{
		cout << "The player could not be found!" << endl;
		exit(-1);
		return -1; // just for looks
	}
}
void VPCounter::add_player(Player* player)
{
	pair<Player*, int> temp(player, 0);
	scores.insert(temp);
}
;

void VPCounter::print_player_score(Player* player)
{
	auto iterator_p = scores.find(player);
	if (iterator_p != scores.end())
		cout << iterator_p->first->getFirstName() << " " << iterator_p->first->getLastName() << " has a score of " << iterator_p->second << endl;
	else
	{
		cout << "The player could not be found!" << endl;
		exit(-1);
	}
}

void VPCounter::print_all_scores()
{
	for (auto player : scores)
	{
		auto iterator_p = scores.find(player.first);
		if (iterator_p != scores.end())
		{
			cout << iterator_p->first->getFirstName() << " " << iterator_p->first->getLastName() << " has a score of " << iterator_p->second << endl;
		}
		else 
		{
			cout << "The player could not be found!" << endl;
			exit(-1);
		}
	}
}

void VPCounter::reset_new_game()
{
	scores.clear();
	player_count = 0;
}

/**
* List of VP increasing conditions tracked via counter:
* +1 VP for each region. Control of a region counts if a players has the most armies (cities included) on a region, same amount of armies means no one controls the region
* (N/A Time limited) +1 VP for each Island. A Player controls an island if they control the most regions on that island.
* Ignoring some cards with +1vp for each addition card of same type condition due to time constrains (Arcane, Ancient, Dire, Night)
* Cursed Tower +1vp per flying ignored due to unsupported feature, to little time to implement.
* 
*/
int VPCounter::check_vp_conditions(Player* player, game_map* w_map)
{
	int control_points = 0;
	int points_from_cards = 0;
	int noble_count = 0; // 3 max
	int cursed_count = 0; // 5 max
	int mountain_count = 0; // 2 max
	int vp_counter = 0;
	
	if (w_map->map_name != "Copy of World Map" || w_map->map_name != "World Map")
	{
		std::cout << "Non World map passed to check_vp_conditions function!" << endl;
		exit(-1);
	}
	else
	{
		game_map::v_map search_regions = w_map->m_map;
		for (auto r_region: search_regions)
		{
			vector<Player*> v_player = r_region.second->get_controlling_player();
			if (!v_player.empty() && v_player.size() == 1)
			{
				if (v_player[0]->getFirstName() == player->getFirstName() && v_player[0]->getLastName() == player->getLastName())
				{
					control_points += 2;
				}
			}
			else
			{
				for (auto* p_player : v_player)
				{
					if(v_player[0]->getFirstName() == player->getFirstName() && v_player[0]->getLastName() == player->getLastName())
					{
						control_points++;
					}
				}
			}
		}
	}
	if (!player->get_my_list_of_used_cards().empty())
	{
		vector<Card*> card_temp = player->get_my_list_of_used_cards();		
		for (auto* c_card: card_temp)
		{
			if (regex_match(c_card->getName(), regex("(Noble)(.*)")))
			{
				noble_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Cursed)(.*)")))
			{
				cursed_count++;
			}
			else if (regex_match(c_card->getName(), regex("(Lake)(.*)")))
			{
				points_from_cards++;
			}
			else if (regex_match(c_card->getName(), regex("(Graveyard)(.*)")))
			{
				points_from_cards++;
			}
			else if (regex_match(c_card->getName(), regex("(Stronghold)(.*)")))
			{
				points_from_cards++;
			}
			else if (regex_match(c_card->getName(), regex("(Mountain)(.*)")))
			{
				mountain_count++;
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
		points_from_cards += cursed_count;
		
	}
	vp_counter = control_points + points_from_cards;
	return vp_counter;
}

VPCounter* VPCounter::instance()
{
	if (!s_instance)
		s_instance = new VPCounter();
	return s_instance;
}