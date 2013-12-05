#include <iostream>
#include "Entity.h"
#include "Board.cpp"

using namespace std;



int main() {


	Board* b = new Board();

	bool gameOn = true;
	while(gameOn) {
		cout << *b << endl;
		gameOn = b->play();
	}

	return 0;


}