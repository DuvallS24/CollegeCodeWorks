//Frequencies.cpp
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main()
{
	ifstream infile;		// File to read from
	ofstream outfile;		// File to output into		
	infile.open("words");	// Filename we are reading from
	outfile.open("frequencies.txt"); 	// Filename to output in
	
	HashTable<Test> dictionary(1000);	// Creating hash table
	
	string line;
	
	while(getline(infile, line))	// Reading line by line
	{
		Test *str = new Test;
		str -> key = line;
		dictionary.insert(str);	// Adding each word in specific line to the dictionary 
	}
	
	infile.close();	// Closing file we are reading from
	
	for(int i = 0; i < dictionary.slots; i++)
	{
		List<Test*> *current1 = &dictionary.table[i];	// List object
		int length = current1 -> length(); // Setting the length of each slot in hashtable
		outfile << length << "\n";	// Outfiling length in order to get the frequency in each slot
	}
	
	outfile.close();	// Closing output file
	
	return 0;
}
