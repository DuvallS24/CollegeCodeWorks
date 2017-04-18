//Movies.h
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#ifndef MOVIES
#define MOVIES

#include "Dictionary.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
class Movies
{
	public:
	

		string title;	// string of movie titles
		string cast;	// string of cast members 
		
		int hash(int slots) const;	// Hash function method 
		bool operator==(const Movies& mov) const;	// Overriding equality operator 
		std::string toString() const;	// toString method
	
		
};

std::ostream& operator<<(std::ostream& stream, const Movies& movie);	// ostream operator 

#endif


