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

	/*
		Notice how we combine cases that have the same value.
		We have to specify what we want for each value that is correct (if we don't it goes to default.),
		but we can combine cases 3, 4 and 5 since if we get case 3 we'll "slide down" to the return statement and then break,
		so cases 3, 4, and 5 all have the same return value when we do it like this.
		We could also have added returns and breaks for each statement, but this saves us some time, and we're lazy in general,
		so we don't want to do anything we don't need to do.
	*/
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