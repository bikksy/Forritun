#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

class IntList
{
public:
	IntList();
	~IntList();


	void add(int);
	int getSize();
	bool full();

	bool operator >(IntList& that);
	IntList& operator =(const IntList& that);
	IntList operator +(IntList& that);
	friend ostream& operator<<(ostream& os, IntList& list);

private:
	int* list;
	int size;

	/* data */
};

int main()
{
    IntList list1, list2, list3, list4;   // Declare 4 integer lists

    for (int i = 0; i < 10; i++)          // Populate the first list
    {
        list1.add(i);
    }

    for (int i = 0; i < 5; i++)           // Populate the second list
    {
        list2.add(i * 2);
    }

    cout << list1;                        // Output the first list to the screen
    cout << list2;                        // Output the second list to the screen

    if (list1 > list2)
    {
        cout << "List 1 is larger than list 2" << endl;
    }
    else
    {
        cout << "List 1 is not larger than list 2" << endl;
    }

    list3 = list1 + list2;                // Add the first two lists
    cout << list3;                        // And output the result to the screen

    cout << "The size of list 3 is: " << list3.getSize() << endl;

    for (int i = 10; i < 25; i++)
    {
        list1.add(i);                     // Put more entries into list 1
    }

    cout << list1;                        // And output it

    if (list1.full())
    {
        cout << "List 1 is full!" << endl;
    }

    list4 = list3;                        // Assign the third list to the fourth
    cout << list4;

    return 0;
}

IntList::IntList() {

	list = new int[MAX_SIZE];
	size = 0;
}

IntList::~IntList() {
	delete [] list;
}

void IntList::add(int i) {

	if(full()) {
		return;
	}

	list[size] = i;
	size++;
}

int IntList::getSize() {
	return size;
}

bool IntList::full() {
	return size == MAX_SIZE;
}

bool IntList::operator >(IntList& that) {
	return getSize() > that.getSize();	
}

IntList& IntList::operator =(const IntList& that) {
	
	size = that.size;
	for(int i = 0; i < size; i++) {
		list[i] = that.list[i];
	}
	return *this;

}

IntList IntList::operator +(IntList& right) {
	IntList temp;

	int size = getSize() < right.getSize() ? getSize() : right.getSize();
	for(int i = 0; i < size; i++) {
		temp.add(list[i] + right.list[i]);
	}
	return temp;
}

ostream& operator <<(ostream& os, IntList& lis) {

	for(int i = 0; i < lis.getSize(); i++) {
		os << lis.list[i] << " ";
	}
	os << endl;
	return os;
}