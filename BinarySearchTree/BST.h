// BST 
// Sherief and Steven 
// CS 271: Data Structers

#ifndef _BST_
#define _BST_

#include <iostream>
#include <sstream>
#include <string>
#include "node.h"


template <class KeyType> 
class BST
{
	public: 
		BST();
		BST(const BST<KeyType>& bst);
		~BST();
		bool empty();           				// return true if empty; false o/w
		KeyType *get(const int k);     	// return first element with key equal to k
		void insert(KeyType *k);				// insert k into the tree
		void remove(const KeyType& k);			// delete first element with key equal to k
		KeyType *maximum(); 					// return the maximum element
		KeyType *minimum();    					// return the minimum element
		KeyType *successor(const KeyType& k);	// return the successor of k
		KeyType *predecessor(const KeyType& k); // return the predecessor of k
		std::string inOrder() const;  		// return string of elements from an inorder traversal
		std::string preOrder() const;       // return string of elements from a preorder traversal
		std::string postOrder() const;      // return string of elements from a postorder traversal

	private:
		Node<KeyType> *root;
		Node<KeyType> *copy(Node<KeyType> *node);
		void destruct(Node<KeyType> *node);
		std::string pre(Node<KeyType> *node) const;
		std::string order(Node<KeyType> *node) const;
		std::string post(Node<KeyType> *node) const;		
		Node<KeyType> *getNode(const KeyType& k, Node<KeyType> *node);
		void ins(KeyType *k, Node<KeyType> *node);
		KeyType *max(Node<KeyType> *node);                     // return the maximum element
		KeyType *min(Node<KeyType> *node);			
};

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const BST<KeyType>& bst);

class Empty { };	//BST Empty exception
class Key { };	    //BST Key exception
class Index { };    //BST Index exception

#include "BST.cpp"
#endif


