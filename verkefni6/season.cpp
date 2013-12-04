#include <iostream>
#include <string>
using namespace std;

// TODO: function declaration comes here


string get_season(int month);

int main()
{
    int month;
    while (cin >> month)
    {
        cout << "month no. " << month << " is in the " << get_season(month) << endl;
    }

    return 0;
}

// TODO: function implementation comes here

string get_season(int month) {


	switch(month) {
		case 1:
		case 2:
			return "winter";
			break;
		case 3:
		case 4:
		case 5:
			return "spring";
			break;
		case 6:
		case 7:
		case 8:
			return "summer";
			break;
		case 9:
		case 10:
		case 11:
			return "autumn";
			break;
		case 12:
			return "winter";
			break;

		default:
			return "error";
	}

}