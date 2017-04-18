/*
Matt Iammarino
CS-271
A program that creates a Node
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;



	Node::Node()
	{
		frequency = 0;
		left = NULL;
		right = NULL;
		
	}


	Node::Node(int freq)
	{
		frequency = freq;
		left = NULL;
		right = NULL;
		
	}
	

	Node::Node(char value, int freq)
	{
		frequency = freq;
		character = value;
		left = NULL;
		right = NULL;
	}
	

std::string 	Node::toString() const
{
	
	
	string value = "";
	char val;
	
	ostringstream seq;
	val = character;
	seq<<val;
	value+=seq.str();
	
	
	value+=",";
	ostringstream seq2;
	seq2<<frequency;
	value+=seq2.str();
	
	
	return value;
}


std::ostream& operator<<(std::ostream& stream, const Node& node)
{
	stream<<node.toString()<<endl;
	return stream;
}


bool Node::operator<(const Node& node)
{
	if(frequency < node.frequency)
		return true;
	else
		return false;
}

	
