// Modified from Tutorial #
#pragma once

#include <map>

class game_map;
class Player;
class VPCounter // Singleton
{
private:
	std::map<Player*, int> scores;
	VPCounter()=default;
	static VPCounter* s_instance;
	void change_score(Player*, int);
public:
	int get_score(Player*);
	void add_player(Player*);
	void print_player_score(Player*);
	void print_all_scores();
	void reset_new_game();

	int compute_score(Player*, game_map*);
	static VPCounter* instance()
	{
		if (!s_instance)
			s_instance = new VPCounter();
		return s_instance;
	}

protected:
	virtual ~VPCounter() {};
};

//VPCounter* VPCounter::s_instance = nullptr;
