/***********************************************
Author: Scott Giorlando
Date: 1/28/17 (Revised on 2/23/17)

Purpose: This program is supposed to show my understanding of pass by reference, it takes the user's input of feet and inches and converts it
to meters and centimeters, with three different functions all using pass by reference for the values that are input.
 
Sources of Help: Google to figure out about setprecision for the 8 decimal places and the iomanip library.
  
Time Spent: 1 hour 30 minutes

***********************************************/

/*
Computing III -­‐-­‐ COMP.2010 Honor Statement

The	practice of	good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy.	 Students are expected to
strictly avoid academic	dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog.	 Violations	will
be dealt with as outlined therein.
   
All programming assignments in this class are to be done by the
student alone.No outside help is permitted except the instructor and	 
approved tutors.
    
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.

Date: 1/28/17 (2/23/17)
Name: Scott Giorlando
*/

#include <iostream>
#include <iomanip>
#include <cmath>

//Function takes two inputs from the user one for feet and one for inches and also uses pass by reference to return the values input to main.
void user_input(int &feet_input, double &inches_input);
/*
Function takes 4 parameters, 2 are pass by reference and two are not, it converts the input of feet and inches
to meters and centimeters then calls the output function to display those values.
*/
void convert_input(int num_of_feet, double num_of_inches, int &meters, double &centimeters);
/*
Function takes 4 parameters, all are pass by reference and it outputs the original values the user entered and outputs the conversion of
those numbers that are input.
*/
void output_conversion(int &feet_entered, double &inches_entered, int &meters_converted, double &centimeters_converted);

//Made one foot a global constant so I could do a conversion for inches.
const double FOOT = 12.0;
//Made METERTOFOOT equal to 0.3048 for the conversion to make feet into meters.
const double METERTOFOOT = 0.3048;
//Made ONEMETERINCM equal to 100 since 100 cm is also known as 1 meter.
const int ONEMETERINCM = 100;

using namespace std;

//
int main(int argc, char *argv[])
{
	//sets the values of these variables to 0, to reset them.
	int feet, meters = 0;
	double inches, centimeters = 0;

	//calls the function for user input.
	user_input(feet, inches);
	//calls the function to convert the values the user input with the user_input function.
	convert_input(feet, inches, meters, centimeters);
	//Calls the output function and uses the converted values above for the desired output.
	output_conversion(feet, inches, meters, centimeters);

	return 0;
}

//user_input takes in two parameters that are pass by reference, an integer for the input of feet and a double input for inches.
void user_input(int &feet_input, double &inches_input)
{
	cout << "Please enter the number of feet: ";
	cin >> feet_input;

	if (feet_input < 0)
	{
		cout << "Please enter the number of feet: ";
		cin >> feet_input;
	}

	cout << "Please enter the number of inches: ";
	cin >> inches_input;

	if (inches_input < 0)
	{
		cout << "Please enter the number of inches: ";
		cin >> inches_input;
	}

	return;
}

//convert_input takes in four parameters, num_of_feet and num_of_inches are pass by value and meters and centimeters are pass by reference.  Then it converts these values.
//num_of_feet is an int that was input and num_of_inches is a double that was input, meters is an int and centimeters is a double.  These are used for conversions.
void convert_input(int num_of_feet, double num_of_inches, int &meters, double &centimeters)
{
	//Converts inches to its feet value by taking the number of inches passed and divides it by one foot or 12 inches.
	double inches_to_feet = (num_of_inches / FOOT);
	//Adds the two values of feet and the converted value of inches together, to have one value.
	double feet_and_inches = (num_of_feet + inches_to_feet);
	//Takes the remainder of feet and inches so it can be converted to centimeters later on.
	double meter_remainder = (feet_and_inches * METERTOFOOT);

	//Converts the value of feet and inches combined as one value into meters.
	meters = (feet_and_inches * METERTOFOOT);
	//Converts the value of the remainder left before into Centimeters by subtracting the value of meters then multiplying by 100.  Since there are 100 centimeters in a meter.
	centimeters = ((meter_remainder - meters) * ONEMETERINCM);
}

//Function takes in 4 parameters two are pass by reference, which are the original values the user input earlier (so they arent changed at all), 
//then the converted values of the numbers that the user input.  The function outputs these values to show the conversions worked (hopefully) in the right way.
//Also uses a precision of 8 decimal places for the output for accuracy.
void output_conversion(int &feet_entered, double &inches_entered, int &meters_converted, double &centimeters_converted)
{
	cout << feet_entered << " feet and " << fixed << setprecision(8) << inches_entered << " inches converts to\n";
	cout << meters_converted << " meters and " << fixed << setprecision(8) << centimeters_converted << " centimeters" << endl;
}