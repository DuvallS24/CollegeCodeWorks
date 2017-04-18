//list.cpp

#include <string>
#include <iostream>
#include <cstdlib>
#include "strlib.h"
#include "list.h"

using namespace std;

List::List()
{
	capacity = INITIAL_CAPACITY;
	data = new double[capacity];
	count = 0;
}

List::List(const List& src)
{
	deepCopy(src);
}

List::~List()
{
	delete [] data;
}
void List::insert(int ind, double item)
{
	if((ind > count) || (ind < 0))
	{
		cerr << "Index out of range" << endl;
		exit(1);
	}
	else if (ind == count)
	{
		append(item);
	}
	else
	{
		if (count == capacity)
			expandCapacity();
		for (int i = count; i > ind; i--)
		{
			data[i] = data[i - 1];
		}
		data[ind] = item;
		count ++;
	}
}

void List::append(double item)
{
	if (count == capacity)
		expandCapacity();
	data[count] = item;
	count++;
}

int List::length() const
{
	return count;
}

int List::index(double item)
{
	int num = 0;
	while(num < count)
	{
		if (data[num] = item)
			return item;
		else
			num++;
	}
	return -1;
}

double List::pop(int ind)
{
	if((ind >= count) || (ind < 0))
	{
		cerr << "Index out of range" << endl;
		exit(1);
	}
	double toReturn = data[ind];
	if (ind == count - 1)
		count--;
	else
	{
		for(int i = ind + 1; i < count; i++)
		{
			data[i - 1] = data[i];
		}
		count--;
	}
	return toReturn;

}

void List::remove(double item)
{
	int ind = index(item);
	if((ind >= count) || (ind < 0))
	{
		cerr << "Index out of range" << endl;
		exit(1);
	}
	pop(index(item));
}


double& List::operator[](int index)
{
	if (index > count - 1)
		{
		cerr << "Index out of range" << endl;
		exit(1);
		}
	return data[index];
}

List& List::operator=(const List& src)
{
	if (this != &src)
	{
		delete [] data;
		deepCopy(src);
	}
	return *this;
}

List& List::operator+=(const List& src)
{
	count = count + src.count;
	for(int i = 0; i < src.count; i++)
	{
		double tempIndex = src.data[i];
		append(tempIndex);
	}
}

string List::toString()
{
	int num = 0;
	string init = "{";
	while(num < count - 1)
	{
		double someNumber = data[num];
		init = init + realToString(someNumber) + ", ";
		num++;
	}
	double temp = data[count - 1];
	init = init + realToString(temp) +"}";
	return init;
}

void List::deepCopy(const List& src)
{
	data = new double[src.capacity];
	for (int i = 0; i < src.count; i++)
	{
		data[i] = src.data[i];
	}
	count = src.count;
	capacity = src.capacity;
}

void List::expandCapacity()
{
	double *oldData = data;
	capacity *= 2;
	data = new double[capacity];
	for (int i = 0; i < count; i++)
	{
		data[i] = oldData[i];
	}
	delete [] oldData;
}

ostream & operator << (ostream &os, List rat) {
	return os << rat.toString();}

