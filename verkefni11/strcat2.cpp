#include <iostream>
using namespace std;

void strcat2(char* a, char* b) {

    char* temp = a;

    for(; *a != '\0'; a++);


    for(; *b != '\0'; b++, a++) {
        *a = *b;
    }

    *a = '\0';
 
}

int main()
{
    char *a = new char[11], *b = new char[11];

    while (cin.getline(a, 10) && cin.getline(b, 10))
    {
        cout << "a = \"" << a << "\";" << endl;
        cout << "strcat2(a, \"" << b << "\");" << endl;
        strcat2(a, b);
        cout << "a = \"" << a << "\";" << endl << endl;


    }
    delete[] a;
    delete[] b;
    return 0;
}
