/***********************************************
Author: Scott Giorlando
Date: 3/26/17

Purpose: This program is supposed to show my understanding of virtual functions.  This program is a guessing game similar to one I did before on another assignment, however this program has a computer player which is a derived class from the regular player class which has virtual functions,
or functions that can be overriden in derived classes.

Sources of Help: Google for the use of srand and ideas for how to work on getPlayrGuess
 
Time Spent: 3.5 hours

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

Date: 3/26/17
Name: Scott Giorlando
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/////////////////////////////////
//Class Player: has two functions that are virtual, getGuess and getPlayerGuess, they both do nothing in this class.  It also has two variables, maximum and minimum
//and they change in value dynamically as the program is being used.
/////////////////////////////////
class Player
{
public:

	//Function getGuess is a virtual function, and it is meant to get the specific player's guess that is input and return it to a variable.  This one however returns nothing.
	virtual int getGuess()
	{
		return 0;
	}

	//Function getPlayerGuess is a void virtual function that takes a string and a int as its parameters, it is meant to take the string and compare it with three other strings to see if it matches these condtions.
	//If it matches specific conditions then the player's guess is stored in either maximum or minimum, changing the original values assinged to those.
	//Here it currently does nothing.
	virtual void getPlayerGuess(string minOrMax, int player_guess) {};

	//Function getMax is a virtual function that returns the value of the highest guess in the range that is possible.
	virtual int getMax()
	{
		return maximum;
	}

	//Function getMin is a virtual function that returns the value of the lowest guess that is possible inside the number range.
	virtual int getMin()
	{
		return minimum;
	}

protected:
	int maximum = 100;
	int minimum = 0;
};

//////////////////////////////////
//Class HumanPlayer: It is derived from the Player class, and it currently holds an overriden version of the virtual function getGuess.  It also holds a private integer variable named HumanGuess.
//////////////////////////////////
class HumanPlayer : public Player
{
public:
	//Function getGuess: This function is overriden from the virtual function in the Parent class.  This function takes the user's input for a number and stores it into a variable inputGuess.
	//inputGuess is then stored into Humanguess and Humanguess is returned.
	int getGuess()
	{
		int inputGuess;
		cout << "Please enter a number: ";
		cin >> inputGuess;
		Humanguess = inputGuess;

		return Humanguess;
	}

private:
	int Humanguess;
};

//////////////////////////////////////
//Class ComputerPlayer: This class is derived from the Player class as well.  This class holds two functions, and overriden getGuess, and an overridden getPlayerGuess.
//This class also holds a private member variable named compGuess.
//////////////////////////////////////
class ComputerPlayer : public Player
{
public:
	//Function getGuess is overriden from the Parent class, this function takes the variable compGuess and assigns it a random value that is in between the variables maximum and minimum that are defined in the Parent class.
	//This function then returns the value of compGuess.
	int getGuess()
	{
		cout << "The computers turn to guess: ";
		compGuess = rand() % ((max + min) + 1);
		return compGuess;
	}

	//Function getplayerGuess takes two arguments, a string and a int.  This function takes the string and compares it with three values "high", "low" or "equal".
	//Once it figures out if the string is equal to one of those three, then it assigns either maximum or minimum to the value that the computer guessed.
	void getPlayerGuess(string minOrMax, int player_guess)
	{
		if (minOrMax == "high") //For example here, if the computers guess is higher than the answer the function will assign the value of player_guess to maximum.
		{
			max = player_guess;
		}
		
		if (minOrMax == "low")
		{
			min = player_guess;
		}
		 
		if (minOrMax == "equal")
		{
			return;
		}
	}

private:
	int compGuess = 0;
	int max = getMax();
	int min = getMin();
};

//Function checkForHighOrLow has two parameters, int guess and int answer.  This function takes guess and compares it to the answer to see if it is higher, lower or equal to the answer.
//It returns a string based on the condtions it is equal to.
string checkForHighOrLow(int guess, int answer);

/////////////////////////////////////
//Global functions given in project
/////////////////////////////////////

bool checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You Win!" << endl;
		return true;
	}
	else if (answer < guess)
	{
		cout << "Your guess is too high." << endl;
	}
	else
	{
		cout << "Your guess is too low." << endl;
	}
	return false;
}

//The play function takes as input two Player objects
void play(Player &player1, Player &player2)
{
	int answer = 0, guess = 0; 
	string highOrLow;
	srand(static_cast <unsigned> (clock())); //generate a true random number
	answer = rand() % 100;
	bool win = false;

	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		highOrLow = checkForHighOrLow(guess, answer);
		cout << endl; //Trying to make it easier to read/play with new lines in between.
		if (win) return;

		player1.getPlayerGuess(highOrLow, guess);
		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
		cout << endl; //Trying to make it easier to read/play with new lines in between.
		player1.getPlayerGuess(highOrLow, guess);
		player2.getPlayerGuess(highOrLow, guess);
	}
}

int main(int argc, char* argv[])
{
	HumanPlayer hPlayer1, hPlayer2;
	ComputerPlayer cPlayer1, cPlayer2;

	play(hPlayer1, hPlayer2);
	cout << endl;
	play(hPlayer1, hPlayer2);
	cout << endl;
	play(hPlayer1, cPlayer1);
	cout << endl;
	play(cPlayer1, cPlayer2);
	cout << endl;
	play(cPlayer1, cPlayer2);

	return 0;
}

//Function checkForHighOrLow has two parameters, int guess and int answer.  This function takes guess and compares it to the answer to see if it is higher, lower or equal to the answer.
//It has a variable hlNum, and hlNum is assigned to "equal" if the guess and answer are equal, it is assigned "high" if guess is greater than answer, and it is assigned "low" if guess is less than answer.
//The string stored into hlNum after it checks the conditions is returned so the computer can change its guesses later on for more educated guesses.
string checkForHighOrLow(int guess, int answer)
{
	string hlNum;

	if (guess < answer)
	{
		hlNum = "low";
	}
	else if (guess > answer)
	{
		hlNum = "high";
	}
	else if(guess == answer)
	{
		hlNum = "equal";
	}
	return hlNum;
}