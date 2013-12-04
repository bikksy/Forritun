#include <iostream>
using namespace std;

int strlen2(char*);

int main()
{
    char s[1000];
    while (cin.getline(s, 1000))
    {
        cout << "strlen2(\"" << s << "\") = " << strlen2(s) << endl;
    }

    return 0;
}


int strlen2(char a[]) {

	int i;
	for(i = 0; a[i] != '\0'; i++);
	return i;

}