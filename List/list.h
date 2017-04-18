//list.h

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

class List
{
	public:
	
		List();									//default constructor
		List(const List& src);					//copy constructor
		~List();								//destructor
		
		void append(double item);				//append a new item to the end of the list
		int length() const;						//return the number of items in the list
		int index(double item);					//return index of value item, or -1 if not found
		void insert(int index, double item);	//insert item in position index
		double pop(int index);					//delete the item in position index and return it
		void remove(double item);				//remove the first occurrence of the value item
		std::string toString();
		
		double& operator[](int index);			//indexing operator
		List& operator=(const List& src);		//assignment operator
		List& operator+=(const List& src);		//concatenation operator
		
	private:
	
		static const int INITIAL_CAPACITY = 10;
		
		double *data;
		int capacity;
		int count;
		
		void deepCopy(const List& src);
		void expandCapacity();
		
		friend std::ostream& operator<<(std::ostream& os, List& list);
		
};

std::ostream& operator<<(std::ostream& os, List& list);

#endif
