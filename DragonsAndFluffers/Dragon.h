#ifndef DRAGON_H
#define DRAGON_H
#include "Entity.h"

class Dragon : public Entity {
public:
	Dragon(int x, int y);

    virtual int getType();
    virtual void move(int& newX, int& newY);
    virtual void die();
};

#endif