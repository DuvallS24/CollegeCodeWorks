//Hash_test.cpp
//Sherief Shahin and Steven Duvall
//Project0101
//CS 271: Databases

#include <string>
#include "HashTable.h"
#include <cassert>

using namespace std;

void test_constructor()
{
	HashTable<Test> test(10); // Contructing HashTable 
}

void test_get()
{
	HashTable<Test> test(10);
	
	Test *str1 = new Test;
	str1 -> key = "brewsky"; // Inserting into a HashTable
	test.insert(str1);
	
	Test *str2 = new Test;
	str2 -> key = "Jebediah"; // Inserting into a HashTable
	test.insert(str2);

	Test find;
	find.key = "Jebediah"; 
	Test *print = test.get(find); // Getting a string from HashTable
	assert(print -> hash(10) == 8); // Asserting the get result
}

void test_insert()
{
	HashTable<Test> test(1);

	
	Test *str1 = new Test;
	str1 -> key = "brewsky"; // Inserting into a HashTable
	test.insert(str1);
	
	Test *str2 = new Test;
	str2 -> key = "Jebediah"; // Inserting into a HashTable
	test.insert(str2);
	
	Test *str3 = new Test;
	str3 -> key = "JackAndJill"; // Inserting into a HashTable
	test.insert(str3);
	
	Test *str4 = new Test;
	str4 -> key = "Went"; // Inserting into a HashTable
	test.insert(str4);
	
	Test *str5 = new Test;
	str5 -> key = "Up"; // Inserting into a HashTable
	test.insert(str5);
	
	Test *str6 = new Test;
	str6 -> key = "The"; // Inserting into a HashTable
	test.insert(str6);
	
	Test *str7 = new Test;
	str7 -> key = "Hill"; // Inserting into a HashTable
	test.insert(str7);
	
	Test *str8 = new Test;
	str8 -> key = "QWERTY"; // Inserting into a HashTable
	test.insert(str8);

	assert(test.toString(0) == "QWERTY, Hill, The, Up, Went, JackAndJill, Jebediah, brewsky");
}

void test_remove()
{
	HashTable<Test> test(1);
	Test *str3 = new Test;
	str3 -> key = "Will-I-Am"; // Inserting into a HashTable
	test.insert(str3);
	
	Test *str4 = new Test;
	str4 -> key = "apple"; // Inserting into a HashTable
	test.insert(str4);
	
	Test *str5 = new Test;
	str5 -> key = "nomad"; // Inserting into a HashTable
	test.insert(str5);
		
	Test *str6 = new Test;
	str6 -> key = "The"; // Inserting into a HashTable
	test.insert(str6);
	
	Test *str7 = new Test;
	str7 -> key = "Hill"; // Inserting into a HashTable
	test.insert(str7);
	
	Test *str8 = new Test;
	str8 -> key = "QWERTY"; // Inserting into a HashTable
	test.insert(str8);

	assert(test.toString(0) == "QWERTY, Hill, The, nomad, apple, Will-I-Am");
	
	Test deleteKey;
	deleteKey.key = "QWERTY";
	test.remove(deleteKey); // Removing a string from HashTable
	deleteKey.key = "The";
	test.remove(deleteKey);

	assert(test.toString(0) == "Hill, nomad, apple, Will-I-Am");


	
}
int main()
{
	test_constructor();
	test_get();
	test_insert();	
	test_remove();

	return 0;
}



