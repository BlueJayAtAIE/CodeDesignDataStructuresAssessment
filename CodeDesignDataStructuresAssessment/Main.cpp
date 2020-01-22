#include <iostream>
#include "tDoubleLinkedList.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	tDoubleLinkedList<int> bleh;

	// This list empty...
	if (bleh.empty())
	{
		cout << "YEET" << endl << endl;
	}

	bleh.push_front(6);

	// Checking again after adding one element to make sure it doesnt trigger.
	if (bleh.empty())
	{
		cout << "YEET" << endl << endl;
	}

	bleh.push_front(8);
	bleh.push_front(7);
	bleh.push_front(9);
	bleh.push_front(2);
	bleh.push_back(4);

	//bleh.remove(8);

	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << (*it) << endl;
	}


	cout << "--------------------------------" << endl << "Size: " << bleh.size() << endl << endl;

	//bleh.resize(7);

	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << (*it) << endl;
	}

	bleh.pop_front();

	cout << "--------------------------------" << endl << "Size: " << bleh.size() << endl << endl;

	//cout << bleh.deletThis() << endl;

	//bleh.clear();

	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << (*it) << endl;
	}

	if (bleh.empty())
	{
		cout << "YEET" << endl << endl;
	}

	bleh.pop_back();

	cout << "--------------------------------" << endl << "Size: " << bleh.size() << endl << endl;

	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << (*it) << endl;
	}
	
	cout << "Please break-point this line!!" << endl;

	return 0;
}