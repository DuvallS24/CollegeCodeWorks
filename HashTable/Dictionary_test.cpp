//Dictionary_test.cpp
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#include "Dictionary.h"
#include <cassert>

using namespace std;

void test_constructor()
{
	Dictionary<Test> test1(5);	// constructing Dictionary 
}

void test_insert()
{
	Dictionary<Test> test2(1);
	Test *str1 = new Test;
	str1 -> key = "Je'sus";
	test2.insert(str1);

	Test *str3 = new Test;
	str3 -> key = "The Bible";			// Inserting into a dictionary
	test2.insert(str3);
	
	Test *str4 = new Test;
	str4 -> key = "Hal Jordan";
	test2.insert(str4);	

	assert(test2.toString(0) == "Hal Jordan, The Bible, Je'sus");
}

void test_get()
{

	Dictionary<Test> test3(10);
	Test *str1 = new Test;
	str1 -> key = "Moses";
	test3.insert(str1);

	Test *str3 = new Test;
	str3 -> key = "Isaac";			// Inserting a string into a dictionary
	test3.insert(str3);
	
	Test *str4 = new Test;
	str4 -> key = "Clark Kent";
	test3.insert(str4);	


	Test find;
	find.key = "Clark Kent";
	Test *print = test3.get(find);		// Getting a string from dictionary
	assert(print -> hash(10) == 3); // Asserting the get result

	

}

void test_remove()
{
	Dictionary<Test> test4(1);

	Test *str4 = new Test;
	str4 -> key = "Abel"; 			 // Inserting a string into a dictionary
	test4.insert(str4);
	
	Test *str5 = new Test;
	str5 -> key = "Lillith";		 // Inserting a string into a dictionary
	test4.insert(str5);
	
	Test *str6 = new Test;
	str6 -> key = "Bruce Wayne"; 		// Inserting a string into a dictionary
	test4.insert(str6);

	assert(test4.toString(0) == "Bruce Wayne, Lillith, Abel");

	Test deleteKey;
	deleteKey.key = "Bruce Wayne";	
	test4.remove(deleteKey);	// Removing a string from dictionary 
	deleteKey.key = "Abel";	
	test4.remove(deleteKey);	// Removing a string from dictionary 
	
	assert(test4.toString(0) == "Lillith");
}

void test_empty()
{
	Dictionary<Test> test3(1);

	Test *str1 = new Test;
	str1 -> key = "Ishmael";     // Inserting a string into a dictionary
	test3.insert(str1);
	
	assert(test3.toString(0) != "");

	
}


int main()
{
	test_constructor();
	test_insert();
	test_get();
	test_remove();
	test_empty();

	return 0;
}

