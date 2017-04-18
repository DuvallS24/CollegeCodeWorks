/*
Matt Iammarino
CS-271
A program that creates a Min Heap
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>


using namespace std;


/*==============================================================================
Default Constructor
PreCondition:There is not a heap yet constructed and n is an integer for the
capacity of heap, or the defaul capacity if no n is passed in
PostCondition: An empty MinHeap object is allocated with capacity of n 
==============================================================================*/
template <class KeyType>
	MinHeap<KeyType>::MinHeap(int n)
	{
		A = new KeyType*[n];
		heapSize = 0;
		capacity = n;
		
		
	}
/*==============================================================================
Constructor using an Array
PreCondition:There is not a heap yet constructed and initA is an array with 
type KeyType and capacity of n
PostCondition: A MinHeap object is created with the values from initA and has
a capacity of n
==============================================================================*/
template <class KeyType>
	MinHeap<KeyType>::MinHeap(KeyType* initA[], int n)
	{
		
		capacity = n;
		heapSize = 0;
		A = new KeyType* [capacity];
		for(int k = 0; k < n; k++)
		{
			*(A[k]) = *(initA[k]);
		}
		
		buildHeap();
		
	}
/*==============================================================================
Copy Constructor
PreCondition:There is not a heap yet constructed and heap is a pre-existing 
MinHeap of type KeyType
PostCondition: A MinHeap object is constructed as an exact copy of heap
==============================================================================*/	

template <class KeyType>
	MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap)
	{
		
		copy(heap);
		
	}
/*==============================================================================
Destructor
PreCondition:There is a MinHeap Object
PostCondition: The MinHeap object has been destroy (or deleted)
==============================================================================*/	
	
template <class KeyType>
	MinHeap<KeyType>::~MinHeap()
	{
		destroy();
		
	}
/*==============================================================================
Heapify
PreCondition: The two children of index are the roots of MinHeaps
PostCondition: The tree rooted at index is a valid MinHeap
==============================================================================*/
	
template <class KeyType>
void	MinHeap<KeyType>::heapify(int index)
{
	int left = leftChild(index);
	int right = rightChild(index);
	int smallest;
	
	if(left < heapSize && *(A[left]) < *(A[index]))
		smallest = left;
	else
		smallest = index;
	
	if(right < heapSize && *(A[right]) < *(A[smallest]))
		smallest = right;
	
	if(smallest != index)
	{
		swap(index,smallest);
		heapify(smallest);
	}
	
		
}
/*==============================================================================
BuildHeap
PreCondition: There is an array of values but may not be a valid MinHeap
PostCondition: A valid MinHeap has been built with the same values as before and
the heapSize is the same size as the capacity
==============================================================================*/

template <class KeyType>
void	MinHeap<KeyType>::buildHeap()
{
	heapSize = capacity;
	
	for(int index = (capacity/2) -1; index >= 0; index--)
	{
		heapify(index);
	}
	
	
}
/*==============================================================================
HeapSort
PreCondition:There is a valid MinHeap and array with size capacity
PostCondition: The HeapSize has been decreased to 1 and the array of values
are in sorted order. Sorted also contains the values of the Heap in sorted order
==============================================================================*/

template <class KeyType>
void	MinHeap<KeyType>:: heapSort(KeyType* sorted[])
{
	
	for(int index = (capacity - 1); index >=1; index--)
	{
		swap(0,index);
		heapSize--;
		heapify(0);
		
	}
	
	
	for(int k = capacity -1 ; k >= 0; k--)
		sorted[(capacity-1) - k] = A[k];
	
	for(int i = 0; i < capacity; i++)
		A[i] = sorted[i];
	
}
/*==============================================================================
Assignment Operator
PreCondition:There are two MinHeaps
PostCondition: One MinHeap is set to the exact copy of the other
==============================================================================*/

template <class KeyType>
MinHeap<KeyType>&	MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap)
{
	destroy();
	copy(heap);
	return *this;
	
	
}
/*==============================================================================
Swap
PreCondition:There is an array, A, of values and index1 and index2 are both
valid indices of A
PostCondition: The values of the array are the same, but the value that was
at index1is now at index2 and the value that was at index2 is now at index 1
==============================================================================*/
template <class KeyType>
void 	MinHeap<KeyType>::swap(int index1, int index2)
{
	KeyType* temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;

}
/*==============================================================================
Copy
PreCondition:There are two MinHeap objects, one calling the function and the
other being passed in as a parameter
PostCondition: The first MinHeap object becomes an exact copy of the heap passed
in the parameter
==============================================================================*/
template <class KeyType>
void 	MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap)
{
	heapSize = heap.heapSize;
	capacity = heap.capacity;
	
	A = new KeyType* [capacity];
	
	for(int k = 0; k < capacity; k++)
	{
		heap.A[k] = A[k];
	}
		
}
/*==============================================================================
Destroy
PreCondition:There is a MinHeap 
PostCondition: The MinHeap is destroyed and the heapSize and capacity are 0
==============================================================================*/
template <class KeyType>
void 	MinHeap<KeyType>::destroy()
{
	
	delete[] A;
	heapSize = 0;
	capacity = 0;

}

/*==============================================================================
toString()
PreCondition: A MinHeap object exists to call the toString function on
PostCondition: The MinHeap object is unchanged and heap is returned in string
form
==============================================================================*/
template <class KeyType>
std::string 	MinHeap<KeyType>::toString() const
{

	string value = "[";
	KeyType arrayVal;
	
	for(int k = 0; k < capacity; k++)
	{
		ostringstream seq;
		if(k == capacity -1)
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
		if( k == heapSize -1)
		{
			value+= "|";
		}
	}
	
	
	value+= "]";
	
	
	
	

	
	return value;
	
	
}
/*==============================================================================
Cout Operator
PreCondition: A MinHeap object exists to call the cout operator
PostCondition: The MinHeap object is unchanged and the toString for the
object returns the heap in string form
==============================================================================*/
template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeap<KeyType>& heap)
{
	stream<<heap.toString()<<endl;
	return stream;
}
	
	
	







