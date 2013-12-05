#include <iostream>
using namespace std;

enum EntityType{Player, Dragon, Fluffer};

class Entity
{
public:
	Entity();
	Entity(int x, int y);
	~Entity();

	void showLocation();
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

Entity::Entity(int x, int y) {
	this->x = x;
	this->y = y;
	this->health = 0;
}

void Entity::showLocation() {
	cout << this->x << " - " << this->y;
}

