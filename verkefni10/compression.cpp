#include <iostream>
using namespace std;


int main() {


	int list[1000];
	int n, length = 0;
	while(cin >> n) {
		list[length] = n;
		length++;
	}

	if(length  == 1) {
		cout << list[0] << endl;
		return 0;
	}

	int a = list[0];
	int b = list[0];

	for(int i = 0; i < length; i++) {
		
		if(b + 1 == list[i + 1]) {
			b = list[i + 1];
			if(i + 1 != length) {
				continue;
			}
		}

		if(a != b) {
			cout << a << "-" << b << " ";
		}
		else {
			cout << a << " ";
		}

		a = list[i + 1];
		b = list[i + 1];
	}


	return 0;
}