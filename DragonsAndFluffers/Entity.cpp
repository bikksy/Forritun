#include <iostream>
using namespace std;

enum EntityType{PLAYER, DRAGON, FLUFFER};

class Entity
{
public:
	Entity();
	Entity(int x, int y, int h);
	~Entity();

	virtual void move() = 0;
	virtual EntityType getType() = 0;
	/* data */

private:
	int x;
	int y;
	int health;

};

Entity::Entity() {
	x = 0;
	y = 0;
}

Entity::~Entity() {/*Entities don't have anything that's dynamically allocated, so we don't need to do anything.*/};
Entity::Entity(int x, int y, int h) {
	this->x = x;
	this->y = y;
	this->health = h;
}
