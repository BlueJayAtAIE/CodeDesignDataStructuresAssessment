#pragma once

template<typename T>
class tDoubleLinkedList
{
private:
	struct Node
	{
		T data;           // Data for the element stored.
		Node * next;      // Pointer to the Node after this Node.
		Node * previous;  // Pointer to the Node before this Node.
	};

	Node * head;  // Pointer to the begining Node of the LinkedList.
	Node * tail;  // Pointer to the ending Node of the LinkedList.

public:
	// CONSTRUCTORS AND DESTRUCTORS -------------------------------------------------------------------------

	// Default Constructor. Initializes head and tail to NULL.
	tDoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	// Copy Constructor.
	tDoubleLinkedList(const tDoubleLinkedList& other)
	{
		head = NULL;
		tail = NULL;
		for (auto it = other.begin(); it != other.end(); ++it)
		{
			push_back(*it);
		}
	}

	// Destructor.
	~tDoubleLinkedList()
	{
		// Clear deletes all the dynamically allocated nodes.
		clear();
	}

	// UTILITY ----------------------------------------------------------------------------------------------

	// Adds element to the front (Head).
	void push_front(const T& val)
	{
		// Create a new node
		Node * temp = new Node;
		temp->data = val;
		temp->next = head;
		temp->previous = NULL;

		// This triggers only if there IS a head. If there isn't,
		// tail also becomes head (because when size is one, head == tail effectively);
		if (head != NULL)
		{
			head->previous = temp;
		}
		else
		{
			tail = temp;
		}

		// Set head to be the new node.
		head = temp;
	}

	// Adds element to the back (Tail).
	void push_back(const T& val)
	{
		// Create a new temp node;
		Node * temp = new Node;
		temp->data = val;
		temp->previous = tail;
		temp->next = NULL;

		// This triggers only if there IS a tail. If there isn't,
		// head also becomes tail (because when size is one, head == tail effectively);
		if (tail != NULL)
		{
			tail->next = temp;
		}
		else
		{
			head = temp;
		}

		// Set tail to be the new node.
		tail = temp;
	}

	// Removes element from front (Head)
	void pop_front()
	{
		// Means this will only run if there is a head to begin with.
		if (head != NULL)
		{
			Node * temp = head;
			head = head->next;
			delete temp;
		}
	}

	// Removes element from back (Tail)
	void pop_back()
	{
		// Means this will only run if there is a tail to begin with.
		if (tail != NULL)
		{
			Node * temp = tail;
			tail = tail->previous;
			delete temp;
			tail->next = NULL;
		}
	}


	// Returns element at the head.
	T& front()
	{
		return head->data;
	}
	
	// Returns element at the tail.
	T& back()
	{
		return tail->data;
	}
	
	// Returns element at the head (const).
	const T& front() const
	{
		return head->data;
	}

	// Returns element at the tail (const).
	const T& back() const
	{
		return tail->data;
	}


	// Removes all elements equal to the given value.
	void remove(const T& val)
	{
		// Since we may remove multiple elements matching val, we need to find how many loops we need to remove everything.
		size_t timesToLoop = 0;

		for (auto it = begin(); it != end(); ++it)
		{
			if (*it == val)
			{
				timesToLoop++;
			}
		}

		for (size_t i = 0; i < timesToLoop; i++)
		{
			// Create a node pointer to head. We create this so we can delete this later.
			Node * node = head;

			// While the node ISNT NULL (NULL being beyond the bounds of the array)...
			while (node != NULL)
			{
				if (node->data == val)
				{
					// If the node isnt the head, set the previous node's next to the next of the current node...
					// if it is the head, change head to the current head's next....
					if (node != head)
					{
						node->previous->next = node->next;
					}
					else
					{
						head = head->next;
					}

					// If the node isnt the tail, set the next node's previous to the previous of the current node...
					// if it is the tail, change tail to the current tail's previous....
					if (node != tail)
					{
						node->next->previous = node->previous;
					}
					else
					{
						tail = tail->previous;
					}

					// And delete the node, then break out early.
					delete node;
					break;
				}

				// Increment node to be it's own next node.
				node = node->next;
			}
		}
	}

	// Returns true is there are no elements.
	bool empty() const
	{
		if (head == NULL)
		{
			return true;
		}

		return false;
	}

	// Returns the size of the LinkedList.
	size_t size() const
	{
		// While not part of the listed functions, the documentation (both cppref and cplusplus)  
		// for lists says it does have a size function. I've used it very sparingly elsewhere,
		// for the purpose of attempting this implimentation as intended as possible.

		size_t temp = 0;

		for (auto it = begin(); it != end(); ++it)
		{
			temp++;
		}

		return temp;
	}

