#include <iostream>
using namespace std;

/*
	Helper function.

	Checks if n is a prime or not.
*/
bool isPrime(int n) {


	//1 is a special case, it's not a prime although it "could be" given the definition of prime numbers.
	if(n == 1) {
		return false;
	}
	//We start at 2 since every number is divisible by 1 (11/1 = 11), and we end at n-1 because every n is divisible by n (11/11 = 1).
	for(int i = 2; i < n - 1; i++) {

		//If the number modulo i is 0, it means that the number was divisible by i (4 mod 2 = 0), so it' s not a prime.
		if(n % i == 0) {
			//If the number isn't a prime, we can stop checking here, and just return false from the function.
			return false;
		}

	} 
	//If we manage to get to this point, it means the number is a prime, so we return true.
	return true;

}


int main()
{
	
	//the range is [a, b].
	int a, b;
	cin >> a;
	cin >> b;

	cout << endl << "The primes in the range [" << a << "," << b << "] are:"<< endl;
	
	//We start checking at a, and we have to check b as well so we check while i <= b.
	for(int i = a; i <= b; i++) {
		//We send each i into the isPrime helper function, and that returns true or false.
		if(isPrime(i)) {
			cout << i << endl;
		}

	}

	return 0;
}