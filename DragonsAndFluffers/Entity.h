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
	void setPosition(int newX, int newY);

	virtual void move(int& newX, int& newY) = 0;
	virtual int getType() = 0;

private:
	int x;
	int y;
	int health;
};

#endif