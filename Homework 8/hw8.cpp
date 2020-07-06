/***********************************************
Author: Scott Giorlando
Date: 3/23/17

Purpose: This program is meant to show my understanding of derived classes and also being able to use initializers, the program has one class called Vehicle and another class that is derived from Vehicle known as Truck.
Truck is meant to inherit some of the same functions and objects as Vehicle, but Truck can also have changed functions (overriden) and it should be able to show that it can use these functions.

Sources of Help: Google for the implementation of initializers
 
Time Spent: 3 hours

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

Date: 3/23/17
Name: Scott Giorlando
*/

#include <iostream>
#include <string>

using namespace std;

/*
Class Person: Has three constructors, a default which sets the variable name of type string to "Unknown", 
a constructor that takes a string as an argument and sets the variable name to the value of the argument,
and a copy constructor that takes a Person object as its parameter and sets name to the value of the other objects name.

This class also has a accessor function called getName an overloaded '=' operator and two friend functions for input and output.
This class is meant to take a name that is a string and use it in the other classes as a specific object.
*/
class Person
{
public:
	//Default constructor which sets the variable name of type string to "Unknown"
	Person() :name("Unknown") {};
	//This constructor takes a string as an argument and sets the variable name to the value of the string theName.
	Person(string theName) :name(theName) {};
	//Copy constructor that takes a constant Person object named theObject that is passed by reference as its parameter and sets name to the value of theObject's name.
	Person(const Person& theObject) :name(theObject.getName()) {};
	//Accessor function getName simply returns the value of the variable name, and does not change anything.
	string getName() const
	{
		return name;
	}

	//Overload = operator takes a constant person object named rtSide, which is passed by reference and checks to see if the object being set is already equal to rtSide
	//if it is, then the object being set is returned, otherwise it gets set to the values stored inside rtSide.
	Person& operator=(const Person& rtSide)
	{
		if (this == &rtSide)
		{
			return *this;
		}

		name = rtSide.getName();
		return *this;
	}

	//Overloaded >> operator is a friend function so it has access to the private variable name.  This function takes a istream object that is passed by reference and a Person object that is passed by reference.
	//This function is meant to take an input from the user and store it into a istream object, taking their first and last name on the same line.  Then when the function is called the istream object is stored into a Person object.
	friend istream& operator >> (istream& inStream, Person& personObject);

	//Overloaded << operator is a friend function so it has the access to the private variable name.  This function takes a ostream object that is passed by reference and a constant Person object that is passed by reference.
	//This function is supposed to store the output into an ostream object and when the function gets called it outputs the Person object.
	friend ostream& operator << (ostream& outStream, const Person& pObject);
private:
	string name;
};

/*
Class Vehicle: Has three constructors (six if the commented ones are uncommented), a default which sets the variable manufacterer of type string to "Unknown Manufacterer", it also sets the variable cylinders of type int to value 0, and it sets the variable owner of type Person to "Unknown Owner",
a constructor that takes a string, an int and a Person object as an argument and sets the variable manufacterer to the value of the string argument, cylinders to the int argument and owner to the Person object argument.
and a copy constructor that takes a Vehicle object as its parameter and sets the manufacterer, cylinders, and owner of the new object to the same values as the object being passed.

This class also has accessor functions called getOwner, getCylinder, getManufacterer an overloaded '=' operator and two friend functions for input and output.
This class is meant to take a string, a number and a name that is of type Person, and it is supposed to make a Vehicle object out of them.
*/
class Vehicle
{
public:
	//Default Constructor which sets the variable manufacterer of type string to "Unknown Manufacterer", it also sets the variable cylinders of type int to value 0, and it sets the variable owner of type Person to "Unknown Owner".
	Vehicle() :manufacterer("Unknown Manufacterer"), cylinders(0), owner("Unknown Owner") {};
//	Vehicle(string company) :manufacterer(company){};
//	Vehicle(int cylAmnt) :cylinders(cylAmnt){};
//	Vehicle(Person newOwner) :owner(newOwner) {};
	//Constructor that takes a string as an argument and sets the variable manufacterer to the value of the argument, it also takes a int and Person as arguments and it sets the variables cyldinders to the int argument and owner to the Person argument.
	Vehicle(string company, int cylAmnt, Person newOwner) :manufacterer(company), cylinders(cylAmnt), owner(newOwner) {};
	//Copy constructor that takes a Vehicle object as its parameter and sets the manufacterer, cylinders, and owner of the new object to the same values as the object being passed.
	Vehicle(const Vehicle& vehType) :manufacterer(vehType.getManufacterer()), cylinders(vehType.getCylinder()), owner(vehType.getOwner()) {};

