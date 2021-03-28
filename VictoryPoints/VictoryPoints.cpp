#include "VictoryPoints.h"


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
void VPCounter::add_player(Player*)
{
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

void VPCounter::reset_newgame()
{
	scores.clear();
	player_count = 0;
}

/**
* List of VP increasing conditions tracked via counter:
* +1 VP for each reagion. Control of a region counts ifa players has the most armie (cities included) on a region, same amount of armies means no one controls the region
* +1 VP for each Island. A Player controls an island if they control the most regions on that island.
* +1 for cursed cards. // No cursed cards.
* Current cards of concern: 
* Arcane Temple: +1 VP per Arcane card, 3 in deck
* Castle: has one elixir, 3 in deck
*/
void VPCounter::check_vp_conditions(Player* player)
{
}

/**
* End of game victory point checks: 
* At the end of game +1 VP per 3 coins.
* Specified amount of VP (+4) for owning all three noble cards. // No noble cards
* +2 for the player with the most elixirs. +1 for all players who are tied.
* Current cards of concern:
* Arcane Temple: +1 VP per Arcane card, 3 in deck
* Castle: has one elixir, 3 in deck
*/
void VPCounter::end_of_game_vp_check()
{
}

VPCounter* VPCounter::instance()
{
	if (!s_instance)
		s_instance = new VPCounter();
	return s_instance;
}

