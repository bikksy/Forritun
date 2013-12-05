#include <iostream>
using namespace std;


int main() {


	int n, sum = 0;
	

	cin >> n;
	int cube[n][n];

	for(int row = 0; row < n; row++) {
		for(int column = 0; column < n; column++) {
			cin >> cube[row][column];
		}
	}

	//We find the inital sum by selecing a single row to sum up.
	//This sums up the elements in the first row.
	for(int column = 0; column < n; column++) {
		sum += cube[0][column];
	}


	//Next, we check each row, and find out if the sum of that row equals the sum of the first row.
	for(int row = 0; row < n; row++) {
		
		int row_sum = 0;
		for(int column = 0; column < n; column++) {
			row_sum += cube[row][column];
		}

		if(row_sum != sum) {
			cout << "ekki galdraferningur" << endl;
			return 0;
		}
	}	

	//Now we check each column, and find out if the sum of that column equals the sum of the first row (all columns and rows should have the same sum).
	for(int column = 0; column < n; column++) {
		
		int column_sum = 0;
		for(int row = 0; row < n; row++) {
			column_sum += cube[row][column];
		}

		if(column_sum != sum) {
			cout << "ekki galdraferningur" << endl;
			return 0;
		}
	}

	//Now we have to check diagonally as well. Both from (0,0) to (n, n), and from  (0, n) to (n, 0).
	int right_down_diagonal_sum = 0;
	for(int i = 0; i < n; i++) {
		//This makes sure we start at (0, 0), then go to (1, 1) and end in (n, n)
		right_down_diagonal_sum += cube[i][i];
	}
	if(right_down_diagonal_sum != sum) {
		cout << "ekki galdraferningur" << endl;
		return 0;
	}

	int left_down_diagonal_sum = 0;
	for(int i = 0; i < n; i++) {
		//Notice the n -1 - i, we have to use n-1 since the matrix is defined in the range[0, n-1].
		left_down_diagonal_sum += cube[i][n - 1 - i];
	}
	if(left_down_diagonal_sum != sum) {
		cout << "ekki galdraferningur" << endl;
 		return 0;
 	}


 	cout << "galdraferningur" << endl;
 	return 0;

}