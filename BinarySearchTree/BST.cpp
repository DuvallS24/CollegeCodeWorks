// BST.cpp
// Sherief and Steven 
// CS 271: Data Structers

using namespace std;

template <class KeyType> 
BST<KeyType>::BST()
/*==============================================
Constructor
Preconditions: -N/A-
Postconditions: A constructed BST with root
	initialized to NULL.
==============================================*/
{
	root = NULL;	
}


template <class KeyType> 
BST<KeyType>::BST(const BST<KeyType>& bst)
/*==============================================
Copy Constructor
Preconditions: A constructed BST object 
Postconditions: A copy constructer of a new BST 
that is a copy of the BST passed in as a parameter.
==============================================*/
{
	root = NULL; 
	copy(bst.root);
}

template <class KeyType> 
Node<KeyType>* BST<KeyType>::copy(Node<KeyType> *node)
/*==============================================
Copy Method
Preconditions: A constructed BST object
Postconditions: A copy helper method that copies 
a BST. The method is then passed into the BST copy 
constructor.
==============================================*/
{
	Node<KeyType> *newNode = new Node<KeyType>;
	if(node == NULL)
	{
		return NULL;
	}

	this->insert(node->item);
	newNode -> left = copy(node -> left);
	newNode -> right = copy(node -> right);

	return newNode;	
}

template <class KeyType> 
BST<KeyType>::~BST()
/*==============================================
Destructor
Preconditions: A constructed BST object
Postconditions: Deallocates the space that was 
allocated for the BST 
==============================================*/
{
	destruct(root);
}

template <class KeyType> 
void BST<KeyType>::destruct(Node<KeyType> *node)
/*==============================================
Destroy Method 
Preconditions: A constructed BST object
Postconditions: A destroy helper method that 
destroies a BST. The method is then passed into 
the BST destructor. 
==============================================*/
{
	if(node != NULL)
	{
		destruct(node->left);
		destruct(node->right);
		delete node;
	}	
}

template <class KeyType> 
bool BST<KeyType>::empty()
/*==============================================
Empty Method
Preconditions: A constructed BST Object
Postconditions: BST is unchanged, and a boolean
	is returned based on if the BST is empty
	or contains an item.
==============================================*/
{
	if(root == NULL)
	{
		return true;
	}
	return false;
}

template <class KeyType> 
KeyType* BST<KeyType>:: get(const int k) 
/*==============================================
Get Method
Preconditions: A constructed BST Object
Postconditions: BST is unchanged, and a KeyType*
	is returned from the tree.
==============================================*/
{
	Node<KeyType> *toReturn = getNode(k, root);
	return toReturn->item;
}

template <class KeyType> 
void BST<KeyType>::insert(KeyType *k)
/*==============================================
Insert Method
Preconditions: A constructed BST Object
Postconditions: A BST object with KeyType *k 
	inserted into the BST.
==============================================*/
{
	ins(k, root);
}

template <class KeyType> 
void BST<KeyType>::ins(KeyType *k, Node<KeyType> *node)
/*==============================================
Insert Helper Function
Preconditions: A constructed BST Object
Postconditions: A BST object with KeyType *k 
	inserted into the BST.
==============================================*/
{
	Node<KeyType> *newNode = new Node<KeyType>(k);
	if(node == NULL)
	{
		root = newNode;
	}
	else if(*k <= *(node -> item) && node -> left == NULL)
	{
		node -> left = newNode;
		newNode -> parent = node;
	}
	else if(*k > *(node -> item) && node -> right == NULL)
	{
		node -> right = newNode;	
		newNode -> parent = node;
	}
	else if(*k <= *(node -> item))
	{
		ins(k, node -> left);
	}
	else
	{
		ins(k, node -> right);
	}
}

template <class KeyType> 
void BST<KeyType>::remove(const KeyType& k)
/*==============================================
Remove Method
Preconditions: A constructed BST Object
Postconditions: A BST with the KeyType *k
	removed from the BST.
==============================================*/
{
	Node<KeyType> *child;
	Node<KeyType> *splice;
	Node<KeyType> *node = getNode(k, root);
	if(node->left == NULL || node->right == NULL)
	{
		splice = node;
	}
	else	
	{
		KeyType *splicer = predecessor(*(node->item));
		splice = getNode(*(splicer), root); 
	}
	if(splice->left != NULL)
	{
		child = splice->left;
	}
	else
	{
		child = splice -> right;
	}
	if(child != NULL)
	{
		child -> parent = splice -> parent;
	}
	if(splice->parent == NULL)
	{
		root = child;
	}
	else
	{
		if(splice == splice -> parent -> left)
		{
			splice -> parent -> left = child;
		}
		else if(splice == splice -> parent -> right)
		{
			splice -> parent -> right = child;
		}
	}
	if(splice != node)
	{
		node -> item = splice -> item;
	}	
}

template <class KeyType> 
KeyType* BST<KeyType>::maximum()
/*==============================================
Maximum Method
Preconditions: A constructed BST Object
Postconditions: The BST is unchanged, and 
	pointer of type KeyType is returned.  
	This pointer points to the max. value in the 
	BST.
==============================================*/
{
	KeyType *toReturn = max(root);
	return toReturn;
}

template <class KeyType> 
KeyType* BST<KeyType>::minimum()
/*==============================================
Minimum Method
Preconditions: A constructed BST Object
Postconditions: The BST is unchanged, and 
	pointer of type KeyType is returned.  
	This pointer points to the min. value in the 
	BST.
==============================================*/
{
	KeyType *toReturn = min(root);
	return toReturn;
}

