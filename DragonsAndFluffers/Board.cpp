#include "Entity.h"
#include "Board.h"
#include "Player.h"
#include "Dragon.h"
#include "Fluffer.h"

//We need this for random.
#include <stdlib.h>
#include "time.h"
#include "unistd.h"
using namespace std;

//The board is an n*n matrix - so we use a constant to define the size of the board.
//Then we could easily make the world larger or smaller by simply changing this constant.
const int NUMBER_OF_DRAGONS = 12;
const int NUMBER_OF_FLUFFERS = 20;
const int PLAYER = 0;
const int DRAGON = 1;
const int FLUFFER = 2;


//Default constructor. Handles initalizing the board.
Board::Board() {

	//Seeding the random number generator.
	srand(time(NULL));

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

	//We have to keep track of what entities have moved - so we begin with
	//setting them all to unmoved.
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			Entity* curr = board[i][j];
			if(curr != NULL) {
				curr->setUnmoved();
			}
		}
	}


	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			//If there is an entity in cell (i, j) then we call move for that entity.
			Entity* curr = board[i][j];
			//If the current entity is a dragon it doesn't move, so we don't need to do anything.
			if(curr != NULL && curr->getType() != DRAGON && curr->hasMoved() == false) {
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
							//Delete the entity that is in the position since we're killing it.
							board[newX][newY]->die();
							sleep(3);
							delete board[newX][newY];
							updateEntityLocation(curr, newX, newY);
						}
					}
					//the cell is empty so the entity just moves there.
					else {
						updateEntityLocation(curr, newX, newY);
					}

				}
				//The bounds check failed, so we tried going off the board.
				//Then we don't update the entity.
				else {
					//If the entity was a player we let him know that he bumped into a wall.
					if(curr->getType() == PLAYER) {					
						cout << "You just bumped into a wall you silly, silly goose." << endl;
					}
				}
			}
		}
	}
	//We should return false when the game is over, for example if the player dies or there are no more entities in the
	//grid.
	return true;
}

void Board::updateEntityLocation(Entity* curr, int newX, int newY) {
	//NULL the old position since there isn't an entity there anymore.
	board[curr->getX()][curr->getY()] = NULL;
	//Move the current entity to the new position.
	board[newX][newY] = curr;
	//Update the entity so that it knows where it is.
	curr->setPosition(newX, newY);
	//Set the entity to moved so we don't move it again in this round.
	curr->setMoved();

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