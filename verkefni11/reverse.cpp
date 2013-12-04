#include <iostream>
using namespace std;


int main() {
	

	int n;
	cin >> n;

	int* list = new int[n];

	int i = 0;

	while(cin >> n) {
		list[i] = n;
		i++;
	}

	for(; i > 0; i--) {
		cout << list[i - 1] << " ";
	}


	delete [] list;

	return 0;

}