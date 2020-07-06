/***********************************************
Author: Scott Giorlando
Date: 2/2/17

Purpose: This project is supposed to demonstrate my understanding of class and objects used by a class.
This program takes a users input for points on a graph and rotates one of them 90 degrees as many times as the user sees fit, 
another moves the point as much as the user sees fit aswell. (For testing purposes I set the first point to rotate, the other two to move).

Sources of Help: None
  
Time Spent: 2-3 hours

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

Date: 2/2/17
Name: Scott Giorlando
*/

#include <iostream>
using namespace std;

/* Create the class named Point, with 5 functions, two are "getter" functions that get the variable the user enters and places them in
the x coordinate and y coordinate variables.  The other three functions make the points the user enters,
moves the points the user enters by an amount that they also enter, and rotates the points 90 degrees by however many times the user wishes.
*/
class Point {
public:
	void makeData();
	void movePoint();
	void rotate_90();

	int getXCoord();
	int getYCoord();

private:
	int x_coordinate;
	int y_coordinate;
};

//Main calls the functions created in the class just to test if it works.
int main(int argc, char *argv[])
{
	Point Point1, Point2, Point3;

	cout << "Point 1\n";
	Point1.makeData();
	cout << "\nPoint 2\n";
	Point2.makeData();
	cout << "\nPoint 3\n";
	Point3.makeData();

	Point1.getXCoord();
	Point1.getYCoord();
	Point2.getXCoord();
	Point2.getYCoord();
	Point3.getXCoord();
	Point3.getYCoord();

	cout << "\nPoint 1\n";
	Point1.rotate_90();  //Point 1 is the one that will rotate 90 degrees.
	cout << "\nPoint 2\n";
	Point2.movePoint(); //Point 2 is one of the points that will move a specific amount of spaces.
	cout << "\nPoint 3\n";
	Point3.movePoint(); // Point 3 is the same as Point 2, so it moves as much as the user specifies.


	return 0;
}

void Point::makeData()
{
	cout << "Please enter a X value (must be a number): ";
	cin >> x_coordinate;

	cout << "Please enter a Y value (must be a number): ";
	cin >> y_coordinate;

	cout << "(" << x_coordinate << ", " << y_coordinate << ")" << endl;
}

void Point::movePoint()
{
	int moveXCoord = 0; 
	int moveYCoord = 0;
	int newXCoord = 0;
	int newYCoord = 0;

	cout << "How far up/down (Y) do you want your point to move by? ";
	cin >> moveYCoord;

	if (moveYCoord > 0)
	{
		cout << "\nMoved up by " << moveYCoord << endl;
	}
	else
	{
		cout << "\nMoved down by " << moveYCoord << endl;
 	}

	cout << "How far to the left/right (X) do you want your point to move by? ";
	cin >> moveXCoord;

	if (moveXCoord > 0)
	{
		cout << "\nMoved right by " << moveXCoord << endl;
	}
	else
	{
		cout << "\nMoved left by " << moveXCoord << endl;
	}

	newXCoord = (x_coordinate + moveXCoord);
	newYCoord = (y_coordinate + moveYCoord);

	cout << "(" << newXCoord << ", " << newYCoord << ")" << endl;
}

void Point::rotate_90()
{
	int how_many;
	int newXCoord = x_coordinate;
	int newYCoord = y_coordinate;

	cout << "How many rotations do you want? ";
	cin >> how_many;
	while (how_many > 0)
	{
		if (newXCoord > 0 && newYCoord > 0)
		{
			newXCoord = (y_coordinate);
			newYCoord = (x_coordinate * -1);
		}
		else if(newXCoord > 0 && newYCoord < 0)
		{
			newXCoord = (newYCoord);
			newYCoord = (y_coordinate * -1);
		}
		else if (newXCoord < 0 && newYCoord < 0)
		{
			newXCoord = newYCoord;
			newYCoord = x_coordinate;
		}
		else if (newXCoord < 0 && newYCoord > 0)
		{
			newXCoord = x_coordinate;
			newYCoord = y_coordinate;
		}

		how_many--;
	}

	cout << "(" << newXCoord << ", " << newYCoord << ")" << endl;
}

int Point::getXCoord()
{
	return x_coordinate;
}

int Point::getYCoord()
{
	return y_coordinate;
}