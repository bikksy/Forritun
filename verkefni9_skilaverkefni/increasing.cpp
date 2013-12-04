#include <iostream>
using namespace std;

bool increasing(int arr[], int n);

int main()
{
    int arr[100], n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << (increasing(arr, n) ? "increasing" : "not increasing") << endl;
    }

    return 0;
}

// TODO: function implementation comes here
bool increasing(int arr[], int n) {


    //The defenition of increasing is n - 1 <= n <= n + 1, so we check for each n if it is larger then n-1, if it's not we return false,
    //but if it is (that is, we finish the loop) we return true.
    for(int i = 1; i < n; i++) {
        if(arr[i-1] > arr[i]) {
            return false;
        }
    }

    return true;
}