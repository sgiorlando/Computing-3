/***********************************************
Author: Scott Giorlando
Date: 3/16/17

Purpose: This program is supposed to show my understanding of the string library.  This program is supposed to take a file with different words and find the word/ words with the largest amount of consecutive double letters.

Sources of Help: Stack Overflow and cplusplus.com for the fstream library and string library functions.
 
Time Spent: 1 hour

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

Date: 3/16/17
Name: Scott Giorlando
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function findDoubleLetter is a void function and takes no parameters, it is meant to take the file and read it, then output the string inside the file with the most consecutive double letters.
void findDoubleLetter();

int main(int argc, char * argv[])
{
	//Function call for findDoubleLetter.
	findDoubleLetter();
	return 0;
}

//Function findDoubleLetter takes in no arguments and returns nothing.  The function is meant to read from a file and store each word into a string object by using a loop. 
//Once the word is stored it goes through an incrementer to find if it has consecutive double letters, if it does a counter goes up, and it will keep going up if there are more consecutive double letters until the end of the string is hit.
//Then the function takes in another string and checks to see if the new string has more consecutive double letters than the previous string, if it does then it will hold the value of the consecutive double numbers in a variable, until another string is found.
void findDoubleLetter()
{
	int pairs = 0;
	int doubleLetter = 0;
	int copyNum = 0;
	string words, tempWord;
	ifstream fileIn;
	fileIn.open("hw07-words.txt");

	if (!fileIn.is_open()) //Condition to check if the file is not open.
	{
		return;
	}

	while (fileIn >> words)
	{
		for (int i = 0; i < words.length(); i++)
		{
			if (words[i] == words[i+1])
			{
				doubleLetter += 1;
			}
		}

		if (doubleLetter > copyNum)
		{
			copyNum = doubleLetter;
			tempWord = words;
			doubleLetter = 0;
		}
		else if (doubleLetter == copyNum)
		{
			copyNum = doubleLetter;
			tempWord = words; //If this is commented out or deleted, the word thats ouptut is addressee. With 3 consecutive double letters.
			doubleLetter = 0;
		}
		else
		{
			doubleLetter = 0;
		}

	}

	cout << tempWord << " has " << copyNum << " consecutive double letters." << endl;

	fileIn.close();
}