#include <iostream>
#include "Entity.cpp"
using namespace std;


class Player : public Entity {
public:
	Player(int x, int y);
	~Player();

	/* data */
};


Player::Player(int x, int y) : Entity(x, y) {};
