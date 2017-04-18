// test_heap.cpp
//Matt Iammarino

#include <iostream>
#include <assert.h>
#include "heap.h"
#include <string>

using namespace std;

void test_heapSort()
{
	//These examples build a heap from an array and then sort them
	//and check to see whether the heapSort function sorts them correctly
	int temp[6] = {5,6,2,1,3,7};
	
	MinHeap<int> theHeap1(temp,6);
		
	theHeap1.heapSort(temp);
	
	assert(theHeap1.toString() == "[1,|2,3,5,6,7]");
	
	int temp2[0] = { };
	
	MinHeap<int> theHeap2(temp2,0);
	
	theHeap2.heapSort(temp2);
	
	assert(theHeap2.toString() == "[]");
	
	int temp3[5] = {2,2,2,2,2};
	
	MinHeap<int> theHeap3(temp3,5);
	
	theHeap3.heapSort(temp3);
	
	assert(theHeap3.toString() == "[2,|2,2,2,2]");
	
	int temp4[10] = {1,7,3,3,4,9,0,11,87,2};
	
	MinHeap<int> theHeap4(temp4,10);
	
	theHeap4.heapSort(temp4);
	
	assert(theHeap4.toString() == "[0,|1,2,3,3,4,7,9,11,87]");
	

}

void test_constructors()
{
	//testing the constructor in which a heap is constructed from an existing
	//array
	int temp[6] = {5,6,2,1,3,7};
	
	MinHeap<int> theHeap1(temp,6);
	
	assert(theHeap1.toString() == "[1,3,2,6,5,7|]");
	
	int temp2[0] = { };
	
	MinHeap<int> theHeap2(temp2,0);
	
	assert(theHeap2.toString() == "[]");
	
	
	
	//testing the copy constructor in which a heap is constructor as an
	//exact copy from a different heap
	MinHeap<int> theHeap3(theHeap1);
	
	assert(theHeap3.toString() == theHeap1.toString());
	
	
	MinHeap<int> theHeap4(theHeap2);
	
	assert(theHeap4.toString() == theHeap2.toString());
	
	
}

void test_operators()
{
	//testing the assignment operator
	int temp[3] = {3,4,2};
	
	MinHeap<int> theHeap1(temp,3);
	
	MinHeap<int> theHeap2(3);
	
	theHeap2 = theHeap1;
	
	assert(theHeap2.toString() == theHeap1.toString());
	
	
	int temp2[0] = {};
	
	MinHeap<int> theHeap3(temp2,0);
	
	MinHeap<int> theHeap4(0);
	
	theHeap4 = theHeap3;
	
	assert(theHeap4.toString() == theHeap3.toString());

	
	
	//testing the cout operator
	int temp5[5] = {3,4,5,1,7};
	
	MinHeap<int> theHeap5(temp5,5);
	
	cout<<"Heap should be [1,3,5,4,7|] and it is: "<<theHeap5.toString()<<endl;
	
	theHeap5.heapSort(temp5);
	
	cout<<"After sort, heap should be [1,|3,4,5,7] and it is: "<<theHeap5.toString()<<endl;
	
	
	
	
}




int main () 
{
	
	test_heapSort();
	test_constructors();
	test_operators();
	
	
	
	
	return 0;
}
