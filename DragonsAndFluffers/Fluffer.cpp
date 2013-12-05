#include "Entity.cpp"

const int FLUFFER_HEALTH = 5;

class Fluffer : public Entity
{
public:
	Fluffer(int x, int y);
	~Fluffer();

	virtual EntityType getType();
	virtual void move();
	/* data */
};

Fluffer::Fluffer(int x, int y) : Entity(x, y, FLUFFER_HEALTH) {};
Fluffer::~Fluffer() {/*Fluffer doesn't have anything dynamically allocated so no cleanup needed*/};

EntityType Fluffer::getType() {
	//Remember the enum in Entity.cpp - FLUFFER is an enum representation of an integer.
	return FLUFFER;
}

void Fluffer::move() {/*Do nothing*/};

