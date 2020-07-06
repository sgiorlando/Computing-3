/***********************************************
Author: Scott Giorlando
Date: 4/17/17

Purpose: The purpose of this program is to show my understanding of the STL containers and iterators.  This program takes a user's input of strings and outputs all the possible permutations for that order of strings.  It also takes out duplicate entries so the permutation isn't messed up.
This program takes the user's input and places it into a linked list and uses iterators to go through, store and output the strings with all possible permutations.

Sources of Help: http://www.cplusplus.com/reference/algorithm/, http://www.cplusplus.com/reference/list/, http://www.cplusplus.com/reference/sstream/
 
Time Spent: 2 hours

 ***********************************************/

/*
Computing III -­‐-­‐ COMP.2010 Honor Statement

The	practice of	good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy.	 Students are expected to
strictly avoid academic	dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog.  Violations will
be dealt with as outlined therein.
  
All programming assignments in this class are to be done by the
student alone.No outside help is permitted except the instructor and	 
approved tutors.
   
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 4/17/17
Name: Scott Giorlando
*/

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>
using namespace std;

//Function generate_permutations is a function that creates a permutation of strings that are input into a linked list.  This function takes a list of strings as its parameter and looks for a list of strings to be returned.
list<string> generate_permutations(list<string> &input);
//Function print_permutations is a function that prints the list of strings that hold the permutations in them.  This is a void function and it has one parameter which is a linked list of strings.
void print_permutations(list<string> strPermutation, int count);

//Did not change any code from the main function that was given in the homework specification.
int main(int argc, char *argv[]) 
{
	int str_count = 0;
	list<string> inputList;     
	string aLine, aString; 
	// read in strings from stdin     
	cout << "Enter strings, separated by a space:";     
	getline(cin, aLine); //read a line from keyboard     
	istringstream iss(aLine); //use
	
	//parse each string

	while (iss >> aString)
	{ 
		inputList.push_back(aString); 
	}

	auto permutations = generate_permutations(inputList); // print permutations to stdout    
	str_count = inputList.size();
	print_permutations(permutations, str_count);          

	return 0; 
}

//Function generate_permutations is a function that creates a permutation of strings that are input into a linked list.  This function takes a list of strings as its parameter and looks for a list of strings to be returned.
//This function uses many functions that are held inside the list library, such as the sort and unique functions.  First I sort the list and use unique to check and see if there are any duplicate strings, the unique function deletes any duplicate corresponding strings.  Since it is sorted they will be corresponding to each other if they do exist.
//Once that check is done I use the next_permutation function inside a do while loop to get all the permutations, I also store the strings inside a list named newList, and use an iterator and the push back function to store the specific strings for the permutation.
list<string> generate_permutations(list<string> &input)
{
	list<string> newList;

	input.sort(); //sorts the list into a specific order with the highest value in front, for example a list c, b, a would be sorted to be a,b,c.  This is to put duplicates next to each other to be deleted.
	input.unique(); //Checks for duplicate inputs, automatically deletes one of them if there is a duplicate.

	do
	{
		for (list<string>::iterator i = input.begin(); i != input.end(); ++i)
		{
			newList.push_back(*i); //Pushes the specific permutation of strings into a new linked list, and will do so until all the varieties of permutations are in the list.
		}

	} while (next_permutation(input.begin(), input.end()));

	return newList;
}

//Function print_permutations is a function that prints the list of strings that hold the permutations in them.  This is a void function and it has one parameter which is a linked list of strings.
//This function uses an iterator to print out the specific strings held inside the linked list.
void print_permutations(list<string> strPermutation, int count)
{
	list<string>::iterator i = strPermutation.begin();
	cout << "Permutations are:" << endl;
	int x = 1;

	while (i != strPermutation.end())
	{
		cout << x << ". ";
		for (int j = 0; j < count; j++)
		{
			cout << *i << " "; //i is the iterator that prints out the specific string held inside the list.
			i++;
		}
		x++;
		cout << endl;
	}
}
