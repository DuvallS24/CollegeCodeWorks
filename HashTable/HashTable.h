//HashTable.h
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#ifndef HASHTABLE
#define HASHTABLE

#include <iostream>
#include "TemplateLinkedList.h"

template <class KeyType>
class HashTable
{
	public:
		HashTable(int numSlots);	// Constructor 
		~HashTable();	// Destructor 
		
		KeyType* get(const KeyType& k) const;	// Get method, getting a string from a HashTable  
		void insert(KeyType *k);	// Insert method, inserting string to a HashTable
		void remove(const KeyType& k); // Remove method, removes intance of a string from HashTable
		
		std::string toString(int slot) const;	// toString method

		int slots;	// Number of slots (Intance Variable)
		List<KeyType*> *table; //an array of List<KeyType*>'s
		
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const HashTable<KeyType>& ht);

class Empty { };	//HashTable Empty exception
class Key { };	    //HashTable Key exception
class Index { };    //HashTable Index exception

#endif

#include "HashTable.cpp"
