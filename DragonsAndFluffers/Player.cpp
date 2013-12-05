#include <iostream>
#include <ctype.h>
#include "Entity.h"
using namespace std;

const int PLAYER = 0;
const int PLAYER_HEALTH = 100;
const int PLAYER_STARTING_ARMOR = 50;

class Player : public Entity {
public:
	Player(int x, int y);
//	~Player();

    virtual int getType();
    virtual void move(int& newX, int& newY);
    int getArmor();

    friend ostream& operator <<(ostream& out, Player& p);
private:
	int armor;
};


Player::Player(int x, int y) : Entity(x, y, PLAYER_HEALTH) {
	armor = PLAYER_STARTING_ARMOR;
};

int Player::getType()
{
    return PLAYER;
}

int Player::getArmor() {
	return armor;
}

void Player::move(int& newX, int& newY) {

	cout << "Where do you want to go?" << endl
		 << "U for up, L for left, D for down and R for right: ";


	char direction;
	cin >> direction;
	direction = toupper(direction);

	switch(direction) {
		case 'U':
			newX = getX() - 1;
			newY = getY();
			break;
		case 'L':
			newX = getX();
			newY = getY() - 1;
			break;		
		case 'D':
			newX = getX() + 1;
			newY = getY();
			break;
		case 'R':
			newX = getX();
			newY = getY() + 1;
			break;
		default:
			cout << "Invalid selection. We'll just hang out here then." << endl;
			return;
	}


}

ostream& operator <<(ostream& out, Player& p) {
	out << "Player location: (" << p.getX() << ", " << p.getY() << ")" << endl
	   << "Player health: " << p.getHealth() << endl
	   << "Player armor: " << p.getArmor() << endl;

	return out;
}
