//DoubleLinkedList.cpp

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

template<class ItemType>
List <ItemType>::List()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

template<class ItemType>
List<ItemType>::List(const List<ItemType>& src)
{
	deepCopy(src);
}

template<class ItemType>
List<ItemType>::~List()
{
	Node<ItemType> *current = head;
	while (current != NULL)
	{
		Node<ItemType> *nextNode = current -> next;
		delete current;
		current = nextNode;
	}
}

template<class ItemType>
void List<ItemType>::append(ItemType item)
{
	if (head != NULL)
	{
		Node<ItemType> *nodePrev = tail;
		Node<ItemType> *newNode = new Node<ItemType>(item, NULL, tail);
		tail -> next = newNode; 
		tail = newNode;
	}
	else
	{
		Node<ItemType> *newNode = new Node<ItemType>(item, NULL, head); 
		head = newNode;
		tail = newNode;
	}
	count++;
	
}

template<class ItemType>
void List<ItemType>::insert(int index, ItemType item)
{
	if ((index < 0) || (index > count))
	{
		cerr << "Index out of range" << endl;
		exit(1);
	} 
	else if (index == count)
	{
		append(item);
	}	
	else if(index == 0)
	{
		Node<ItemType> *newNode = new Node<ItemType>(item, head, NULL);
		Node<ItemType> *current = head;
		head = newNode;
		current -> prev = newNode;
		count ++;
	}
	else
	{
		Node<ItemType> *current = head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current -> next;
		}
		Node<ItemType> *newNode = new Node<ItemType>(item, current -> next, current);
		current -> next = newNode;
		current = current -> next;
		current -> prev = newNode;
		count++;
	}	
}

template<class ItemType>
int List<ItemType>::length() const
{
	return count;
}

template<class ItemType>
int List<ItemType>::index(ItemType indexItem)
{
	Node<ItemType> *current = head;
	for(int i = 0; i < count; i++)
	{
		if (current != NULL)
		{
			if(current -> item == indexItem)
				return i;
			current = current -> next;
		}
	}
	return -1;
}

template<class ItemType>
ItemType List<ItemType>::pop(int index)
{
	
	if ((index < 0) || (index >= count))
	{
		cerr << "Index out of range" << endl;
		exit(1);
	}
	else if (count == 1)
	{
		Node<ItemType> *current = head;
		ItemType toReturn = current -> item;
		delete current;
		head = NULL;
		tail = NULL;
		count--;
		return toReturn;
	}
	else if (index == 0)
	{
		Node<ItemType> *toDelete = head;
		head = toDelete -> next;
		head -> prev = NULL;
		ItemType toReturn = toDelete -> item;
		delete toDelete;
		count--;
		return toReturn;
	}
	else if (index == count)
	{
		Node<ItemType> *current = head;
		Node<ItemType> *toDelete = tail;
		tail = tail -> prev;
		tail -> next = NULL;
		ItemType toReturn = toDelete -> item;
		delete toDelete;
		count--;
		return toReturn;
	}
	else
	{
		Node<ItemType> *current = head;
		for (int i = 0; i < index - 1; i++)
		{
			current = current -> next;
		}
		Node<ItemType> *toDelete = current -> next;
		current -> next = current -> next -> next;
		
		current -> next -> prev = current;

		ItemType toReturn = toDelete -> item;
		delete toDelete;
		count--;
		return toReturn;
	}  
}

template<class ItemType>
void List<ItemType>::remove(ItemType del)
{
	if(count <= 0)
	{
		cerr << "Operation on an empty list" << endl;
		exit(1);
	}
	int tempIndex = index(del);
	if (tempIndex == -1)
	{
		cerr << "Item not found" << endl;
		exit(1);
	}
	else
	{
		ItemType tempPop = pop(tempIndex);
		return;
	}
}

template<class ItemType>
ItemType& List<ItemType>::operator[](int indexItem)
{
	if ((indexItem < 0) || (indexItem > count))
	{
		cerr << "Index out of Range" << endl;
		exit(1);
	}
	if(indexItem == 0)
	{
		return head -> item;
	}
	Node<ItemType> *current = head;
	while(current -> next != NULL) 
	{
		for(int i = 0; i < count; i++)
		{
			if(i == indexItem)
				return current -> item;
			current = current -> next;
		}
	}
}

template<class ItemType>
List<ItemType>& List<ItemType>::operator=(const List<ItemType>& src)
{
	if(this == &src)
		return *this;
	deepCopy(src);
	return *this;
}

template<class ItemType>
List<ItemType>& List<ItemType>::operator+=(const List<ItemType>& src)
{
	Node<ItemType> *current = head;
	Node<ItemType> *secondStart = src.head;
	if (count == 0)
	{
		*this = src;
	}
	if (src.count == 0)
	{
		return *this;
	}
	while(current != NULL)
	{
		current = current -> next;
	}
	while(secondStart != NULL)
	{
		append(secondStart -> item);
		secondStart = secondStart -> next;
	}
	return *this;
}

template<class ItemType>
string List<ItemType>::toString()
{
	Node<ItemType> *current = head;
	stringstream s;
	if (count == 0)
	{
		s << "List is Empty" << endl;
	}
	while(current != NULL)
	{
		s << current -> item << ", ";
		current = current -> next;
	}
	return s.str();
}

template<class ItemType>
void List<ItemType>::deepCopy(const List<ItemType>& src)
{
	 Node<ItemType> *current = src.head;
	 
	 if (src.count == 0)
	 {
	 	tail = NULL;
	 	head = NULL;
	 	return;
	 }
	 
	 Node<ItemType> *newL = new Node<ItemType>(current -> item, NULL, NULL);
	 Node<ItemType> *newHead = newL;

	 while(current -> next != NULL)
	 {
		newL -> next = new Node<ItemType>(current -> next -> item, NULL, newL);
		current = current -> next;
		newL = newL -> next;
		tail = newL;
		count++;
	 }
	 head = newHead;
}

template<class ItemType>
ostream & operator << (ostream &os, List<ItemType> rat) {
	return os << rat.toString();}

