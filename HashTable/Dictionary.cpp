//Dictionary.cpp
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases  

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

/*===============================================
Empty method
Precondition: A valid Dictionary object
PostConditon: The Dictionary is unchanged, 
	and a boolean is returned.
===============================================*/
template<class KeyType>
bool Dictionary<KeyType>::empty()
{
	for(int i = 0; i < slots; i++)
	{
		List<KeyType*> *current1 = &table[i];	// creating list object
		Node<KeyType*> *current = current1 -> head;	//creating node within the list object
		if(current != NULL)
			return false;
	}
	return true;
}







