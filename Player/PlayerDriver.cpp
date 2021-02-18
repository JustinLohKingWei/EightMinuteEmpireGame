#include "Player.h";

int main() {

	Player* a = new Player();
	a->Player::BuildCity();
	a->Player::DestroyArmy();
	a->Player::MoveArmies();
	a->Player::MoveOverLand();
	a->Player::PayCoin();
	a->Player::PlaceNewArmies();
	return 0;
}