//MovieFile.cpp
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "Movies.cpp"

using namespace std;

int main()
{

	ifstream infile;	// File we are reading from 
	infile.open("Movies.txt");	// Name of file we are reading from 
	ofstream outfile;	// File we are outputting in movie frequencies in each slot
	outfile.open("MovieFrequencies.txt");	// Name of output file 

	Dictionary<Movies> movieTable(1000);	// Creatinf dictionary that holds movie names in slots 
	string line;

	while(getline(infile, line))	// Gets each line 
	{
		Movies *movie = new Movies;
		int count = 0;
		while (line[count] != '\t')
		{
			count ++;
		}
		movie -> title = line.substr(0, count);	// Creates title string from letter 0 up to length of title 
		movie -> cast = line.substr(count + 1);	// Creates the cast string from one letter after the title until the end of the line 
		movieTable.insert(movie);	// Inserting the movie object in the  dictionary 
	}
	infile.close();	// Closes input file 

	for(int i = 0; i < movieTable.slots; i++)
	{
		List<Movies*> *current1 = &movieTable.table[i];	// Creates list object 
		Node<Movies*> *current = current1 -> head;	// Creates node within the list object 
		int length = current1 -> length();	// Gets the length of items in slots, giving us the frequency of items in each slot  
		outfile << length << "\n";	// Outputting frequency 
	}
	outfile.close();	// Closes output class  


	string movieTitle;
	cout << "Enter a movie title: ";	
	getline(cin, movieTitle);	// Prompting user to enter movie title 
	while(true)	// Prompts user until the user types "Quit"
	{
		if(movieTitle == "Quit")
		{
			break;
		}
		else
		{
			Movies find;	// Creating a movie object 
			find.title = movieTitle;	 
			Movies *print = movieTable.get(find); // Find user prompted movie title
			cout << endl << "This is the cast of the movie: "<< movieTitle<<endl <<endl;
			cout << print -> cast << endl;	// Prints cast of the movie
			cout << endl;
			cout << "Enter another movie title you wish to find or type Quit: ";
			getline(cin, movieTitle); // Prompting user to enter another movie title 

		}	

	}
	
	
	return 0;
}






