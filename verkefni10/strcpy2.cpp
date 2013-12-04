#include <iostream>
using namespace std;

void strcpy2(char* b, char a[]);

int main()
{
    char a[1000], b[1000];
    while (cin.getline(a, 1000))
    {
        cout << "strcpy2(b, \"" << a << "\");" << endl;
        strcpy2(b, a);
        cout << "b = \"" << b << "\";" << endl;
    }

    return 0;
}

// TODO: function implementation comes here
void strcpy2(char b[], char* a) {

	int  i = 0;

	while(a[i] != '\0') {
		b[i] = a[i];
		i++;
	}

	b[i] = '\0';
}