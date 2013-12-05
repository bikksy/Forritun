#include <iostream>
#include "Entity.h"
using namespace std;

const int FLUFFER = 2;
const int FLUFFER_HEALTH = 5;

class Fluffer : public Entity
{
public:
	Fluffer(int x, int y);

	virtual int getType();
	virtual void move();

};

Fluffer::Fluffer(int x, int y) : Entity(x, y, FLUFFER_HEALTH) {};

int Fluffer::getType() {
	return FLUFFER;
}

void Fluffer::move() {/*Do nothing*/};
