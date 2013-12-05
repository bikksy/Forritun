#include <iostream>
#include "Entity.h"
using namespace std;

const int DRAGON = 1;
const int DRAGON_HEALTH = 200;


class Dragon : public Entity {
public:
	Dragon(int x, int y);

    virtual int getType();
    virtual void move(int& newX, int& newY);
    virtual void die();
};


Dragon::Dragon(int x, int y) : Entity(x, y, DRAGON_HEALTH) {};
//Dragon::~Dragon() {/*Dragon doesn't have anything dynamically allocated so no cleanup needed*/};

int Dragon::getType()
{
    return DRAGON;
}


void Dragon::move(int& newX, int& newY) {/*Do nothing. */};


void Dragon::die() {
	cout << endl << endl
	     << "OH NO. IT'S A DRAGON." << endl
		 << "Prepare to fight!!!!" << endl
		 << "...." << endl
		 << "Ok. It's dead now." << endl;
}