#include <iostream>
#include <math.h>
using namespace std;






int main() {


	int n;
	double list[100];
	double avg = 0, sum = 0;

	cin >> n;


	for(int i = 0; i < n; i++) {
		cin >> list[i];
		avg += list[i];
	}

	avg = avg / n;

	for(int i = 0; i < n; i++) {

		sum += pow((list[i] - avg), 2);
	}

	cout << sqrt((sum / n)) << endl;


	return 0;

}