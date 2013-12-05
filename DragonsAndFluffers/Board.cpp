#include <iostream>
#include "Entity.cpp"
using namespace std;

const int BOARD_SIZE = 10;


class Board
{
public:
	Board();
	~Board();


	void play();
	/* data */
private:
	Entity* board[BOARD_SIZE][BOARD_SIZE];
};




Board::Board() {

	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = NULL;
		}
	}
}