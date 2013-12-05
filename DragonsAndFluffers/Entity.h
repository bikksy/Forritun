#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
using namespace std;

class Entity
{
public:
	Entity();
	Entity(int x, int y, int h);
	~Entity();

	int getHealth();
	void setHealth(int h);
	bool isDead();

	int getX();
	int getY();

	virtual void move() = 0;
	virtual int getType() = 0;

private:
	int x;
	int y;
	int health;

};

#endif