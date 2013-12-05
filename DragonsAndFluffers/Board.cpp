#include "Entity.h"
//We need this for random.
#include <stdlib.h>
using namespace std;

//The board is an n*n matrix - so we use a constant to define the size of the board.
//Then we could easily make the world larger or smaller by simply changing this constant.
const int BOARD_SIZE = 10;


class Board
{
public:
	//Default constructor
	Board();
	//Destructor
	~Board();
	//Iterates through all cells in the board, and updates all entities.
	void play();

private:
	//We use an double array to represent the board, so it becomes a grid. Can be thought of as a
	//chess board, for example.
	Entity* board[BOARD_SIZE][BOARD_SIZE];
	int numberOfEntities;

};


Board::Board() {


	srand(200389);
	numberOfEntities = 0;
	//We iterate through our board, and initialize each cell with NULL.
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = NULL;
		}
	}
}

Board::~Board() {

	//Explicitly delete each of entity on the board.
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			//If there is an entity in the cell we want to delete it.
			if(board[i][j] != NULL) {
				//delete board[i][j];
			}
		}
	}
}

void Board::play() {

	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			//If there is an entity in cell (i, j) then we call move for that entity.
			if(board[i][j] != NULL) {
				board[i][j]->move();
			}
		}
	}
}
