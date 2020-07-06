/***********************************************
Author: Scott Giorlando
Date: 2/18/27 - 2/23/17

Purpose: This program is supposed to demonstrate my understanding of operator overloading, it is supposed to take two integers in as fractions and do multiple
math operations on them some include adding, subtracting, multiplying, dividing, also to check if they are equal or not.

Sources of Help: The internet for the Eculidean's Algortihm.  Also looked around on operator overloading, more specifically the == and division.
 
Time Spent: 4 hours

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

Date: 2/23/17
Name: Scott Giorlando
*/

#include <iostream>

using namespace std;

//Class Rational has 5 functions in it's public and two in its private, with 3 private variables.
class Rational 
{
public:
	//The default constructor sets the numerator to 0 and the denominator to 1, to set the variables in case there is actually no input.
	Rational()
	{
		numerator  = 0;
		denominator = 1;
	}

	//Constructor has a single parameter, for whole numbers that could be entered.  It automatically sets the numerator as the single whole value and sets the denominator to 1.
	void wholeRationalNum(int wholeNumber)
	{
		numerator = wholeNumber;
		denominator = 1;
	}

	/*
	This constructor sets the rational number with the values the user enters.  It takes in the input for the numerator and input for the denominator.
	It assigns the numerator and denominator variables that are private to the value the user has input, it then calls the normalize function with the private
	variables to make sure they are set the wasy they are supposed to be.
	*/
	void setRationalNum(int input_num, int input_denom)
	{
		numerator = input_num;
		denominator = input_denom;

		normalize_num(numerator, denominator);
	}

	//This function has no parameters and simply returns the value of the numerator, if it is needed for a specific function.
	int getNumerator() const
	{
		return numerator;
	}

	//This function has no parameters and simply returns the value of the denominator, if it is needed for a specific function.
	int getDenominator() const
	{
		return denominator;
	}

private:

	/*
	Function is meant to normalize the number entered by the user, whether it has a negative in the denominator or it has two negatives in it.
	It also reduces the fraction with the GCD if the fraction can actually be reduced to a lower value.
	This function takes in the numerator and denominator as it's parameters, and they are pass by reference so the values can change as it executes.
	*/
	void normalize_num(int &numerator, int &denominator)
	{
		if (denominator < 0)
		{
			numerator = (numerator * -1);
			denominator = (denominator * -1);
		}
		else if (numerator < 0 && denominator < 0)
		{
			numerator *= -1;
			denominator *= -1;
		}
		else if (numerator == denominator)
		{
			numerator = 1;
			denominator = 1;
		}
		
		if (numerator < 0)
		{
			numerator *= -1;
			gcd = commonDenom(numerator, denominator);
			numerator *= -1;
		}
		else
		{
			gcd = commonDenom(numerator, denominator);
		}

		if (gcd != 0)
		{
			numerator = numerator / gcd;
			denominator = denominator / gcd;
		}
	}

	//Fucntion is meant to find the common denominator for the numerator and denominator entered by the user.  It follows the Eculidean Algorithm.  
	//It takes in the numerator and denominator and returns the greatest common denominator value in an int called gcd.
	int commonDenom(int numerator, int denominator)
	{
		int temp;

		if (numerator < denominator)
		{
			temp = numerator;
			numerator = denominator;
			denominator = temp;
		}

		while (denominator > 0)
		{
			int num3 = (numerator % denominator);
			numerator = denominator;
			denominator = num3;
		}

		return numerator;
	}

	int numerator;
	int denominator;
	int gcd;
};

//Function is an overload for the + operator so it can add the two Rational objects together, it takes two constant objects under the Rational class and returns a new Rational object.
const Rational operator+(const Rational& num1, const Rational& num2);
//Function is an overload for the - operator so it can subtract the two Rational objects, it takes two constant objects under the Rational class and returns a new Rational object.
const Rational operator-(const Rational& num1, const Rational& num2);
//Function is an overload for the * operator so it can multiply the two Rational objects together, it takes two constant objects under the Rational class and returns a new Rational object.
const Rational operator*(const Rational& num1, const Rational& num2);
//Function is an overload for the / operator so it can divide the two Rational objects, it takes two constant objects under the Rational class and returns a new Rational object.
const Rational operator/(const Rational& num1, const Rational& num2);
//Function is an overload for the == operator so it can compare the two Rational objects to see if they are equal in value, it takes two constant objects under the Rational class and returns either true or false.
const bool operator==(const Rational& num1, const Rational& num2);
//Function is an overload for the << operator so it can output a Rational object, it takes in a ostream object and a constant Rational object, it does not look to change the object just output it.  It takes an ostream object as it's return value.
ostream& operator<<(ostream& outStream, const Rational& num);
//Function is an overlaod for the  >> operator so it can take a user's input for the Rational object.  It takes in a istream object and a Rational object.  It returns an istream object with all the values the user input for the Rational object.
istream& operator>>(istream& inStream, Rational& num);

