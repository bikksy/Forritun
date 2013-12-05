#include <iostream>
#include "Entity.cpp"
using namespace std;


class Player : public Entity {
public:
	Player(int x, int y);
	~Player();

    virtual EntityType getType();
	/* data */
};


Player::Player(int x, int y) : Entity(x, y) {};

EntityType Player::getType()
{
    return PLAYER;
}
