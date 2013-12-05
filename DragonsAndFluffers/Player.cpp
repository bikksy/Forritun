#include <iostream>
#include "Entity.h"
using namespace std;

const int PLAYER = 0;
const int PLAYER_HEALTH = 100;
const int PLAYER_STARTING_ARMOR = 50;

class Player : public Entity {
public:
	Player(int x, int y);
//	~Player();

    virtual int getType();
	/* data */
private:
	int armor;
};


Player::Player(int x, int y) : Entity(x, y, PLAYER_HEALTH) {
	armor = PLAYER_STARTING_ARMOR;
};

int Player::getType()
{
    return PLAYER;
}
