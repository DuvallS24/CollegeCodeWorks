//Dictionary.h
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include "HashTable.h"

template <class KeyType>
class Dictionary : public HashTable<KeyType>
{
	public:
	
		Dictionary(int tableSlots) : HashTable<KeyType> (tableSlots) { } //Constructor 
	
		bool empty(); // Empty method to check whether the Dictionary is empty or not  
		
		using HashTable<KeyType>::get;
		using HashTable<KeyType>::remove;
		using HashTable<KeyType>::insert;	//Inheriting mentioned methods from HashTable class
		using HashTable<KeyType>::toString;
		using HashTable<KeyType>::slots;
		using HashTable<KeyType>::table;		
		
};

#endif

#include "Dictionary.cpp"
