#include <iostream>
using namespace std;


int main() {


	double n, r, guess, previousguess;

	cin >> n;
	//Initial guess.
	previousguess = n;
	guess = n / 2;


	while(guess/previousguess > 1.01) {
		previousguess = guess;
		r = n / guess;
		guess = (guess + r) / 2;
		cout << guess / previousguess << endl;
	}

	cout << endl << guess << endl;
	return 0;
}