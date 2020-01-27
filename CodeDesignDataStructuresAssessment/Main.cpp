#include <iostream>
#include "tDoubleLinkedList.h"

using std::cout;
using std::cin;
using std::endl;

template<typename T>
void printListValues(tDoubleLinkedList<T> list);

int main()
{
	char dummy;

	// Testing creation and empty.
	tDoubleLinkedList<int> listA;

	cout << "listA has just been created. Is it empty?: " << listA.empty() << endl << endl;

	listA.push_front(6);

	// Checking again after adding one element to make sure it doesnt trigger.
	cout << "The following value(s) have been added to the front of listA: 6. Is it empty?: " << listA.empty() << endl << endl;

	// Testing push_front/push_back.
	listA.push_front(8);
	listA.push_front(8);
	listA.push_front(7);
	listA.push_front(9);
	listA.push_front(2);
	listA.push_back(4);

	cout << "The following value(s) have been added to the front of listA: 8, 8, 7, 9, 2." << endl << "The following value(s) have been added to the back of listA: 4." << endl << endl;

	cout << "Current values of listA: ";
	printListValues(listA);
	cout << endl << endl;

	// Testing copy constructor.
	tDoubleLinkedList<int> listB(listA);

	cout << "------------------------------------------" << endl << "listB is created as a copy of listA." << endl << endl;

	// Testing remove.
	listA.remove(8);
	listA.remove(4);
	listA.remove(2);

	cout << "All values matching the following have been removed from listA: 8, 4, 2." << endl << endl;

	cout << "Current values of listA: ";
	printListValues(listA);
	cout << endl << endl;

	cout << "Current values of listB: ";
	printListValues(listB);
	cout << endl << endl;

	cout << "listA will now be set to listB." << endl << endl;

	// Testing =operator.
	listA = listB;

	cout << "Current values of listA: ";
	printListValues(listA);
	cout << endl << endl;
	cout << "------------------------------------------" << endl << "listA is being resized to hold 12 nodes." << endl << endl;

	// Testing resize.
	listA.resize(12);

	cout << "Current values of listA: ";
	printListValues(listA);
	cout << endl << endl;

	// Testing pop_front/pop_back.
	listA.pop_front();
	listA.pop_front();
	listA.pop_back();

	cout << "listA has run pop front 2 time(s). listA has run pop back 1 time(s)." << endl << endl;

	// Testing front/back.
	cout << "The current value of listA's head node is: " << listA.front() << "; the current value of listA's tail node is: " << listA.back() << endl << endl;

	cout << "Current values of listA: ";
	printListValues(listA);
	cout << endl << endl;

	cout << "------------------------------------------" << endl << "listA is being cleared." << endl << endl;

	// Testing clear.
	listA.clear();

	cout << "listA has just been cleared. Is it empty?: " << listA.empty() << endl << endl;

	cout << "Press any lettered key and then enter to close this window." << endl;
	cin >> dummy;
	
	return 0;
}

template<typename T>
void printListValues(tDoubleLinkedList<T> list)
{
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		cout << (*it) << ", ";
	}
}
