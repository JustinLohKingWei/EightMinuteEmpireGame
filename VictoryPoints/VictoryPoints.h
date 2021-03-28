// Modified from Tutorial #

#include <map>
#include "../Player/Player.h"

using namespace std;

class VPCounter // Singleton
{
private:
	int player_count = 0;
	map<Player*, int> scores;
	VPCounter() {}
	static VPCounter* s_instance;
	void change_score(Player*, int);
public:
	int get_score(Player*);
	void add_player(Player*);
	void print_player_score(Player*);
	void print_all_scores();
	void reset_newgame();
	void check_vp_conditions(Player* player);
	void end_of_game_vp_check();
	static VPCounter* instance();
protected:
	virtual ~VPCounter() {};
};

VPCounter* VPCounter::s_instance = 0;