	//Accessor function getOwner returns the value of the variable owner which is of type Person, and does not change anything.
	Person getOwner() const 
	{ 
		return owner; 
	}

	//Accessor function getCylinder returns the value of the variable cylinders, and does not change anything.
	int getCylinder() const
	{
		return cylinders;
	}

	//Accessor function getManufacterer returns the value of the variable manufacterer, and does not change anything.
	string getManufacterer() const
	{
		return manufacterer;
	}

	//Overload = operator takes a constant Vehicke object named vehObj, which is passed by reference and checks to see if the object being set is already equal to vehObj
	//if it is, then the object being set is returned, otherwise it gets set to the values stored inside vehObj (which would be: manufacterer, cylinders, owner).
	Vehicle& operator=(const Vehicle &vehObj)
	{
		if (this == &vehObj)
		{
			return *this;
		}

		manufacterer = vehObj.getManufacterer();
		cylinders = vehObj.getCylinder();
		owner = vehObj.getOwner();

		return *this;
	}
	
	//Overloaded << operator is a friend function so it has the access to the private variables manufacterer, cylinder, owner.  This function takes a ostream object that is passed by reference and a constant Vehicle object that is passed by reference.
	//This function is supposed to store the output into an ostream object and when the function gets called it outputs the Vehicle object.
	friend ostream& operator << (ostream& outStream, const Vehicle& vObject);

protected:
	string manufacterer;
	int cylinders;
	Person owner;
};

/*
Class Truck: Derived from the Vehicle class, so it inherits every function unless it is overriden so it has four constructors (seven if the commented ones are uncommented), a default which sets towCap to 0 and loadCap to 0,
a constructor that takes a string, two ints, a double and a Person object as an argument and sets the variable manufacterer to the value of the string argument, cylinders to one of the int argument and owner to the Person object argument, then it sets towCap to another int value and loadCap to the double value.
and a copy constructor that takes a Truck object as its parameter and sets the manufacterer, cylinders, and owner of the new object to the same values as the object being passed.

This class also has accessor functions called getLoadCap and getTowCap an overloaded '=' operator and two friend functions for input and output.
This class is meant to take a string, three numbers and a name that is of type Person, and it is supposed to make a Vehicle object out of them.
*/
class Truck : public Vehicle 
{
public:
	//Default constructor that sets the values of loadCap and towCap to 0.
	Truck() :loadCap(0), towCap(0) {};
	//Constructor that takes a double as a argument.  It sets loadCap to the value of the argument load.
	Truck(double load) :loadCap(load) {};
	//Constructor that takes an int as a argument.  It sets the value of towCap to the value of the argument tow.
	Truck(int tow) :towCap(tow) {};
	//Overriden Constructor which sets the variable manufacterer of type string to company, it also sets the variable cylinders of type int to cylAmnt, and it sets the variable owner of type Person to newOwner, it sets the variable loadCap to inputLoad and towCap to inputTow.
	Truck(string company, int cylAmnt, Person newOwner, double inputLoad, int inputTow) :loadCap(inputLoad), towCap(inputTow) 
	{
		manufacterer = company; 
		cylinders = cylAmnt;
		owner = newOwner;
	};

	//Accessor function getLoadCap returns the value of the variable loadCap, and does not change anything.
	double getLoadCap() const
	{
		return loadCap;
	}

	//Accessor function getTowCap returns the value of the variable towCap, and does not change anything.
	int getTowCap() const
	{
		return towCap;
	}

	//Overloaded << operator is a friend function so it has the access to the private variables manufacterer, cylinder, owner, loadCap and towCap.  This function takes a ostream object that is passed by reference and a constant Truck object that is passed by reference.
	//This function is supposed to store the output into an ostream object and when the function gets called it outputs the Truck object.
	friend ostream& operator << (ostream& outStream, const Truck& tObject);

private:
	double loadCap;
	int towCap;
};

