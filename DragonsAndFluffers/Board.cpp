#include "Entity.h"
#include "Player.cpp"
#include "Dragon.cpp"
#include "Fluffer.cpp"
//We need this for random.
#include <stdlib.h>
using namespace std;

//The board is an n*n matrix - so we use a constant to define the size of the board.
//Then we could easily make the world larger or smaller by simply changing this constant.
const int BOARD_SIZE = 10;
const int NUMBER_OF_DRAGONS = 12;
const int NUMBER_OF_FLUFFERS = 20;


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
	void updateEntityLocation(Entity& e, int newX, int newY);
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

//Default constructor. Handles initalizing the board.
Board::Board() {

	//Seeding the random number generator.
	srand(200389);

	numberOfMobs = 0;
	//We iterate through our board, and initialize each cell with NULL.
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = NULL;
		}
	}

	//First we add the player to the board.
	int playerX = rand() % 10;
	int playerY = rand() % 10;
	board[playerX][playerY] = new Player(playerX, playerY);
	player = (Player*)board[playerX][playerY];

	//Next we'll add NUMBER_OF_DRAGONS dragons to the board.
	int dragonsLeft = NUMBER_OF_DRAGONS;
	while(dragonsLeft > 0) {
		int dragonX = rand() % 10;
		int dragonY = rand() % 10;
		if(board[dragonX][dragonY] == NULL) {
			board[dragonX][dragonY] = new Dragon(dragonX, dragonY);
			dragonsLeft--;
			numberOfMobs++;
		}
	}

	//And finally we add NUMBER_OF_FLUFFERS fluffers to the board.
	int fluffersLeft = NUMBER_OF_FLUFFERS;
	while(fluffersLeft > 0) {
		int flufferX = rand() % 10;
		int flufferY = rand() % 10;
		if(board[flufferX][flufferY] == NULL) {
			board[flufferX][flufferY] = new Fluffer(flufferX, flufferY);
			fluffersLeft--;
			numberOfMobs++;
		}
	}

}

Board::~Board() {

	//Explicitly delete each of entity on the board.
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			//If there is an entity in the cell we want to delete it.
			if(board[i][j] != NULL) {
				delete board[i][j];
			}
		}
	}
}

bool Board::play() {

	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			//If there is an entity in cell (i, j) then we call move for that entity.
			Entity* curr = board[i][j];
			//If the current entity is a dragon it doesn't move, so we don't need to do anything.
			if(curr != NULL && curr->getType() != DRAGON) {
				int newX, newY;
				//newX and newY are passed as referenced variables to the function
				//so their values get changed inside of it.
				curr->move(newX, newY);

				//Make sure that the entity isn't moving off the board.
				if(boundaryCheck(newX, newY)) {
					//If there is another entity on the board we have to handle that.
					if(board[newX][newY] != NULL) {
						//If this isn't the player the entity doesn't move since Dragons don't move and Fluffers are afraid of other 
						//entities.
						if(curr->getType() != PLAYER) {
							continue;
						}
						//If the player walked into a cell that has another entity in it it is going to fight it.
						else {
							//player->fight(board[newX][newY]);
							board[curr->getX()][curr->getY()] = NULL;	
							delete board[newX][newY];
							curr->setPosition(newX, newY);
							board[newX][newY] = curr;

						}
					}
					//the cell is empty so the entity just moves there.
					else {

						board[curr->getX()][curr->getY()] = NULL;
						board[newX][newY] = curr;
						curr->setPosition(newX, newY);
					}


				}
				else {
					if(curr->getType() == PLAYER) {					
						cout << "You just bumped into a wall you silly, silly goose." << endl;
					}
				}
			}
		}
	}
	return true;
}

void Board::updateEntityLocation(Entity& e, int newX, int newY) {

}

//Checks if the new position is within range of the board.
bool Board::boundaryCheck(int x, int y) {
	if(x < BOARD_SIZE && x >= 0) {
		if(y < BOARD_SIZE && y >= 0) {
			return true;
		}
	}
	return false;
}

ostream& operator <<(ostream& out, Board& b) {

	out << endl;
	out << *(b.player);
	out << endl;

	out << "  ";
	for(int i = 0; i < BOARD_SIZE; i++) {
		out << "  " << i << " ";
	}
	out << endl;
	for(int i  = 0; i < BOARD_SIZE; i++) {
		out << "   ---------------------------------------" << endl << i << " ";
		for(int j = 0; j <  BOARD_SIZE; j++) {

			Entity* curr = b.board[i][j];

			if(curr != NULL) {

				if(curr->getType() == PLAYER) {
					out << "| P ";
				}
				else if(curr->getType() == DRAGON) {
					out << "| D ";
				}
				else if(curr->getType() == FLUFFER) {
					out << "| F ";
				}
				//Should not happen.
				else {
					out << "| ?";
				}
			}
			else {
				out << "|   ";
			}
		}
		out << "|" << endl;
	}
	out << "   ---------------------------------------" << endl;
	return out;
}