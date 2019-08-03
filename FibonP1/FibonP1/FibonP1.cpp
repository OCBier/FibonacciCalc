/** FibonP1.cpp
 *
 *  Program recursively calculates the Fibonacci number Fn, where n is an integer >= 0.
 *  Also calculates and outputs the time required to perform the calculation.
 *
 *  Author: Oloff Biermann
 *  IDE: Microsoft Visual Studio 2017
 *  Compiler: Microsoft Visual C++ 14.16.27012.6
 *  OS: Microsoft Windows 10 version 1903
 *  Hardware: Alienware 15 R4 Intel i7 8750h (4.1 GHz) CPU with 16GB memory
 *
 *
 **/

#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>
#include <regex>
#include <inttypes.h>

using namespace std;


/**
*  Recursively calculates the Fibonacci number Fn, where n = i for the first call of fibon1().
*  Calculation is done using n1 as the first term and n2 as the second term. Therefore, n1 is Fj-2 and
*  n2 is Fj-1 for term j in the Fibonacci sequence.
*
**/
uint64_t fibon1(uint64_t n1, uint64_t n2, int64_t i)
{
	if (i < 2)
	{
		return i;
	}

	/*Base case for recursion when there are 2 items in the sequence before Fi.*/
	if (i == 2)
	{
		return n1 + n2;
	}

	return fibon1(n2, n1 + n2, i - 1);                                         //Recursively call fibon1 to calcualte next number in sequence.
}


/*Returns positive */
int64_t getFibInput()
{
	cout << "Enter a positive integer n or negative integer to exit: " << endl;
	string input;
	regex pattern("-?\\d+");                                                    //Matches positive or negative integer input.

	cin >> input;                                                              //Attempt to read numeric input as a string


	/*While input is not a valid integer, attempt to get valid input */
	while (!(regex_match(input, pattern)))
	{
		cout << "Invalid input. Please enter an integer >= 0 or a negative integer to exit:" << endl;
		cin >> input;
	}

	return stol(input);                                                      //Return input string converted to integer.


}



int main()
{
	cout << "This program will calculate the Fibonacci number Fn." << endl;
	int64_t userInput = getFibInput();

	while (userInput >= 0)
	{
		uint64_t fibN = fibon1(0, 1, userInput);                                          //Calculate the Fibonacci number using fibon1().
		cout << "F" << userInput << " = " << fibN << endl;
		userInput = getFibInput();                                                        //Give option to another number or -1 to exit. 
	}

	cout << "closing..." << endl;


}




