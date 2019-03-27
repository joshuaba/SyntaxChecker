#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "GenStackGeneric.h"
#include "Delimeter.h"

using namespace std;

class SyntaxChecker
{
	public:
		SyntaxChecker(); //default no-arg constructor
		SyntaxChecker(string fileToCheck); //overloaded constructor
		~SyntaxChecker(); //destructor
		void checkSyntax(); //check the syntax of the input file. Calls processLine(string lineToProcess)
		void processLine(string lineToProcess); //processed each individual line in the input file to determine any errors
		void addCharacterToStack(char charToAdd); //add charToAdd to the stack initalized in the constructor
		bool getFoundErrorValue(); //access the foundError variable

	private:
		GenStackGeneric<Delimeter> *myStack; //this creates an object of the class GenStackGeneric, creating a stack of char values to be pushed onto the stack
		int processedLineNum = 1; //number of the line being processed
		bool foundError = false; //boolean condition to test if an error was found in the input file
		bool extraOpeningDelims = true; //boolean condition to check if there are extra opening delimeters by the time all the lines have been processed. True by default, changed to false if an error is found in any line
		string inputFileToCheck; //the name of the input file whose syntax the program will check
		char findOppositeDelim(char delim); //find the opposite delimiter. For example, if delimeter is (, then the opposite delimeter is )
};
