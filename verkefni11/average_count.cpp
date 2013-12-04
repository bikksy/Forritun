#include <iostream>
using namespace std;


int main() {


	int n;
	cin >> n;

	double* list = new double[n];

	double curr;
	int count = 0, sum = 0;

	while(cin >> curr) {
		list[count] = curr;
		sum += curr;
		count++;	
	}

	double avg = (double)sum / n;
	count = 0;

	for(int i = 0; i < n; i++) {
		if(list[i] < avg) {
			count++;
		}
	}

	cout << count;
	delete [] list;
	return 0;

}