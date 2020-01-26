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

	// Creates a const iterator pointing to the first element.
	const iterator begin() const
	{
		iterator temp(head);
		return temp;
	}

	// Creates a const iterator pointing to one past the last element.
	const iterator end() const
	{
		// NULL can also be uaed here or whatever TODO fix this awful comment :ok_hand:
		iterator temp(tail);
		++temp;
		return temp;
	}

	// CONSTRUCTORS AND DESTRUCTORS --------------------------------------

	// Default Constructor. Initializes head and tail to Null.
	tDoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
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

	// Adds element to the front (Head).
	void push_front(const T& val)
	{

		Node * temp = new Node;
		temp->data = val;
		temp->next = head;
		temp->previous = NULL;
		if (head != NULL)
		{
			head->previous = temp;
		}
		else
		{
			tail = temp;
		}
		head = temp;
	}

	// Adds element to the back (Tail).
	void push_back(const T& val)
	{
		Node * temp = new Node;
		temp->data = val;
		temp->previous = tail;
		temp->next = NULL;
		if (tail != NULL)
		{
			tail->next = temp;
		}
		else
		{
			head = temp;
		}
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
		Node * node = head;
		while (node != NULL)
		{
			if (node->data == val)
			{
				if (node != head)
				{
					node->previous->next = node->next;
				}
				else
				{
					head = head->next;
				}

				if (node != tail)
				{
					node->next->previous = node->previous;
				}
				else
				{
					tail = tail->previous;
				}

				delete node;
				break;
			}

			node = node->next;
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
			// TODO
		}
	}

	// Resizes the LinkedList to contain the given number of elements.
	// New elements are default initialized.
	void resize(size_t newSize)
	{
		int actualSize = size();

		// This should only run if the newSize is greater than our current size.
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