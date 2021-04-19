// Modified from Tutorial #
#pragma once

#include <map>
#include "../Player/Player.h"

class Player;
class WorldMap;

class VPCounter
{

public:
	// Constructor and Destructor
	VPCounter() = default;
	~VPCounter() = default;

	// functions
	// int get_score(Player*, WorldMap);
	void add_player(Player*);
	// void print_player_score(Player*);
	// void print_all_scores();
	void reset_for_new_game();

	// score functions
	int compute_score(Player*, WorldMap*);
	map<Player*, int> compute_score_end_of_game(WorldMap*);
private:
	map<Player*, int> scores_;
	map<Player*, int> elixirs;
	void change_score(Player*, int);
};