	// Destroys every single Node in the LinkedList (but not the list itself!).
	void clear()
	{
		// Create a node and set it to head. This will be deleted later.
		// I've used a node incrementing in the place of an iterator because
		// from what I've found there is no way to delete the node an iterator points to.
		Node * node = head;

		// While node isn't NULL, create node toDelete as a copy of node, increment node, then delete toDelete.
		while (node != NULL)
		{
			Node * toDelete = node;
			node = node->next;
			delete toDelete;
		}

		// Here at the very end, delete node and set head/tail to NULL so any push functions work again.
		delete node;
		head = NULL;
		tail = NULL;

		//iterator it = begin();
		//while (it != end())
		//{
			//iterator itTemp = it;
			//++it;
			//delete itTemp.current;   // Current is private- doesn't work. C2248.
			//delete itTemp->current;  // Doesnt use -> operator- doesn't work. C2819 and C2232.
			//delete itTemp;           // Delete cannot figure out HOW to delete iterators. C2440.
		//}
	}

	// Resizes the LinkedList to contain the given number of elements.
	// New elements are default initialized.
	void resize(size_t newSize)
	{
		size_t actualSize = size();

		// If the new size is bigger than the size, add onto it- else take off the back.
		if (newSize > actualSize)
		{
			for (size_t i = 0; i < (newSize - actualSize); i++)
			{
				push_back(0);
			}
		}
		else
		{
			for (size_t i = 0; i < (actualSize - newSize); i++)
			{
				pop_back();
			}
		}
	}

	// OPERATORS --------------------------------------------------------------------------------------------

	tDoubleLinkedList& operator=(const tDoubleLinkedList& rhs)
	{
		// Resize ourselves to match the list we're setting ourseves equal to.
		resize(rhs.size());

		// Create an iterator for the right hand side.
		// Set left hand side's data to right hand side's, and increment both iterators.
		auto itRHS = rhs.begin();
		for (auto it = begin(); it != end(); ++it)
		{
			*it = *itRHS;
			++itRHS;
		}

		return *this;
	}

	// ITERATORS ------------------------------------------------------------------------------------------------------

	class iterator
	{
	private:
		Node * current;  // Current Node being operated upon.

	public:
		// CONSTRUCTORS AND DESTRUCTORS ---------------------------------------------------------------------

		// Initalizies an empty iterator pointing to NULL.
		iterator()
		{
			current = nullptr;
		}

		// Initalizes an iterator pointing to the given Node.
		iterator(Node * startNode)
		{
			current = startNode;
		}

		// OPERATORS ----------------------------------------------------------------------------------------

		// Returns true if the iterator points to the same Node.
		bool operator==(const iterator& rhs) const
		{
			if (current == rhs.current)
			{
				return true;
			}

			return false;
		}

		// Returns true if the iterator DOES NOT point to the same Node.
		bool operator!=(const iterator& rhs) const
		{
			if (current != rhs.current)
			{
				return true;
			}

			return false;
		}

		// Returns a reference to the element pointed to by the current Node.
		T& operator*() const
		{
			return current->data;
		}

		// Pre-increment (returns a refernce to this iterator after it is incremented).
		iterator& operator++()
		{
			current = current->next;
			return *this;
		}

		// Post-increment (returns an iterator to the current Node while incrementing the existing iterator).
		iterator operator++(int)
		{
			iterator temp = *this;
			current = current->next;
			return temp;
		}

		// Pre-decrement (returns a refernce to this iterator after it is decremented).
		iterator& operator--()
		{
			current = current->previous;
			return *this;
		}

		// Post-decrement (returns an iterator to the current Node while decrementing the existing iterator).
		iterator operator--(int)
		{
			iterator temp = *this;
			current = current->previous;
			return temp;
		}
	};

	// Creates an iterator pointing to the first element.
	iterator begin()
	{
		iterator temp(head);
		return temp;
	}

	// Creates a const iterator pointing to the first element (const).
	const iterator begin() const
	{
		iterator temp(head);
		return temp;
	}

	// Creates an iterator pointing to one past the last element.
	iterator end() 
	{
		// NULL can also be used here since the value after tail will always be NULL;
		iterator temp(tail);
		++temp;
		return temp;
	}

	// Creates a const iterator pointing to one past the last element (const).
	const iterator end() const
	{
		// NULL can also be used here since the value after tail will always be NULL;
		iterator temp(tail);
		++temp;
		return temp;
	}
};


// PROGRESS
// 28/28 Baseline functions done.
// Still needed:
//	 Import sorting stuff from exersizes (All 3 done).
// Stretch goals (if I'm feeling like I want to do extra for fun.):
//   Additional functions: Reverse, Unique, Insert(?)