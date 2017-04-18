//Test.h
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#ifndef TEST
#define TEST

#include <iostream>

class Test
{
	public:
	
		string key;

		int hash(int slots) const;  // Hash function 
		std::string toString() const;	// toString method
		bool operator==(const Test& tes) const;		// Overriding equality operator 
};

std::ostream& operator<<(std::ostream& stream, const Test& testt);	// ostream operator 

#endif
