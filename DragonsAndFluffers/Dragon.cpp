#include <iostream>
#include "Entity.cpp"
using namespace std;


class Dragon : public Entity {
public:
	Dragon(int x, int y);
	~Dragon();

    virtual EntityType getType();
	/* data */
};


Dragon::Dragon(int x, int y) : Entity(x, y) {};

EntityType Dragon::getType()
{
    return DRAGON;
}
