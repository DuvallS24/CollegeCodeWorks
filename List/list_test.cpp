//list_test.cpp

#include <cassert>
#include "TemplateList.h"
#include <iostream>
#include <cmath>

using namespace std;

void testEmptyConstructor()
{
	List <double>l1;
	assert(l1.length() == 0);
}

void testCopyConstructor()
{
	List l1;
	List l2(l1);
	assert(l2.length() == 0);
	List l3(l2);
	assert(l3.length() == 0);
}

void testAppend()
{
	List l1;
	l1.append(3.2);
	assert(l1.length() == 1);
	l1.append(2.2);
	assert(l1.length() == 2);
	for (int i = 0; i < 12; i++)
	{
		l1.append(i);
	}
	assert(l1.length() == 14);
}

void testInsert()
{
	List l1;
	l1.append(1.0);
	l1.append(2.0);
	l1.append(3.0);
	l1.insert(0, 0.0);
	l1.insert(1, 1.5);
	l1.insert(5, 5.0);
}

int main()
{
	testEmptyConstructor();
//	testCopyConstructor();
//	testAppend();
//	testInsert();
	
	
	return 0;
}
