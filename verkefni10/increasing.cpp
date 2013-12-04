#include <iostream>
#include <vector>
using namespace std;

bool increasing(vector<int> v);

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << (increasing(arr) ? "increasing" : "not increasing") << endl;
    }

    return 0;
}


bool increasing(vector<int> v) {

    for(unsigned int i = 1; i < v.size(); i++) {
        if(v[i-1] > v[i]) {
            return false;
        }
    }
    return true;

}

// TODO: function implementation comes here