#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"
#include <iostream>
using namespace std;

class Player : public Entity {
public:
	Player(int x, int y);
//	~Player();

    virtual int getType();
    virtual void move(int& newX, int& newY);
    virtual void die();
    int getArmor();


    friend ostream& operator <<(ostream& out, Player& p);
private:
	int armor;
};

#endif