#include <iostream>
using namespace std;

// TODO: function declaratin comes here

int main()
{
    char *a = new char[2010], *b = new char[1000];
    while (cin.getline(a, 1000) && cin.getline(b, 1000))
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
