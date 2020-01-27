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
	bleh.push_front(8);
	bleh.push_front(7);
	bleh.push_front(9);
	bleh.push_front(2);
	bleh.push_back(4);


	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << "Bleh:" << (*it) << endl;
	}

	tDoubleLinkedList<int> blah(bleh);

	cout << "--------------------------------" << endl << "Blah is created as a copy of Bleh." << endl << "All 8s 4s and 2s are removed from Bleh." << endl << endl;

	//bleh.resize(7);

	bleh.remove(8);
	bleh.remove(4);
	bleh.remove(2);

	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << "Bleh:" << (*it) << endl;
	}

	cout << endl;

	for (auto it = blah.begin(); it != blah.end(); ++it)
	{
		cout << "Blah:" << (*it) << endl;
	}

	//bleh.pop_front();

	cout << "--------------------------------" << endl << "Bleh will now be set to Blah." << endl << endl;

	bleh = blah;

	for (auto it = bleh.begin(); it != bleh.end(); ++it)
	{
		cout << "Bleh:" << (*it) << endl;
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