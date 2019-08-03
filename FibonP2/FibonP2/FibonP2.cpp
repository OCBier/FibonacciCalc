/** FibonP2.cpp
 *
 *  Program iteratively calculates the Fibonacci number Fn, where n is an integer >= 0. Provides the requested
 *  number as output. Also calculates and outputs the time required to perform the calculation.
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
#include <regex>
#include <chrono>
#include <inttypes.h>

using namespace std;


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

	return stol(input);                                                       //Return input string converted to integer.


}


uint64_t fibon2(int n)
{

	if (n < 2)
	{
		return n;
	}

	uint64_t n1 = 0;
	uint64_t n2 = 1;


	for (int i = 0; i < n - 1; i++)
	{
		uint64_t temp = n1;
		n1 = n2;
		n2 = temp + n2;
	}

	return n2;

}




int main()
{
	int64_t userInput = getFibInput();

	while (userInput >= 0)
	{
		auto start = std::chrono::high_resolution_clock::now();

		uint64_t fibN = fibon2(userInput);                                          //Calculate the Fibonacci number using fibon1().

		auto end = std::chrono::high_resolution_clock::now();
		auto diff = end - start;
		auto runTime = std::chrono::duration_cast<std::chrono::nanoseconds>(diff);       //Cast runtime to nanoseconds

		cout << "F" << userInput << " = " << fibN << endl;
		cout << "Runtime was " << runTime.count() << " ns." << endl;                      //Output runtime in microseconds
		userInput = getFibInput();                                                        //Give option to another number or -1 to exit. 
	}

	cout << "closing..." << endl;


}