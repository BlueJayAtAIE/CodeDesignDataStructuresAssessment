#include <iostream>
#include "Sorting.h"

using std::cout;
using std::cin;
using std::endl;

template<typename T>
void printVectArrValues(T container);

int main()
{
	char dummy;

	vector<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(10);
	vec.push_back(2);

	cout << "Vector vec has just been created with the following values: ";
	printVectArrValues(vec);
	cout << endl << endl;

	bubbleSort(vec);

	cout << "vec has been sorted in ascending order using Bubble Sort. New value order: ";
	printVectArrValues(vec);
	cout << endl << endl;

	bubbleSortFlip(vec);

	cout << "vec has been sorted in descending order using Bubble Sort. New value order: ";
	printVectArrValues(vec);
	cout << endl << endl;

	vec.clear();
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(12);
	vec.push_back(3);
	vec.push_back(12);
	vec.push_back(9);

	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;

	cout << "Vector vec has just been cleared, and the following values have been added back: ";
	printVectArrValues(vec);
	cout << endl << endl;

	insertionSort(vec);

	cout << "vec has been sorted in ascending order using Insertion Sort. New value order: ";
	printVectArrValues(vec);
	cout << endl << endl;

	insertionSortFlip(vec);

	cout << "vec has been sorted in descending order using Insertion Sort. New value order: ";
	printVectArrValues(vec);
	cout << endl << endl;

	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;

	vec.clear();
	vec.push_back(9);
	vec.push_back(2);
	vec.push_back(15);
	vec.push_back(12);
	vec.push_back(4);
	vec.push_back(9);

	cout << "Vector vec has just been cleared, and the following values have been added back: ";
	printVectArrValues(vec);
	cout << endl << endl;

	MergeSort(vec, 0, (vec.size() - 1));

	cout << "vec has been sorted in ascending order using Merge Sort. New value order: ";
	printVectArrValues(vec);
	cout << endl << endl;

	MergeSortFlip(vec, 0, (vec.size() - 1));

	cout << "vec has been sorted in descending order using Merge Sort. New value order: ";
	printVectArrValues(vec);
	cout << endl << endl;

	cout << "----------------------------------------------------------------------------------------------------" << endl << endl;

	array<int, 7> arr = { 4, 7, 1, 1, 5, 9, 2 };

	cout << "Array arr has just been created with the following values: ";
	printVectArrValues(arr);
	cout << endl << endl;

	bubbleSort(arr);

	cout << "arr has been sorted in ascending order using Bubble Sort. New value order: ";
	printVectArrValues(arr);
	cout << endl << endl;

	insertionSortFlip(arr);

	cout << "arr has been sorted in descending order using Insertion Sort. New value order: ";
	printVectArrValues(arr);
	cout << endl << endl;

	cout << ">> Press any lettered key and then enter to close this window. <<" << endl;
	cin >> dummy;

	return 0;
}

template<typename T>
void printVectArrValues(T container)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		cout << container[i] << ", ";
	}
}
