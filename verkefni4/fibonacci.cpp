#include <iostream>
using namespace std;


/*
	Recursive implementation.

	Pros: It's cool.
	Cons: We're calculating the same values over and over, since we have no recognition of what numbers
		  we've already calculated. If n is large we get alot of recursive function calls, thus smashing our stack.

*/m
int fibonacciRecursive(int n) {


	if(n < 1) {
		return 0;
	}

	if(n == 1) {
		return 1;
	}

	if(n == 2){
		return 1;
	}


	return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);


}


/*
	Brute force implementation.

	Pros: Is faster and more stack-friendly then the recursive implementation.
	Cons: Takes alot of space if n is large.
*/
int fibonacciBruteForce(int n) {

	if(n < 1) {
		return 0;
	}

	//We calculate all the fibonacci numbers and store them in a list.
	int listOfFibonacciNumbers[n];
	//We initialize the first two values of the list, since we need to know at least two numbers to calculate the rest.
	listOfFibonacciNumbers[0] = 1;
	listOfFibonacciNumbers[1] = 1;

	for(int i = 2; i < n; i++) {
		//Each number nr. i is made up of the sum of numbers nr. i-1 and -2.
		listOfFibonacciNumbers[i] = listOfFibonacciNumbers[i - 1] +  listOfFibonacciNumbers[i - 2];
	}

	//We return the (n-1)th number since the first element is at position 0, so the last position in the array is n-1.
	return listOfFibonacciNumbers[n - 1];

} 

/*
	Dynamic programming implementation of the solution.

	Pros: Doesn't take alot of space and is fast.
	Cons: Nothing.
*/
int fibonacciDynamicProgramming(int n) {


	if(n < 1) {
		return 0;
	}
	if(n < 3) {
		return 1;
	}

	//Again we initalize the first two values, storing them in a and b.
	int a = 1, b = 1, c;

	for(int i = 2; i < n; i++) {
		c = a + b;
		a = b;
		b = c;

	}

	return c;

}

int main() {

	int number, answer;
	cout << "Which fibonacci number do you want me to find?" << endl;
	cin >> number;

	//You can change the function call here to test the other methods.
	answer = fibonacciRecursive(number);
	cout << answer;
	cout << "The fibonacci number nr. " << number << " is: " << answer << endl;

	return 0;

}