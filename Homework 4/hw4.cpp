/***********************************************
Author: Scott Giorlando
Date: 2/9/17 (Revised on 2/24/17)

Purpose: This program should demonstrate my understanding of class, and constructor functions inside a class. 
This program takes Zip Codes and changes it to its POSTNET counterpart, 
and same the otherway taking a POSTNET or barcode number and converting it to its Zip Code counterpart.

Sources of Help: Mostly Google and Stack Overflow for use of the sstream library and the stoi function.
 
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

Date: 2/9/17  (Revised on 2/24/17)
Name: Scott Giorlando
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

class ZipCode 
{
public:
	//Function takes the barcode as an argument and converts it to Zipcode.
	ZipCode(string zip_bar)
	{
		int bar_conv;
		bar_conv = convertToZipCode(zip_bar);
		z_code = bar_conv;
	}

	//Function takes the zipcode as an argument and sets the private variable equal to the number being passed into the function.
	ZipCode(int zip_num)
	{
		z_code = zip_num;
	}

	//Getter function returns the value of the zip code stored in the private variable.
	int getZipCode()
	{
		return z_code;
	}

	//Getter function takes the stored zip code and converts it to a bar code format and returns that value.
	string getBarCode()
	{
		string z_bar_code;
		z_bar_code = convertToBar(z_code);
		return z_bar_code;
	}

private:
	//The zip code value that will be stored and used for objects.
	int z_code;

	//Function converts the zipcode to the corresponding barcode value.
	string convertToBar(int zip_num)
	{
		string zip_code;
		//Converts the int value to a string.
		zip_code = to_string(zip_num);

		while (zip_code.length() != 5)
		{
			zip_code.push_back('0');
		} 

		//Makes a string stream of the converted numbers for the output.
		stringstream b_code;
		
		//Adds on each converted number to the leading and ending 1 and 0.
		b_code << "1";
		b_code << convNumtoPNET(zip_code[0]);
		b_code << convNumtoPNET(zip_code[1]);
		b_code << convNumtoPNET(zip_code[2]);
		b_code << convNumtoPNET(zip_code[3]);
		b_code << convNumtoPNET(zip_code[4]);
		b_code << "1";

		//returns the string stream in string format.
		return b_code.str();
	}

	//Function converts a string to zipcode, only takes in strings of length 27, but takes off the leading and ending 1's, breaks the string into 5 segments of 5.
	//So it starts at 1 instead of 0, and ends at 25 instead of 27.
	int convertToZipCode(string zip_bar)
	{
		string b_code, b_code_to_zip;
		stringstream addNum;
		b_code = zip_bar;

		if (b_code.length() == 27)
		{
			int z_code1, z_code2, z_code3, z_code4, z_code5;
			
			z_code1 = convPNETtoNum(b_code.substr(1, 5));
			z_code2 = convPNETtoNum(b_code.substr(6, 5));
			z_code3 = convPNETtoNum(b_code.substr(11, 5));
			z_code4 = convPNETtoNum(b_code.substr(16, 5));
			z_code5 = convPNETtoNum(b_code.substr(21, 5));

			//A stream of the int values that each bar gives.  So it should be a number like "91078".
			addNum << z_code1;
			addNum << z_code2;
			addNum << z_code3;
			addNum << z_code4;
			addNum << z_code5;

			//Converts the string stream back to a string so it can be converted to an int for the return value.
			b_code_to_zip = addNum.str();

			//returns the string to int value of the barcode.  Making it a zip code number.
			return stoi(b_code_to_zip);
		}
		else
		{
			cout << "The barcode has an incorrect length" << endl;
			return -1;
		}
	}

	//Function converts a POSTNET number to a zipcode.  It takes a string of 1's and 0's that are broken into segments of 5 as the argument, returns an int corresponding to the string value.
	int convPNETtoNum(string PNET)
	{
		if (PNET == "11000")
		{
			return 0;
		}
		else if (PNET == "00011")
		{
			return 1;
		}
		else if (PNET == "00101")
		{
			return 2;
		}
		else if (PNET == "00110")
		{
			return 3;
		}
		else if (PNET == "01001")
		{
			return 4;
		}
		else if (PNET == "01010")
		{
			return 5;
		}
		else if (PNET == "01100")
		{
			return 6;
		}
		else if (PNET == "10001")
		{
			return 7;
		}
		else if (PNET == "10010")
		{
			return 8;
		}
		else if (PNET == "10100")
		{
			return 9;
		}
		else
		{
			cout << "A barcode can only contain a \"0\" or a \"1\"." << endl;
			return -1;
		}
	}

	//Function converts the zipcode to a POSTNET number, it takes the single characters of the zip code as an argument and returns the string as a whole.
	//Casts the character value of the zip code for example the character '9' would be casted as an int and compared in the function.  
	//'9' returns the string "10100".  The equation in this function Zip_Code = (x - '0') takes the character at x and changes it to the int value.
	string convNumtoPNET(char x)
	{
		int Zip_Code;
		Zip_Code = (x - '0');
		if (Zip_Code == 0)
		{
			return "11000";
		}
		else if (Zip_Code == 1)
		{
			return "00011";
		}
		else if (Zip_Code == 2)
		{
			return "00101";
		}
		else if (Zip_Code == 3)
		{
			return "00110";
		}
		else if (Zip_Code == 4)
		{
			return "01001";
		}
		else if (Zip_Code == 5)
		{
			return "01010";
		}
		else if (Zip_Code == 6)
		{
			return "01100";
		}
		else if(Zip_Code == 7)
		{
			return "10001";
		}
		else if(Zip_Code == 8)
		{
			return "10010";
		}
		else if (Zip_Code == 9)
		{
			return "10100";
		}
		else if (Zip_Code == -1)
		{
			cout << "\nDid not convert to POSTNET correctly" << endl;
			return "00000";
		}
		else
		{
			cout << "\nDid not convert to POSTNET correctly" << endl;
			return "00000";
		}
	}
};

int main(int argc, char *argv[])
{

	ZipCode zip(99504), zip2("100101010011100001100110001"), zip3(12345), zip4(67890);
	cout << zip.getZipCode() << "'s bar code is '" << zip.getBarCode() << "'" << endl;     
	cout << zip2.getZipCode() << "'s bar code is '" << zip2.getBarCode() << "'" << endl;     
	cout << zip3.getZipCode() << "'s bar code is '" << zip3.getBarCode() << "'" << endl;     
	cout << zip4.getZipCode() << "'s bar code is '" << zip4.getBarCode() << "'" << endl;          
	cout << endl;          

	// Test a range of values by first constructing a zip code     
	// with an integer, then retrieving the bar code and using     
	// that to construct another ZipCode.     
	
	int zip_int = 0; 
	
	for (int i = 0; i < 25; i++) 
	{         
		
		// Make an aribrary 5-digit zip code integer, and use it         
		// to construct a ZipCode         
		int five_digit_zip = ((zip_int * zip_int) % 100000);         
		ZipCode z1(five_digit_zip);      

		// Construct a second ZipCode from the first's bar code        
		string z1_barcode = z1.getBarCode();         
		ZipCode z2(z1_barcode);             

		cout.width(3);         
		cout << (i + 1) << ": ";         
		cout.width(5);         
		cout << z2.getZipCode() << " has code '"  << z1_barcode << "'";   

		if ((z1_barcode == z2.getBarCode()) && (z1.getZipCode() == z2.getZipCode()) && (z2.getZipCode() == five_digit_zip))         
		{             
			cout << " [OK]" << endl;         
		}         
		else        
		{             
			cout << " [ERR]" << endl;         
		}                  

		// Increment the test value arbitrarily         
		zip_int += (233 + zip_int % 7);     
	}

	cout << endl; 

	// Test some error conditions. This test assumes that     
	// ZipCode will simply set its value to a flag that indicates     
	// an error, and will not exit the program.

	int BAD_ZIP_COUNT = 2;     
	string bad_zips[][2] = 
	{         
		{ "100101010011100001100110000", "bad start/end character" },         
		{ "100101010011100001100110021", "bad digit" },     
	};  

	for (int i = 0; i < BAD_ZIP_COUNT; i++)
	{         
		cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;   
		ZipCode test(bad_zips[i][0]); 
		cout << endl;     
	}

			cout << "Enter a character to quit." << endl;     
			char c;    
			cin >> c;


	return 0;
}