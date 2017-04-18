/*
//Matt Iammarino and Steven Duvall
CS-271
A program that creates a Min Priority Queue
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

/*==============================================================================
Default Constructor
PreCondition:There is not a pq yet constructed 
PostCondition: An empty pq object is allocated with capacity of default(100)
and the heapSize is set to 0
==============================================================================*/
template <class KeyType>
	MinPriorityQueue<KeyType>::MinPriorityQueue()
	{
		A = new KeyType*[100];
		heapSize = 0;
		capacity = 100;
		for(int i = 0; i < capacity; i++)
		{
			KeyType* temp = new KeyType;
			A[i] = temp;
			
			
		}
		
	}
/*==============================================================================
Constructor
PreCondition:There is not a pq yet constructed and n is an integer for the
capacity of pq
PostCondition: An empty pq object is allocated with capacity of n and heapSize 0
==============================================================================*/
template <class KeyType>
	MinPriorityQueue<KeyType>::MinPriorityQueue(int n)
	{
		A = new KeyType*[n];
		heapSize = 0;
		capacity = n;
		for(int i = 0; i < capacity; i++)
		{
			KeyType* temp = new KeyType;
			A[i] = temp;
			
			
		}
		
		
	}



/*==============================================================================
Copy Constructor
PreCondition:There is a pre-existing pq object, pq, that is to be copied
PostCondition: A pq object is created as an exact copy of the object passed in.
The object that was passed in remains unchanged
==============================================================================*/
template <class KeyType>
	MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq)
	{
		heapSize = pq.heapSize;
		capacity = pq.capacity;
		
		A = new KeyType*[capacity];
		
		
		for(int i = 0; i < capacity; i++)
		{
			KeyType* temp = new KeyType;
			A[i] = temp;
			*(A[i]) = *(pq.A[i]);
			
		}
		
			
	}

/*==============================================================================
Minimum
PreCondition:There is a pre-existing pq object
PostCondition: The pq object is unchanged and a pointer to the minimum is returned
==============================================================================*/
template <class KeyType>
KeyType*	MinPriorityQueue<KeyType>::minimum()
{	
	if(heapSize <= 0)
		throw EmptyError();
	else
		return A[0];
	
	
}

/*==============================================================================
extractMin()
PreCondition:There is a pre-existing pq object to extract the minimum from
PostCondition: The pq object contains the same elements as before besides the 
minimum element that was extracted
==============================================================================*/
template <class KeyType>
KeyType*	MinPriorityQueue<KeyType>::extractMin()
{
	KeyType *theMin;
	if(heapSize <= 0)
		throw EmptyError();
	else
	{
		theMin = A[0];
		A[0] = A[heapSize-1];
		heapSize--;
		heapify(0);
	}
		
	return theMin;
	
}

/*==============================================================================
decreaseKey
PreCondition:There is a pre-existing pq object that we can decrease a key in
PostCondition: The pq objects contains the same elements as before besides the
key at the given index, which has been decreased
==============================================================================*/
template <class KeyType>
void	MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
	if(*(key) >= *(A[index]))
		throw KeyError();
	else if(index >= heapSize || index < 0)
		throw IndexError();
	else
	{
		A[index] = key;
		while(A[parent(index)] > A[index])
		{
			swap(index,parent(index));
			index = parent(index);
		}
	}
	
	
}

/*==============================================================================
Insert
PreCondition:There is a pre-existing pq object in which we can insert a key
PostCondition: The elements in the pq object remain the same but a new key
has been inserted and the pq has been arranged to maintain the characteristics
of a priority queue
==============================================================================*/
template <class KeyType>
void	MinPriorityQueue<KeyType>::insert(KeyType* key)
{
	if(heapSize == capacity)
		throw FullError();
	else
	{
		A[heapSize] = key;
		heapSize++;
		int index = heapSize-1;
		
		while(*(A[index]) < *(A[parent(index)]))
		{
			swap(index,parent(index));
			index = parent(index);
		}
	}
	
}

/*==============================================================================
Empty
PreCondition:There is a pre-existing pq object to check if it is empty
PostCondition: The pq object is unchanged and a boolean is returned of whether
it was empty or not
==============================================================================*/
template <class KeyType>
bool	MinPriorityQueue<KeyType>::empty() const
{
	if(heapSize == 0)
		return true;
	else
		return false;
	
	
}

/*==============================================================================
toString()
PreCondition: A pq object exists to call the toString function on
PostCondition: The pq object is unchanged and pq is returned in string
form
==============================================================================*/
template <class KeyType>
std::string	MinPriorityQueue<KeyType>::toString() const
{
	string value = "[";
	KeyType arrayVal;
	
	for(int k = 0; k < heapSize; k++)
	{
		ostringstream seq;
		if(k == heapSize -1)
		{
			arrayVal = *(A[k]);
			seq<<arrayVal;
			value+= seq.str();	
		}
		else
		{
			arrayVal = *(A[k]);
			seq<<arrayVal;
			value+= seq.str() + ",";
		}
		
	}
	
	
	value+= "]";
	

	
	return value;
	
	
}

/*==============================================================================
Cout Operator
PreCondition: A pq object exists to call the cout operator
PostCondition: The pq object is unchanged and the toString for the
object returns the pq in string form
==============================================================================*/
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq)
{
	stream<<pq.toString()<<endl;
	return stream;
	
	
}

