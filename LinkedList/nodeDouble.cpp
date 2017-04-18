//nodeDouble.cpp

#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

template<class ItemType>
Node<ItemType>::Node()
{
	next = NULL;
	prev = NULL;
}

template<class ItemType>
Node<ItemType>::Node(ItemType initItem)
{
	item = initItem;
	next = NULL;
	prev = NULL;
}

template<class ItemType>
Node<ItemType>::Node(ItemType initItem, Node<ItemType> *initNext)
{
	item = initItem;
	next = initNext;
	prev = NULL;
}

template<class ItemType>
Node<ItemType>::Node(ItemType initItem, Node<ItemType> *initNext, Node<ItemType> *initPrev)
{
	item = initItem;
	next = initNext;
	prev = initPrev;
}
