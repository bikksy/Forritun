#ifndef FLUFFER_H
#define FLUFFER_H

#include "Entity.h"

class Fluffer : public Entity
{
public:
	Fluffer(int x, int y);

	virtual int getType();
	virtual void move(int& newX, int& newY);
	virtual void die();

};

#endif