int main(int argc, char* argv[])
{
	//Initialize Person object P1, P2 which is set to "John Doe" and P3 which is meant to copy the value of P2.
	Person P1, P2("John Doe"), P3(P2);

	cout << "///// Testing Person Class /////" << endl;
	cout << "Testing Default Constructor: " << "The person is: " << P1 << endl;
	cout << "Testing Constructor(string): " << "I am: " << P2 << endl;
	cout << "Testing Copy Constructor: " << "Another me is: " << P3 << endl;
	cout << "Testing >> Overloading: ";
	cin >> P1;
	cout << "\tYou're: " << P1 << endl;
	P2 = P1;
	cout << "Testing = Overload: " << "Another you is: " << P2 << endl;

	//Initialize Vehicle object Veh1, Veh2 which is set to "Chevrolet Car", 6 , Person object P2, and Veh3 which is meant to copy the value of Veh2.
	Vehicle Veh1, Veh2("Chevrolet Car", 6, P2), Veh3(Veh2);
	cout << "\n\n///// Testing Vehicle Class /////" << endl;
	cout << "Testing Default Constructor: " << Veh1 << endl;
	cout << "Testing Constructor(args): " << Veh2 << endl;
	cout << "Testing Copy Constructor: " << Veh3 << endl;
	Veh1 = Veh2;
	cout << "Testing = Overloading: " << "\n\tCar 1: " << Veh1 << "\n\tCar 2: " << Veh2 << endl;

	//Initialize Truck object T1, T2 which is set to "Ford Truck", 8, Person object P3, 250 and 2000 and T3 which is meant to copy the value of T2.
	Truck T1, T2("Ford Truck", 8, P3, 250, 2000), T3(T2);
	cout << "\n\n///// Testing Truck Class /////" << endl;
	cout << "Testing Default Constructor:\n" << T1 << endl;
	cout << "Testing Constructor(args) for a Truck:\n" << T2 << endl;
	cout << "Testing Copy Constructor: Copied Truck:\n" << T3 << endl;
	T1 = T3;
	cout << "Testing = Overloading:\n" << "His truck is: " << T3 << "\nHis same truck is: " << T1 << endl;

	return 0;
}

//Overloaded << operator is a friend function so it has the access to the private variables manufacterer, cylinder, owner.  This function takes a ostream object that is passed by reference and a constant Vehicle object that is passed by reference.
//This function is supposed to store the output into an ostream object and when the function gets called it outputs the Vehicle object.
ostream& operator << (ostream& outStream, const Vehicle& vObject)
{
	outStream << " Manufacterer is: " << vObject.getManufacterer() << ", " << " Cylinders: " << vObject.getCylinder() 
		<< ", " << " belongs to: " << vObject.getOwner();

	return outStream;
}

//Overloaded >> operator is a friend function so it has access to the private variable name.  This function takes a istream object that is passed by reference and a Person object that is passed by reference.
//This function is meant to take an input from the user and store it into a istream object, taking their first and last name on the same line.  Then when the function is called the istream object is stored into a Person object.
istream& operator >> (istream& inStream, Person& personObject)
{
	string fullName;
	cout << "Enter your full name: ";
	getline(inStream, fullName);
	personObject.name = fullName;
	return inStream;
}

//Overloaded << operator is a friend function so it has the access to the private variable name.  This function takes a ostream object that is passed by reference and a constant Person object that is passed by reference.
//This function is supposed to store the output into an ostream object and when the function gets called it outputs the Person object.
ostream& operator << (ostream& outStream, const Person& pObject)
{
	outStream << pObject.name;
	return outStream;
}

//Overloaded << operator is a friend function so it has the access to the private variables manufacterer, cylinder, owner, loadCap and towCap.  This function takes a ostream object that is passed by reference and a constant Truck object that is passed by reference.
//This function is supposed to store the output into an ostream object and when the function gets called it outputs the Truck object.
ostream& operator << (ostream& outStream, const Truck& tObject)
{
	outStream << " Manufacterer is: " << tObject.getManufacterer() << ", " << " Cylinders: " << tObject.getCylinder()
		<< ", " << " belongs to: " << tObject.getOwner() << " Load Capacity: " << tObject.getLoadCap() << ", Towing Capacity: " << tObject.getTowCap();

	return outStream;
}
