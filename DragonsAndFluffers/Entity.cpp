#include "Entity.h"
using namespace std;

Entity::~Entity() {/*Entities don't have anything that's dynamically allocated, so we don't need to do anything.*/};
Entity::Entity(int x, int y, int h) {
	this->x = x;
	this->y = y;
	this->health = h;
};

int Entity::getHealth() {
	return health;
};

void Entity::setHealth(int h) {
	health = h;
};

bool Entity::isDead() {
	return health <= 0;
};

int Entity::getX() {
	return x;
};

int Entity::getY() {
	return y;
};

void Entity::setPosition(int newX, int newY) {
	x = newX;
	y = newY;
}