#include <iostream>
using namespace std;

// TODO: implement the is_leap_year function here

bool is_leap_year(int year) {

    //Check if the year is divisible by 4.
    if(year % 4 == 0) {

        //If the year is divisble by 100, and not divisible by 400 it is not a leap year.
        if(year % 100 == 0 && year % 400 != 0) {
            return false;
        }

        //If we reach this the previous if statement wasn't valid, so the year is a leap year.
        return true;
    }

    //If the year is not divisible by 4, we can return false.
    return false;


}


// DO NOT EDIT BELOW THIS LINE
// ---------- snip -----------

int main()
{
    int year;
    while (cin >> year)
    {
        if (is_leap_year(year))
        {
            cout << year << " is a leap year" << endl;
        }
        else
        {
            cout << year << " is not a leap year" << endl;
        }
    }

    return 0;
}