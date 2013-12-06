#include <iostream>
#include <stdlib.h>

#include "Fluffer.h"
#include "time.h"
using namespace std;

const int FLUFFER = 2;
const int FLUFFER_HEALTH = 5;


Fluffer::Fluffer(int x, int y) : Entity(x, y, FLUFFER_HEALTH) {};

int Fluffer::getType() {
	return FLUFFER;
}

void Fluffer::move(int& newX, int& newY) {

	srand(time(NULL));
	int direction = rand() % 4;

	switch(direction) {
		case 0:
			newX = getX() + 1;
			newY = getY();
			break;
		case 1:
			newX = getX();
			newY = getY() - 1;
			break;
		case 2:
			newX = getX() - 1;
			newY = getY();
			break;
		case 3:
			newX = getX();
			newY = getY() + 1;
			break;
		default:
			cout << "wat" << endl;	
	} 

};


void Fluffer::die() {
	cout << endl << endl
	     << "Oh look at that cute little fluffer." << endl
		 << "What a cute cute fluffer." << endl 
		 << "To bad it has to DIE!!!!" << endl;
}	