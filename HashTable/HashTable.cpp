//HashTable.cpp
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "Test.cpp"

using namespace std;

/*==================================================
Default Constructor
Precondition: -N/A-
Postcondition: A HashTable object with an array of 
	length numSlots and instance variable slots
	equal to numSlots
==================================================*/
template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots)
{
	slots = numSlots;
	table = new List<KeyType*>[numSlots];
}

/*==================================================
Destructor
Precondition: A valid HashTable object with an
	initialized array and instance variable
	slots.
Postcondition: Object is deallocated
==================================================*/
template <class KeyType>
HashTable<KeyType>::~HashTable()
{
	delete [] table;
}

/*===================================================
get method
Precondition: A valid HashTable object
Postcondition: HashTable is unchanged, but a pointer
	to a specific object is returned if found.
	Otherwise, throws an instance of Key.
===================================================*/
template <class KeyType>
KeyType* HashTable<KeyType>::get(const KeyType& k) const
{
	int slot = k.hash(slots);
	List<KeyType*> *current1 = &table[slot];
	Node<KeyType*> *current = current1 -> head;

	if(current == NULL)
	{
		throw Empty();
	}
	while(current != NULL)
	{
		if (*(current) -> item  == k)
			return current -> item;
		else
		{	
		    current = current -> next;

		}
	}
	throw Key();
}

/*===================================================
insert method
Precondition: A valid HashTable object
Postcondition: The object of KeyType is inserted
	into the HashTable that the method was used on.
===================================================*/
template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k)
{
	int slot = k -> hash(slots);
	List<KeyType*> *current1 = &table[slot];
	Node<KeyType*> *current = current1 -> head; 
	
	current1 -> insert(0, k);
}

/*===================================================
remove method
Preconditon: A valid HashTable object
Postcondition: The same HashTable, but with the item
	k removed from the instance variable table if
	found.
===================================================*/
template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k)
{
	KeyType *temp = get(k);
	
	int slot = k.hash(slots);
	table[slot].remove(temp);
}
/*====================================================
toString method
====================================================*/
template <class KeyType>
string HashTable<KeyType>::toString(int slot) const
{
	List<KeyType*> *current1 = &table[slot];
	Node<KeyType*> *current = current1 -> head;
	
	stringstream s;
		
	while(current != NULL)
	{
		s << current -> item -> key << ", ";

		current = current -> next;
	}	
	string returnString = s.str();
	return returnString.substr(0, returnString.size() - 2);
}


/*====================================================
stream insertion operator overload
====================================================*/
template <class KeyType>
ostream& operator<<(ostream& stream, const HashTable<KeyType>& ht)
{
	for(int i = 0; i < ht.slots; i++)
	{
		stream << ht.toString(i) << "\n";
	}
	return stream;
}



