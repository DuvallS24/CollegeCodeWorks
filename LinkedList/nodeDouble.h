//nodeDouble.h

#ifndef NODEDOUBLE_H
#define NODEDOUBLE_H

#include <iostream>
#include <string>

template<class ItemType>
class Node
{
	public:
	
		Node();
		Node(ItemType initItem);
		Node(ItemType initItem, Node<ItemType> *initNext);
		Node(ItemType initItem, Node<ItemType> *initNext, Node<ItemType> *initPrev);
		
		ItemType item;
		Node<ItemType> *next;
		Node<ItemType> *prev;
};

#include "nodeDouble.cpp"
#endif
		
