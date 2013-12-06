#ifndef BOARD_H
#define BOARD_H

#include "Entity.h"
#include "Player.h"
const int BOARD_SIZE = 10;

class Board
{
public:
	//Default constructor
	Board();
	//Destructor
	~Board();
	//Iterates through all cells in the board, and updates all entities.
	bool play();
	//The bord handles moving the entities around.
	void updateEntityLocation(Entity* e, int newX, int newY);
	bool boundaryCheck(int x, int y);

	//Overriding the outstream operator for the board.
	friend std::ostream& operator <<(std::ostream& out, Board& b);

private:
	//We use an double array to represent the board, so it becomes a grid. Can be thought of as a
	//chess board, for example.
	Entity* board[BOARD_SIZE][BOARD_SIZE];
	int numberOfMobs;
	Player* player;

};

#endif