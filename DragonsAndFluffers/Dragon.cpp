#include <iostream>
#include "Entity.h"
using namespace std;

const int DRAGON = 1;
const int DRAGON_HEALTH = 200;


class Dragon : public Entity {
public:
	Dragon(int x, int y);

    virtual int getType();
    virtual void move();
};


Dragon::Dragon(int x, int y) : Entity(x, y, DRAGON_HEALTH) {};
//Dragon::~Dragon() {/*Dragon doesn't have anything dynamically allocated so no cleanup needed*/};

int Dragon::getType()
{
    return DRAGON;
}


void Dragon::move() {/*Do nothing. */};

