#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include "nodeDouble.h"

template <class ItemType> class List;   // so that g++ knows what List<T> is in prototype of operator<< below

template <class ItemType>
std::ostream& operator<<(std::ostream &os, List<ItemType> &l);  // prototype for operator<<

template <class ItemType>
class List
{
	public:
	
		List();									//default constructor
		List(const List<ItemType>& src);		//copy constructor
		~List();								//destructor
		
		void append(ItemType item);				//append a new item to the end of the list
		int length() const;						//return the number of items in the list
		int index(ItemType item);				//return index of value item, or -1 if not found
		void insert(int index, ItemType item);	//insert item in position index
		ItemType pop(int index);				//delete the item in position index and return it
		void remove(ItemType item);				//remove the first occurrence of the value item
		std::string toString();
		
		ItemType& operator[](int index);			//indexing operator
		List<ItemType>& operator=(const List<ItemType>& src);		//assignment operator
		List<ItemType>& operator+=(const List<ItemType>& src);		//concatenation operator
		
	private:
	
		static const int INITIAL_CAPACITY = 10;
		
		Node<ItemType> *head;
		Node<ItemType> *tail;
		int count;
		
		void deepCopy(const List<ItemType>& src);
		
		friend std::ostream& operator<< <ItemType> (std::ostream &os, List<ItemType> &l);   // notice <T> after operator<<
		
};

#include "DoubleLinkedList.cpp"
#endif
