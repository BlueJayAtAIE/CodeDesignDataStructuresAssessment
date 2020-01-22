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
	// ITERATORS ---------------------------------------------------------

	class iterator 
	{
	private:
		Node * current;  // Current Node being operated upon.

	public:
		// CONSTRUCTORS AND DESTRUCTORS ----------------------------------

		// Initalizies an empty iterator pointing to Null.
		iterator()
		{
			current = nullptr;
		}

		// Initalizes an iterator pointing to the given Node.
		iterator(Node * startNode)
		{
			current = startNode;
		}

		// OPERATORS -----------------------------------------------------

		// Returns true if the iterator points to the same Node.
		bool operator==(const iterator& rhs) const
		{
			if (current->data == rhs.current->data && current->next == rhs.current->next && current->previous == rhs.current->previous)
			{
				return true;
			}

			return false;
		}

		// Returns true if the iterator DOES NOT point to the same Node.
		bool operator!=(const iterator& rhs) const
		{
			if (current->data != rhs.current->data && current->next != rhs.current->next && current->previous != rhs.current->previous)
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
			return (*this)++;
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
			return (*this)--;
		}
	};

	// Creates an iterator at the Head of the LinkedList.
	iterator begin() const
	{
		iterator temp(head);
		return temp;
	}

	// Creates an iterator at the Tail of the LinkedList.
	iterator end() const
	{
		iterator temp(tail);
		return temp;
	}

	// CONSTRUCTORS AND DESTRUCTORS --------------------------------------

	// Default Constructor. Initializes head and tail to Null.
	tDoubleLinkedList()
	{
		Node * temp = new Node;
		temp->data = NULL;
		temp->next = nullptr;
		temp->previous = nullptr;
		head = temp;
		tail = head;
	}

	// Copy Constructor.
	tDoubleLinkedList(const tDoubleLinkedList& other)
	{
		// TODO
	}

	// Destructor.
	~tDoubleLinkedList()
	{
		// TODO
	}

	// UTILITY -----------------------------------------------------------

	// please delete this after testing,,,, TODO
	T& deletThis()
	{
		return head->next->data;
		// WHAT??? THIS ACTUALLY WORKS????? HEL L O
		// This is really gross and cheesy looking but also has a lot of uses.
	}

	// Adds element to the front (Head).
	void push_front(const T& val)
	{
		Node * temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
	}

	// Adds element to the back (Tail).
	void push_back(const T& val)
	{
		Node * temp = new Node;
		temp->data = val;
		temp->previous = tail;
		tail = temp;
	}

	// Removes element from front (Head)
	void pop_front()
	{
		// Means this will only run if there is a head to begin with.
		if (head->data != NULL && size() > 0)
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
		if (tail->data != NULL && size() > 0)
		{
			Node * temp = tail;
			tail = tail->previous;
			delete temp;
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
		for (auto it = begin(); it != end(); ++it)
		{
			/*if (it.currentNode().next->data == val)
			{
				Node  * temp = it.currentNode().next;
				it.currentNode().next = it.currentNode().next->next;
				delete temp;
			}*/

			// TODO
		}
	}

	// Returns true is there are no elements.
	bool empty() const
	{
		if (head == tail && head->data == NULL)
		{
			return true;
		}

		return false;
	}

	// Returns the size of the LinkedList.
	size_t size() const
	{
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
		for (auto it = begin(); it != end(); ++it)
		{
			// It doesn't matter if this is pop_front or pop_back.
			// Functionally the same.
			pop_front();
		}
	}

	// Resizes the LinkedList to contain the given number of elements.
	// New elements are default initialized.
	void resize(size_t newSize)
	{
		// This should only run if the newsize is greater than our current size.
		if (newSize > size())
		{
			for (auto it = begin(); it != end(); ++it)
			{
				push_back(0);
			}
		}
	}

	// OPERATORS ---------------------------------------------------------

	tDoubleLinkedList& operator=(const tDoubleLinkedList& rhs)
	{
		// TODO
	}
};


// PROGRESS
// 24/28 Baseline functions done.
// Still needed:
//	 At least 1 sorting function (Pick from: Bubble, Insert, Merge).
// Stretch goals:
//   Additional functions: Reverse, Unique, Insert(?)

// Fix these:
// Gordo problem #1:
// When a list is created, head and tail are the same cell. As intended.
// When push_front is called it adds a cell in front of the head, replacing it as new head. As intended.
// At no point is tail ever changed to not be that Null starting node.
// This means that when things are added AFTER the tail, a null value, nullpointing node is revieled to the array. NOT AS INTENDED.

// Gordo problem #2:
// A large amount of functions have suddenly stopped working.
// This may be because of changes to how the list handles itself that happened at... some point.