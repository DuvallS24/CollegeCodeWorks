// test_pq.cpp
//Matt Iammarino and Steven Duvall

#include <iostream>
#include <assert.h>
#include "pq.h"
#include <string>

using namespace std;

void test_constructors()
{
	MinPriorityQueue<int> pq1;
	
	assert(pq1.length() == 0);
	
	assert(pq1.empty() == true);
	
	MinPriorityQueue<int> pq2(5);
	
	assert(pq2.length() == 0);
	
	assert(pq2.empty() == true);
	
	
	
	int *a=new int;
	*a=5;
	pq2.insert(a);
	
	MinPriorityQueue<int> pq3(pq2);
	
	assert(pq2.toString() == pq3.toString());
	assert(pq3.length() == pq2.length());
	assert(pq3.empty() == false);
		
}

void test_minimum()
{
	MinPriorityQueue<int> pq(3);
	for(int k = 0; k < 3; k++)
	{
		int *a = new int;
		*a = k+1;
		pq.insert(a);
	}
	
	int* min = pq.minimum();
	
	assert(*min == 1);
	try
	{
		
		MinPriorityQueue<int> pq1(0);
		int*min1 = pq1.minimum();
	}
	catch (EmptyError exception)
	{
		cerr<<"Error: MPQ is empty! (Minimum)"<<endl;
	}
	
	
	MinPriorityQueue<int> pq2(3);
	for(int k = 0; k < 3; k++)
	{
		int *a = new int;
		*a = 2;
		pq2.insert(a);
	}
	
	int* min2 = pq2.minimum();
	assert(*min2 == 2);
	
}

void test_extract()
{
	
	MinPriorityQueue<int> temp(3);
	for(int k = 0; k<3; k++)
	{
		int *a = new int;
		*a = k;
		temp.insert(a);
	}
	//[0,1,2] -> [1,2,|2]
	int *min = temp.extractMin();
	assert(*min == 0);
	assert(temp.toString() == "[1,2]");
	
	
	MinPriorityQueue<int> temp2(0);
	try{
		temp2.extractMin();
	}
	catch (EmptyError exception)
	{
		cerr<<"Error: MPQ is empty! (Extract Min)"<<endl;
	}
	
	MinPriorityQueue<int> temp3(3);
	for(int k = 0; k < 3; k++)
	{
		int *a = new int;
		*a = 2;
		temp3.insert(a);
	}
	
	int* min2 = temp3.extractMin();
	assert(*min2 == 2);
	
	assert(temp3.toString() == "[2,2]");

}
void test_decreaseKey()
{
	MinPriorityQueue<int> p1(3);
	for(int k = 0; k<3; k++)
	{
		int *a = new int;
		*a = k;
		p1.insert(a);
	}
	int *val = new int;
	*val = 1;
	p1.decreaseKey(2,val);
	//[0,1,2] -> [0,1,1]
	assert(p1.toString() == "[0,1,1]");
	
	
	MinPriorityQueue<int> p2(3);
	for(int k = 0; k<3; k++)
	{
		int *a = new int;
		*a = k;
		p2.insert(a);
	}
	int *val2 = new int;
	*val2 = 1;
	try{
		p1.decreaseKey(0,val);
	}
	catch (KeyError exception)
	{
		cerr<<"Error: The key value is not less than original!"<<endl;
	}
	catch (IndexError exception2)
	{
		cerr<<"Error: Trying to access invalid index!"<<endl;
	}
	
	
	MinPriorityQueue<int> p3(3);
	for(int k = 0; k<3; k++)
	{
		int *a = new int;
		*a = k;
		p3.insert(a);
	}
	int *val3 = new int;
	*val3 = 1;
	try{
		p1.decreaseKey(4,val);
	}
	catch (KeyError exception)
	{
		cerr<<"Error: The key value is not less than original!"<<endl;
	}
	catch (IndexError exception2)
	{
		cerr<<"Error: Trying to access invalid index!"<<endl;
	}
	
	
}
void test_insert()
{
	MinPriorityQueue<int> p(10);
	for(int k = 0; k<10; k++)
	{
		int *a = new int;
		*a = k;
		p.insert(a);
	}
	assert(p.length() == 10);
	assert(p.toString() == "[0,1,2,3,4,5,6,7,8,9]");
	
	MinPriorityQueue<int> p1(10);
	try{
		for(int k = 0; k<11; k++)
		{
			int *a = new int;
			*a = k;
			p1.insert(a);
		}
	}
	catch (FullError exception)
	{
		cerr<<"Error: Queue is full!"<<endl;
	}
	
	
	


}



int main()
{
	test_constructors();
	test_minimum();
	test_extract();
	test_decreaseKey();
	test_insert();
	
	
	return 0;
}


