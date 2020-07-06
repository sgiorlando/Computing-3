/***********************************************
Author: Scott Giorlando
Date: 4/2/17

Purpose: This program is meant to demonstrate my understanding of the vector object and its properties.  I needed to create a dynamically allocating array of strings without using the vector library.
The array emulates a vector and should share the same properties as a vector, it can change it's size and be copied to a larger array.  Elements can also be deleted and the size changes dynamically.

Sources of Help: Cplusplus.com for initialization of the copy constructor, and the deleteEntry function.
 
Time Spent: 4 hours (fixing the deleteEntry function)

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

Date: 4/2/17
Name: Scott Giorlando
*/

#include <iostream>
#include <string>
using namespace std;


/*
Class DynamicStringArray holds 2 constructors and two private member variables an array of strings called dynamicArray and integer called size., a default constructor and a copy constructor.  It also holds a destructor an operator overload on the = sign, an inline function to get the size of the private member variable size.
The class holds three member functions, an add entry a delete entry and a get entry.
*/
class DynamicStringArray
{
public:
	//This is the default constructor and it assigns the dynamicArray to nullptr.  It also assigns the variable size to the value 0.
	DynamicStringArray()
	{
		dynamicArray = nullptr;
		size = 0;
	}

	//Copy constructor takes in a constant DynamicStringArray object to be copied to a new DynamicStringArray object.
	DynamicStringArray(const DynamicStringArray &stringObj);

	//This is the destructor to clear all allocated memory.
	~DynamicStringArray();

	//Operator overload for the assignment operator, it takes in a constant DynamicStringArray object.  It is meant to assign the value of one object to another.
	DynamicStringArray& operator=(const DynamicStringArray &object1);

	//Function get size takes in no arguments and returns the value of size.
	int getSize() const
	{
		return size;
	}

	//Function addEntry takes in a constant string object as its parameter.  It is meant to add the string on to the dynamicArray object.
	void addEntry(const string &inputString);
	//Function deleteEntry takes in a constant string object as its parameter.  It is meant to delete the specific string from the dynamicArray object, returns true when the specific string is found, false if it doesn't exist in the object.
	bool deleteEntry(const string &inputString);
	//Function getEntry takes in a constant integer which is the value of the index the user wants to search.  It takes the number and searches the array for the specific index number, breaks out of the function if the index is out of bounds.  It returns the string at the specific index value.
	string getEntry(const int inputIndex);

private:
	string* dynamicArray; //Private variable dynamicArray is an array of strings.
	int size = 1; //Private variable size has the assigned value of 1.

};

int main(int argc, char* argv[])
{
	DynamicStringArray string1, string2; //Creates the objects string1 and string2 with the default values of nullptr and size of 0.

	cout << "String 1 Size: " << string1.getSize() << endl; //Expect the value of 0.

	string1.addEntry("Hello"); //Adds the entry "Hello" to string1.

	cout << "String 1 Entry at element 0 : " << string1.getEntry(0) << endl; //Expect the output of "Hello".

	string1.addEntry("World!"); //Adds the entry "World!" to string1.

	cout << "String 1 Size: " << string1.getSize() << endl; //Expect a size of 2.
	cout << "String 1 Entry at element 1: " << string1.getEntry(1) << endl; //Expected a reutrn of "World!".
	cout << "String1 Entry at element -1 : " << string1.getEntry(-1);

	string2 = string1; //Assigns the value of string1 to string2.
	cout << "String 2 Size: " << string2.getSize() << endl; //Size should be 2 after this.

	string2.deleteEntry("World!"); //Deletes the entry of "World!" in string2.
	cout << "String 2 Size: " << string2.getSize() << endl; //Size should be 1 after this.

	DynamicStringArray string3(string1), string4; //Copies the value of string1 to string3, and creates a new object string4.

	cout << "String 3 Size: " << string3.getSize() << endl; //String3 should have the size of 2.
	cout << "String 3 at element 0: " << string3.getEntry(0) << endl; //String3 should return "Hello".
	cout << "String 3 at element 1: " << string3.getEntry(1) << endl; //String3 should return "World!".

	string4 = string3; //Assigns the value stored in string3 into string4.

	string4.addEntry("Hello"); //Adds the entry "Hello" to string4.
	string4.addEntry("Hello!"); //Adds the entry "Hello!" to string4.

	string4.deleteEntry("Hello");
	string4.deleteEntry("Hello!");

	cout << "String 4 at entry 0: " << string4.getEntry(0) << endl;
	cout << "String 4 at entry 1: " << string4.getEntry(1) << endl;

	cout << "String 4 Size: " << string4.getSize() << endl; //Expected a returned size of 2.

	return 0;
}

