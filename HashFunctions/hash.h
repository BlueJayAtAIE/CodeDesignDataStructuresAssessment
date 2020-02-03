#include <limits>
#include <string>

#pragma once

using std::string;

template<typename K, typename V>
class tHashmap
{
private:
	// UNUSED.
	//struct Pair
	//{
	//	V heldData;
	//	K key;
	//};

	V * data;		  // Buffer holding all potential pairs in the hashmap.
	//Pair * data;		  // UNUSED. Switched back to using V instead.
	size_t dataCapacity;  // Size of the above buffers.

public:
	// Constructs a hashmap with a fixed size.
	tHashmap();


	// Constructs a hashmap with a defined size.
	tHashmap(size_t size);

	// Copy constructor.
	tHashmap(const tHashmap & other);

	// Destructor. Cleans up the underlaying data.
	~tHashmap();                          


	// Copy assignment.
	tHashmap & operator=(const tHashmap & rhs)
	{
		dataCapacity = rhs.dataCapacity;

		// Do the copy thing.
		for (size_t i = 0; i < dataCapacity; i++)
		{
			data[i] = rhs.data[i];
		}

		return *this;
	}


	// Returns object at the given key.
	V & operator[](const K & key);

	// Returns object at the given key (const).
	const V & operator[](const K & key) const;
};

// HASHING FUNCTIONS -------------------------------------------------------------------------

template<typename T>
size_t hash(const T& val)
{
	// Used purely as a placeholder since we need specializations of this function. 
	//T::hash_template;
}

// Template specialization for int (using Knuth's hash function).
template<>
size_t hash<int>(const int & val)
{
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

// Template specialization for char (using Knuth's hash function).
template<>
size_t hash<char>(const char & val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

// Template specialization for std::string (using something I came up with).
template<>
size_t hash<string>(const string & val)
{
	size_t temp = 0;

	for (size_t i = 0; i < val.length(); i++)
	{
		if (i % 2 == 0)
		{
			temp += (int)val[i];
		}
		else
		{
			temp *= (int)val[i];
		}
	}

	return temp;
}

// An array version of the hash template.
template<typename T>
size_t hash(const T val[], size_t size)
{
	// Used purely as a placeholder since we need specializations of this function. 
	//T::hash_template;
}

// Template specialization for c-string (using something I came up with).
template<>
size_t hash<char>(const char val[], size_t size)
{
	size_t temp = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			temp += (int)val[i];
		}
		else
		{
			temp *= (int)val[i];
		}
	}

	return temp;
}

// FUNCTIONS FOR HASHTABLE -------------------------------------------------------------------

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap()
{
	dataCapacity = 100;
	data = new V[dataCapacity];
}

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap(size_t size)
{
	dataCapacity = size;
	data = new V[dataCapacity];
}

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap(const tHashmap & other)
{
	data = new V[other.dataCapacity];

	*this = other;
}

template<typename K, typename V>
inline tHashmap<K, V>::~tHashmap()
{
	delete[] data;
}

template<typename K, typename V>
inline V & tHashmap<K, V>::operator[](const K & key)
{
	auto hashedKey = hash(key) % dataCapacity;
	return data[hashedKey];
}

template<typename K, typename V>
inline const V & tHashmap<K, V>::operator[](const K & key) const
{
	auto hashedKey = hash(key) % dataCapacity;
	return data[hashedKey];
}
