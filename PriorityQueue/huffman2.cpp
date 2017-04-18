
#include <iostream>     
#include <fstream>
#include <sstream>
#include "node.h"
#include "pq.h"
#include <map>
#include <string>

using namespace std;
string theCodes[256];

Node* huffMan(MinPriorityQueue<Node> q, int items)
{
	//creates a tree using the huffman algorithm
	for(int k = 1; k < items; k++)
	{
		//extract the two minimums in the MPQ and then add another node
		//with the frequency being the addition of the two minimums
		//and the left and right nodes being the two extracted minimums
		Node* point = new Node;
		Node* left = q.extractMin();
		Node* right = q.extractMin();
		Node theLeft = *left;
		Node theRight = *right;
		int f1 = theLeft.frequency;
		int f2 = theRight.frequency;
		Node temp = Node(f1+f2);
		temp.left = left;
		temp.right = right;
		*point = temp;
		q.insert(point);
	}
	
	return q.extractMin();
	
}

std::string findStrings(Node* input, string code, int pos)
{
	 Node theRoot = *input;
	 
	//recursively loop through the tree created from the Huffman algorithm
	 
	//if there is a left path, add a 0 to the code
	 
	 if(theRoot.left != NULL)
	 {
	 	 code.insert(pos,"0");
	 	 findStrings(theRoot.left, code, pos+1);
	 }
	 
	 //if there is a right path, add a 1 to the code
	 if(theRoot.right != NULL)
	 {
	 	 code.insert(pos,"1");
	 	 findStrings(theRoot.right,code, pos+1);
	 }
	 
	 
	 //if it is a leaf, then it is a character.. store the code at that
	 //location in the array of codes
	 if(theRoot.left == NULL && theRoot.right == NULL)
	 {
	 	 int index = theRoot.character;
	 	 theCodes[index] = code.substr(0,pos);
	 	 return code;
	 }
	 
	 return "";
}

void writeToFile(char* input, char*output)
{
	
	//write the compressed file to a temporary file that represents the
	//bits as 1's and 0 characters
	ifstream is(input);
	ofstream myfile,myfile2;
	myfile.open("binary.txt");
	
	int count = 0;
	
	for(int k = 0; k < 256; k++)
	{
		if(theCodes[k].length() != 0)
			myfile<<k<<":"<<theCodes[k]<<",";
	}
	myfile<<"\n";
	char c;
	while (is.get(c)) 
	{				
		int x = c;
		myfile << theCodes[x];
		count+=theCodes[x].length();
	}
	
	myfile.close();
	is.close();
	
	//open the compressed file of 1's and 0 characters and write new characters
	//in bits
	ifstream is2("binary.txt");
	myfile2.open (output);
	
	string header;
	getline(is2,header);
	
	//create a header that shows the codes for each letter as well as the
	//number of bits you will want to look through
	
	myfile2<<header;
	myfile2<<"\n";
	myfile2<<count;
	myfile2<<"\n";
	
	char c1;
	while(is2.get(c1))
	{	
		//shift each character so that it is only one bit and or it
		//with 7 others, to make one character bit made up of 8 characters
		//from the previous file
		unsigned char finalByte = c1;
		finalByte = finalByte<<7;
		for(int k = 1; k <8; k++)
		{
			if(is2.get(c1))
			{
				int x2 = c1 - '0';
				x2 = x2<<(8-k-1);
				finalByte = finalByte | x2;
				
			}
		}
		
		myfile2<<char(finalByte);
		
	
	}
		
	
	//close files and delete temporary file
	is2.close();
	myfile2.close();
	remove("binary.txt");
	
	
}

void decompressFile(char* input, char* ouput)
{
	//open up the input file and write to a new file
	ifstream is(input);
	ofstream myfile2;
	myfile2.open (ouput);
	
	map<string,string> codes;
	
	string header;
	getline(is, header);
	int pos = 0;
	
	//loop through the header to figure out the codes for each letter and
	//add it to the map
	while(header.find(",",pos) != -1)
	{
		
		int place = header.find(",",pos);
		
		string t = header.substr(pos,place-pos);
		
		int divider = t.find(":");
		
		string letter = t.substr(0,divider);
		
		string code = t.substr(divider+1);
		
		pos = place +1;
		
		codes[code] = letter;
		
	}
	//find the number of bits you want to look through
	string t;
	getline(is, t);
	int count = atoi(t.c_str());

	//loop through sets of 8 bits(characters) and check if there are any
	//codes that correspond to characters
	string seq = "";
	char c;
	while(is.get(c))
	{
		
		unsigned char buffer = c;
		int temp = c;
		int numBits = 0;
		while(numBits <8 && count>0)
		{
			
			unsigned char bit = buffer>>7;
			buffer = buffer<<1;
			
			int temp = bit;
			
			ostringstream convert;
			
			convert<<temp;
			seq = seq + convert.str();
			
			
			//if the code corresponds to a character, write it to the file
			if(codes.find(seq) != codes.end())
			{
				int ascii = atoi(codes[seq].c_str());
				char character = ascii;
				myfile2<<character;
				seq.clear();
			
			
			}
			//decrement total count and numBits
			count--;
			numBits++;
			
			
			
			
		}
		
		
		
		
	}
		
	//close files
	myfile2.close();
	is.close();
	
}


int main (int argc, char* argv[]) {

	
	
	//make sure there are four arguments, (./a.out, type, file1, file2)
	if(argc == 4)
	{
		
		string type, input, output;
	
		ostringstream seq,seq2,seq3;
		
		seq<<argv[1];
		type = seq.str();
		seq2<<argv[2];
		input = seq2.str();
		seq3<<argv[3];
		output = seq3.str();
		
		
		//check whether or not we want to compress the file or decompress
		if(type == "-c")
		{
			
			 ifstream is(argv[2]);     
		
			  int numItems = 0;
			  int Array[256];
			  
			  for(int k = 0; k < 256; k++)
			  {
				  Array[k]= 0;
			  }
			  
			  char c;
			  while (is.get(c)) 
			  {				
				  int x = c;
				  Array[x] = Array[x] +1;
				  if(Array[x] == 1)
					  numItems++;
			  }
			  
			  is.close();   
			  
			  
			  //create a MPQ that has all of the nodes that contain
			  //characters and frequencies
			 MinPriorityQueue<Node> theQueue = MinPriorityQueue<Node>(numItems);
			  
			  
			  
			  for(int i = 0; i < 256; i++)
			  {
				  if(Array[i] > 0)
				  {
					  char letter = i;
					  Node temp = Node(letter, Array[i]);
					  Node* pointer = new Node;
					  *pointer = temp;
					  theQueue.insert(pointer);
			  
				  }
			  }
			  
			  Node* theRoot = new Node;
			  theRoot = huffMan(theQueue, numItems);
			  //create the huffman Tree of those nodes
			  
			  
			  
			  
			  string code = "";
			  
			  //find the codes for each character
			  findStrings(theRoot, code,0);
			  //compress the file
			  writeToFile(argv[2], argv[3]);
		}
	
		else if(type == "-d")
		{
			//decompress the file
			decompressFile(argv[2],argv[3]);
			
		}
		
	}
	
	
	
		
	  
	 

  return 0;
}