//Function addEntry takes in a constant string as its parameter.  It takes the old object and creates a new one with the size being one larger than the old size.  Then it takes the string and adds it on to the new object and deletes the old object.  Then it assigns the old object to the value of the new object.
void DynamicStringArray::addEntry(const string &inputString)
{
	int newSize = size + 1;
	string *newDynamicArray = new string[newSize];
	for (int i = 0; i < size; i++)
	{
		newDynamicArray[i] = dynamicArray[i];
	}

	newDynamicArray[size] = inputString;
	
	delete[] dynamicArray;
	size += 1;
	dynamicArray = newDynamicArray;
}

//Function deleteEntry takes in a constant string as its parameter.  It takes the old object and creates a new one with the size being one smaller than the old size.  Then it takes the string and searches for it on the dynamic array.  If it finds it then it deletes it from the object.  It returns true if the string is found, false if not.
bool DynamicStringArray::deleteEntry(const string &inputString)
{	
	int j = 0;
	string *newDynamicArray = new string[(size-1)];

	if (size == 0)
	{
		return false;
	}

	for(int i = 0; i < size; i++)
	{
		if (dynamicArray[i] == inputString)
		{
			j = i;
		}
	}
	
	for (int i = 0; i < j; i++)
	{
		newDynamicArray[i] = dynamicArray[i];
	}

	while (j < (size-1))
	{
		newDynamicArray[j] = dynamicArray[j + 1];
		j++;
	}

	size = size - 1;
	delete[] dynamicArray;
	dynamicArray = newDynamicArray;

	return true;
}

//Function getEntry takes in a constant integer as its parameter.  It takes the integer and searches through the specific object and uses the integer as the index it is looking for.  It returns the string at the specified index, if that index is in the boundaries of the array.
string DynamicStringArray::getEntry(const int inputIndex)
{
	if (inputIndex > size || inputIndex < 0)
	{
		cout << "Point is out of bounds." << endl;
		return "";
	}
	else
	{
		return dynamicArray[inputIndex];
	}
}

//Copy constructor takes in a constant of the object being passed in.  The object is passed by reference so it cannot have its values be changed.  This constructor is meant to take an object in and copy its value to a brand new object.
DynamicStringArray::DynamicStringArray(const DynamicStringArray &stringObj)
{
	size = stringObj.getSize();
	dynamicArray = new string[size];
	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = stringObj.dynamicArray[i];
	}

}

//Destructor takes in no parameters and is executed when an object is out of scope.  It is meant to delete an object and set its value to nullptr to have no memory leaks.
DynamicStringArray::~DynamicStringArray()
{
	cout << "Inside Destructor." << endl;
	delete[] dynamicArray;
	dynamicArray = nullptr;
	cout << "Destructor done." << endl;
}

//Overloaded = operator function takes in a constant DynamicStringArray object that is passed by reference.  It is very similar to the copy constructor where it takes the object and assigns its size and values to another object.  It does not change the original values of the object.
DynamicStringArray&  DynamicStringArray::operator=(const DynamicStringArray &object1)
{
	if (this == &object1)
	{
		return *this;
	}

	delete[] dynamicArray;
	size = object1.getSize();
	dynamicArray = new string[size];
	for (int i = 0; i < size; i++)
	{
		dynamicArray[i] = object1.dynamicArray[i];
	}

	return *this;
}