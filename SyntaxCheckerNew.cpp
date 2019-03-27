#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "SyntaxCheckerNew.h"

using namespace std;

SyntaxChecker::SyntaxChecker()
{
	myStack = new GenStackGeneric<Delimeter>(); //create a new stack of Delimeter objects. This is the default constructor
}

SyntaxChecker::SyntaxChecker(string fileToCheck)
{
	myStack = new GenStackGeneric<Delimeter> (20); //create a new stack of Delimeter objects. Initialize the size to 20 objects. If stack fills up, will automatically re-size.
	inputFileToCheck = fileToCheck;
}

SyntaxChecker::~SyntaxChecker()
{
	delete myStack;
}

char SyntaxChecker::findOppositeDelim(char delim)
{
	char oppositeDelimeter;

	switch (delim)
	{
		case '(':
			oppositeDelimeter = ')';
			break;
		case '{':
			oppositeDelimeter = '}';
			break;
		case '[':
			oppositeDelimeter = ']';
			break;
		case ')':
			oppositeDelimeter = '(';
			break;
		case '}':
			oppositeDelimeter = '{';
			break;
		case ']':
			oppositeDelimeter = '[';
			break;
	}

	return oppositeDelimeter;
}

void SyntaxChecker::checkSyntax()
{

	ifstream inputStream(inputFileToCheck);

	while(!inputStream.eof())
	{
		string stringToProcess; //variable storing the line of the input file
		getline(inputStream, stringToProcess); //get the lines of the input file
		processLine(stringToProcess); //calls the processLine method
		if(foundError) //break if an error was found in any line
		{
			break;
		}
		processedLineNum++;
	}

	if(!foundError && myStack->isEmpty())
	{
		cout << "No errors were found! Great job coding today!" << endl;
	}


	else if(!myStack->isEmpty() && !foundError) //there are opening delimeters that were not matched to a closing delimeter and no mismatch error was found (which means there are extra opening delims)
	{
		Delimeter delimObjectStillInStack = myStack->pop();
		char delimStillInStack = delimObjectStillInStack.getOpeningDelimeter();
		switch (delimStillInStack)
		{
			case '(':
				cout << "Error on line " << (delimObjectStillInStack).getLineNumber() << ". Expected " << findOppositeDelim(delimStillInStack) << endl;
				foundError = true;
				break;
			case '[':
				cout << "Error on line " << (delimObjectStillInStack).getLineNumber() << ". Expected " << findOppositeDelim(delimStillInStack) << endl;
				foundError = true;
				break;
			case '{':
				cout << "Error on line " << (delimObjectStillInStack).getLineNumber() << ". Expected " << findOppositeDelim(delimStillInStack) << endl;
				foundError = true;
				break;
		}
	}

	inputStream.close();
}

void SyntaxChecker::processLine(string lineToProcess)
{
	for (int i = 0; i < lineToProcess.length(); ++i)
	{
		Delimeter delimToAdd;

		if(lineToProcess[i] == '(')
		{
			delimToAdd = Delimeter('(', processedLineNum); //create a new Delimeter instance
			myStack->push(delimToAdd);
		}

		else if(lineToProcess[i] == '{')
		{
			delimToAdd = Delimeter('{', processedLineNum); //create a new Delimeter instance
			myStack->push(delimToAdd);
		}

		else if(lineToProcess[i] == '[')
		{
			delimToAdd = Delimeter('[', processedLineNum); //create a new Delimeter instance
			myStack->push(delimToAdd);
		}

		else if(lineToProcess[i] == ')')
		{
			if((myStack->peek()).getOpeningDelimeter() == '(') //no errors were found, delimeters match
			{
				(myStack->pop()).getOpeningDelimeter(); //clear out the top character of the stack, since there was a mismatched delimeter
			}

			else //mismatched )
			{
				cout << "Error on line: " << processedLineNum << ". Expected " << findOppositeDelim((myStack->pop()).getOpeningDelimeter()) << endl;
				foundError = true;
			}
		}

		else if(lineToProcess[i] == '}')
		{
			if((myStack->peek()).getOpeningDelimeter() == '{') //no errors were found, delimeters match
			{
				(myStack->pop()).getOpeningDelimeter(); //clear out the top character of the stack, since there was a mismatched delimeter
			}

			else //mismatched delimeters
			{
				cout << "Expected " << myStack->peek().getOpeningDelimeter() << " on line " << myStack->pop().getLineNumber() << endl;
				//cout << myStack->pop().getOpeningDelimeter() << endl;
				//cout << "Expected " << findOppositeDelim(myStack->peek().getOpeningDelimeter()) << " on line " << (myStack->pop()).getLineNumber() << endl;
				foundError = true;
			}
		}

		else if(lineToProcess[i] == ']')
		{
			if((myStack->peek()).getOpeningDelimeter() == '[') //no errors were found, delimeters match
			{
				(myStack->pop()).getOpeningDelimeter(); //clear out the top character of the stack, since there was a mismatched closing delimeter
			}

			else //mismatched closing delimeter
			{
				cout << "Error on line: " << processedLineNum << ". Expected " << findOppositeDelim((myStack->pop()).getOpeningDelimeter()) << " on line " << (myStack->pop()).getLineNumber() << endl;
				foundError = true;
			}
		}
	}
}

bool SyntaxChecker::getFoundErrorValue() //getter method. Needed for main method
{
	return foundError;
}
