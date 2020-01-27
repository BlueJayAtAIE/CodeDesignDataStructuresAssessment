#include <vector>

using std::vector;

#pragma once

// With the way these sorts are templates, they should support the use of both
// vectors and arrays. Hypothetically, anything with a [] accessor operator and size.

template<typename T>
void bubbleSort(T & container)
{
	for (size_t i = 0; i < (container.size() - 1); i++)
	{
		// For each element i...
		for (size_t j = (container.size() - 1); j >= i + 1; j--)
		{
			// Compare to each element j... 
			if (container[j] < container[j - 1])
			{
				// If j is less than i, swap the values.
				auto temp = container[j];
				container[j] = container[j - 1];
				container[j - 1] = temp;
			}
		}
	}
}

template<typename T>
void bubbleSortFlip(T & container)
{
	for (size_t i = 0; i < (container.size() - 1); i++)
	{
		// For each element i...
		for (size_t j = (container.size() - 1); j >= i + 1; j--)
		{
			// Compare to each element j... 
			if (container[j] > container[j - 1])
			{
				// If j is greater than i, swap the values.
				auto temp = container[j];
				container[j] = container[j - 1];
				container[j - 1] = temp;
			}
		}
	}
}

template<typename T>
void insertionSort(T & container)
{
	// Starting with the SECOND value, for each value in the array...
	for (size_t i = 1; i < container.size(); i++)
	{
		// the key is the value at the current index.
		auto key = container[i];
		size_t j = i - 1;

		// while the key'd value is less than the value to it's left...
		while (j >= 0 && container[j] > key)
		{
			// Swap the values.
			container[j + 1] = container[j];
			j = j - 1;
			container[(j + 1)] = key;

			// Extra check to make sure j never overflows.
			if (j > container.size())
			{
				j = 0;
			}
		}
	}
}

template<typename T>
void insertionSortFlip(T & container)
{
	// Starting with the SECOND value, for each value in the array...
	for (size_t i = 1; i < container.size(); i++)
	{
		// the key is the value at the current index.
		auto key = container[i];
		size_t j = i - 1;

		// while the key'd value is less than the value to it's left...
		while (j >= 0 && container[j] < key)
		{
			// Swap the values.
			container[j + 1] = container[j];
			j = j - 1;
			container[(j + 1)] = key;

			// Extra check to make sure j never overflows.
			if (j > container.size())
			{
				j = 0;
			}
		}
	}
}

// Merge sort is the only sort that we're going vector only- we need to be able to use resize.

template<typename T>
void Merge(vector<T> & container, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;

	// Create two empty containers.
	vector<T> containerL;
	containerL.resize(leftEnd);
	vector<T> containerR;
	containerR.resize(rightEnd);

	// Copy values from hsVector to the respective containers.
	for (size_t i = 0; i < leftEnd; i++)
	{
		containerL[i] = container[p + i];
	}
	for (size_t j = 0; j < rightEnd; j++)
	{
		containerR[j] = container[q + j + 1];
	}

	// Used for navigating the temp arrays.
	size_t i = 0;
	size_t j = 0;

	// Compares the values in containerL and containerR, then
	// copies the value accordingly back to the array we actually use.
	for (size_t k = p; k <= r; k++)
	{
		if ((j >= rightEnd) || (i < leftEnd && containerL[i] <= containerR[j]))
		{
			container[k] = containerL[i];
			i++;
		}
		else
		{
			container[k] = containerR[j];
			j++;
		}
	}
}

template<typename T>
void MergeFlip(vector<T> & container, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;

	// Create two empty containers.
	vector<T> containerL;
	containerL.resize(leftEnd);
	vector<T> containerR;
	containerR.resize(rightEnd);

	// Copy values from hsVector to the respective containers.
	for (size_t i = 0; i < leftEnd; i++)
	{
		containerL[i] = container[p + i];
	}
	for (size_t j = 0; j < rightEnd; j++)
	{
		containerR[j] = container[q + j + 1];
	}

	// Used for navigating the temp arrays.
	size_t i = 0;
	size_t j = 0;

	// Compares the values in containerL and containerR, then
	// copies the value accordingly back to the array we actually use.
	for (size_t k = p; k <= r; k++)
	{
		if ((j >= rightEnd) || (i < leftEnd && containerL[i] >= containerR[j]))
		{
			container[k] = containerL[i];
			i++;
		}
		else
		{
			container[k] = containerR[j];
			j++;
		}
	}
}

template<typename T>
void MergeSort(vector<T> & container, size_t p, size_t r)
{
	if (p < r)
	{
		// q here is the middle of the array/vector (in this case).
		size_t q = (p + r) / 2;

		MergeSort(container, p, q);
		MergeSort(container, q + 1, r);
		Merge(container, p, q, r);
	}
}

template<typename T>
void MergeSortFlip(vector<T> & container, size_t p, size_t r)
{
	if (p < r)
	{
		// q here is the middle of the array/vector (in this case).
		size_t q = (p + r) / 2;

		MergeSortFlip(container, p, q);
		MergeSortFlip(container, q + 1, r);
		MergeFlip(container, p, q, r);
	}
}