int main(int argc, char *argv[])
{
	//Declare the 3 objects under Rational class. Sets num to the default constructor (should output 0/1).
	Rational num, num1, num2, num3;
	//Sets num1 to the wholeNumber constructor.  Should output the value 3/1.
	num1.wholeRationalNum(3);

	cin >> num2; // I tired 1/2, 15/5, -4/-8 as some inputs.
	cin >> num3;

	//Compares num2 and num3's values together and outputs if they are equal or not.
	if (num2 == num3)
	{
		cout << "These fractions are equal." << endl;
	}
	else
	{
		cout << "These fractions are not equal." << endl;
	}

	cout << "num: " << num << endl; //Should expect 0/1.
	cout << "num1: " << num1 << endl; // Should expect 3/1.
	cout << "num2: " << num2 << endl; // When I tried 1/2, 15/5, -4/-8 I got 1/2, 3/1, and 1/2 as output.
	cout << "num3: " << num3 << endl;

	// Declares the object num4 and sets it equal to num2 + num3.
	Rational num4 = num2 + num3;

	cout << "num4 = num2 + num3: " << num4 << endl;

	num4 = num2 - num3;

	//For this output if you subtract the same number by itself it comes out as 0/1, since I set the program to not allow 0 as a denominator.
	cout << "num4 = num2 - num3: " << num4 << endl;

	num4 = num2 * num3;

	cout << "num4 = num2 * num3: " << num4 << endl;

	num4 = num2 / num3;

	cout << "num4 = num2 / num3: " << num4 << endl;

	return 0;
}

/*
This function is constant because it shouldn't change the original values being placed in.  It takes two constant objects under the Rational class and gets
their numerator and denominator values and stores it into 4 different variables, then does the conversion for addition of fractions.  Returns the total value of them added up.
*/
const Rational operator+(const Rational& num1, const Rational& num2)
{
	Rational totalNum;
	int a, b, c, d, tempNum, tempDenom;

	a = num1.getNumerator();
	b = num1.getDenominator();
	c = num2.getNumerator();
	d = num2.getDenominator();

	tempNum = (a*d) + (b*c);
	tempDenom = b*d;

	totalNum.setRationalNum(tempNum, tempDenom);
	return totalNum;
}

/*
This function is also constant because it shouldn't change the original values being placed in.  It takes two constant objects under the Rational class and gets
their numerator and denominator values and stores it into 4 different variables, then does the conversion for subtraction of fractions.  Returns the total value of them subtracted from each other.
*/
const Rational operator-(const Rational& num1, const Rational& num2)
{
	Rational totalNum;
	int a, b, c, d, tempNum, tempDenom;

	a = num1.getNumerator();
	b = num1.getDenominator();
	c = num2.getNumerator();
	d = num2.getDenominator();

	tempNum = (a*d) - (b*c);
	tempDenom = b*d;

	totalNum.setRationalNum(tempNum, tempDenom);
	return totalNum;
}

/*
This function is also constant because it shouldn't change the original values being placed in.  It takes two constant objects under the Rational class and gets
their numerator and denominator values and stores it into 4 different variables, then does the conversion for multiplication of fractions.  Returns the total value of them multiplied from each other.
*/
const Rational operator*(const Rational& num1, const Rational& num2)
{
	Rational totalNum;
	int a, b, c, d, tempNum, tempDenom;

	a = num1.getNumerator();
	b = num1.getDenominator();
	c = num2.getNumerator();
	d = num2.getDenominator();

	tempNum = (a*c);
	tempDenom = (b*d);

	totalNum.setRationalNum(tempNum, tempDenom);
	return totalNum;
}

/*
This function is also constant because it shouldn't change the original values being placed in.  It takes two constant objects under the Rational class and gets
their numerator and denominator values and stores it into 4 different variables, then does the conversion for divison of fractions.  Returns the total value of them divided from each other.
*/
const Rational operator/(const Rational& num1, const Rational& num2)
{
	Rational totalNum;
	int a, b, c, d, tempNum, tempDenom;

	a = num1.getNumerator();
	b = num1.getDenominator();
	c = num2.getNumerator();
	d = num2.getDenominator();

	tempNum = (a*d);
	tempDenom = (b*c);

	totalNum.setRationalNum(tempNum, tempDenom);
	return totalNum;
}

/*
This function is also constant because it shouldn't change the original values being placed in.  It takes two constant objects under the Rational class and gets
their numerator and denominator values and stores it into 4 different variables, then it checks to see if the numerator multiplied by the denominator of both fractions give the same result.
It returns true if yes, false if not.
*/
const bool operator==(const Rational& num1, const Rational& num2)
{
	int a, b, c, d;
	a = num1.getNumerator();
	b = num1.getDenominator();
	c = num2.getNumerator();
	d = num2.getDenominator();

	if ((a*b) == (c*d))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
This function is an overload for the output of the Rational objects.  It takes an ostream object as one of the parameters and a constant of the object being passed as the other.
This function is not meant to change the object being passed in so it is constant.  This function simply takes the object and displays it's numerator and denominator once called.
It returns the ostream object, so the output can be used.
*/
ostream& operator<<(ostream& outStream, const Rational& num)
{
	outStream << num.getNumerator() << "/" << num.getDenominator();
	return outStream;
}

/* 
This function is an overload for the input of the Rational objects.  It takes an istream object as one of the parameters and a constant of the object being passed as the other.
This function is meant to change the object being passed in so it is not a constant.  This function simply takes the user's input and places it inside one of the int variables.
The istream object takes the int either the numerator or denominator for the user, depending on which one they enter first/last.  It also takes a '/' character in between the input.
Returns the istream object so the user can have their numerator and denominator values.
*/
istream& operator >> (istream& inStream, Rational& num)
{
	int input_num, input_denom;
	char slashSign;
	cout << "Please enter a fraction with a '/' in between. ";
	inStream >> input_num >> slashSign >> input_denom;

	if (slashSign != '/')
	{
		cout << "Error, did not get a '/' from your input, please try again. ";
		inStream >> input_num >> slashSign >> input_denom;
	}
	else if (input_denom == 0)
	{
		cout << "Error, you cannot have a denominator equal to 0.  Try again. ";
			inStream >> input_num >> slashSign >> input_denom;
	}

	num.setRationalNum(input_num, input_denom);
	return inStream;
}