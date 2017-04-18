// node.h
// a node

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>



class Node
{
   public:
   	   char character;
   	   int frequency;
   	   Node* left;
   	   Node* right;
   	   
   	   Node();
   	   Node(int freq);
   	   Node(char value, int freq);
   	   
   	   std::string toString() const;
   	   bool operator<(const Node& node);
   	   
};


std::ostream& operator<<(std::ostream& stream, const Node& node);
   	   
#include "node.cpp"

#endif	