template <class KeyType> 
KeyType* BST<KeyType>::successor(const KeyType& k)
/*==============================================
Successor Method
Preconditions: A constructed BST Object
Postconditions: Returns the successor to
	KeyType k, from the BST.
==============================================*/
{
	Node<KeyType> *nodeX = getNode(k, root);
	Node<KeyType> *nodeY;
	if(nodeX -> right != NULL)
	{
		return min(nodeX -> right);
	}

	nodeY = nodeX -> parent;

	while(nodeY != NULL && nodeX == nodeY -> right)
	{
		nodeX = nodeY;
		nodeY = nodeY -> parent;
	}
	return nodeY->item; 
}

template <class KeyType> 
KeyType* BST<KeyType>::predecessor(const KeyType& k)
/*==============================================
Predecessor Method
Preconditions: A constructed BST Object
Postconditions: Returns the predecessor to 
	KeyType k, from the BST.
==============================================*/
{
	Node<KeyType> *nodeX = getNode(k, root);
	Node<KeyType> *nodeY;
	if(nodeX -> left != NULL)
	{
		return max(nodeX -> left);
	}
	nodeY = nodeX -> parent;
	while(nodeY != NULL && nodeX == nodeY -> left)
	{
		nodeX = nodeY;
		nodeY = nodeY -> parent;
	}
	return nodeY->item;
	 
}

template <class KeyType> 
string BST<KeyType>::preOrder() const
/*==============================================
PreOrder Method
Preconditions: A constructed BST Object
Postconditions: Returns a string of the elements
	in the BST after a preOrder traversal.
==============================================*/
{
	string toReturn = pre(root);
	return toReturn.substr(0, toReturn.size() - 2);
}

template <class KeyType> 
string BST<KeyType>::inOrder() const
/*==============================================
InOrder Method
Preconditions: A constructed BST Object
Postconditions: Returns a string of the elements
	in the BST after an inOrder traversal.
==============================================*/
{
	string toReturn = order(root);
	return toReturn.substr(0, toReturn.size() - 2);
}

template <class KeyType> 
string BST<KeyType>::postOrder() const
/*==============================================
PostOrder Method
Preconditions: A constructed BST Object
Postconditions: Returns a string of the elements
	in the BST after a postOrder traversal.
==============================================*/
{
	string toReturn = post(root);
	return toReturn.substr(0, toReturn.size() - 2);
}



template <class KeyType> 
string BST<KeyType>::pre(Node<KeyType> *node) const
/*==============================================
PreOrder Helper Function
Preconditions: A constructed BST Object
Postconditions: Returns a string of the elements
	in the BST after a preOrder traversal.
==============================================*/
{
	stringstream s;
	if(node == NULL)
	{
		return "";
	}
	else
	{
		s << *(node -> item)<<", ";
		s << pre(node -> left);
		s << pre(node -> right);
	} 
	string returnString = s.str();
	return returnString;
}


template <class KeyType> 
string BST<KeyType>::order(Node<KeyType> *node) const
/*==============================================
InOrder Helper Function
Preconditions: A constructed BST Object
Postconditions: Returns a string of the elements
	in the BST after an inOrder traversal.
==============================================*/
{
	stringstream s;
	if(node == NULL)
	{
		return "";
	}
	else
	{
		s << order(node -> left);
		s << *(node -> item)<<", ";	
		s << order(node -> right);
	} 
	string returnString = s.str();
	return returnString;
}

template <class KeyType> 
string BST<KeyType>::post(Node<KeyType> *node) const
/*==============================================
PostOrder Helper Function
Preconditions: A constructed BST Object
Postconditions: Returns a string of the elements
	in the BST after a postOrder traversal.
==============================================*/
{
	stringstream s;
	if(node == NULL)
	{
		return "";
	}
	else
	{

		s << post(node -> left);
		s << post(node -> right);
		s << *(node -> item)<<", ";
	} 
	string returnString = s.str();
	return returnString;
}


template <class KeyType> 
Node<KeyType>* BST<KeyType>::getNode(const KeyType& k, Node<KeyType> *node)
/*==============================================
Get Helper Function
Preconditions: A constructed BST Object
Postconditions: BST is unchanged, and a 
	Node<KeyType>* is returned from the tree 
==============================================*/
{
	if(node == NULL)
	{
		throw Empty();	
	}
	if(k == *(node -> item))
	{
		return node;
	}
	if(k <= *(node->item))
	{
		return getNode(k, node -> left);
	}
	else 
	{
		return getNode(k, node -> right);
	}
}



template <class KeyType> 
KeyType* BST<KeyType>::max(Node<KeyType> *node)
/*==============================================
Maximum Helper Function
Preconditions: A constructed BST Object
Postconditions: The BST is unchanged, and 
	pointer of type KeyType is returned.  
	This pointer points to the min. value in the 
	BST.
==============================================*/
{
	if(node == NULL)
	{
		return NULL;
	} 
	if(node->right == NULL)
	{
		return node -> item;
	}
	return max(node->right);
}

template <class KeyType> 
KeyType* BST<KeyType>::min(Node<KeyType> *node)
/*==============================================
Minimum Helper Function
Preconditions: A constructed BST Object
Postconditions: The BST is unchanged, and 
	pointer of type KeyType is returned.  
	This pointer points to the min. value in the 
	BST.
==============================================*/
{
	if(node == NULL)
	{
		return NULL;
	} 
	if(node->left == NULL)
	{
		return node -> item;
	}
	return min(node->left);
}

template <class KeyType> 
ostream& operator<<(std::ostream& stream, const BST<KeyType>& bst)
{
	stream << bst.inOrder();
	return stream;
}






