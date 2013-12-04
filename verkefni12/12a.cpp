#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction();
	~Fraction();

	void input_numerator();
	void input_denominator();

	int get_numerator();
	int get_denominator();

	bool operator<(Fraction& that);
	friend std::ostream& operator<<(std::ostream& os, Fraction& f);

	/* data */
private:
	int numerator;
	int denominator;
};



int main()
{
    const int n = 10;

    Fraction arr[n];

    // Input ten fractions into the array
    for (int i = 0; i < n; i++)
    {
        arr[i].input_numerator();
        arr[i].input_denominator();
    }

    // Bubble sort the fractions; do not try this at home
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                Fraction tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }

    // Output the fractions
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

Fraction::~Fraction() {};

void Fraction::input_numerator() {
	cin >> numerator;
}

void Fraction::input_denominator() {
	cin >> denominator;
}

int Fraction::get_numerator() {
	return numerator;
}

int Fraction::get_denominator() {
	return denominator;
}

bool Fraction::operator < (Fraction& that) {
	return ((double)numerator / denominator) < ((double)that.get_numerator() / that.get_denominator());
}

ostream& operator << (ostream& os, Fraction& f) {
	os << f.get_numerator() << "/" << f.get_denominator() << endl;
	return os;
}