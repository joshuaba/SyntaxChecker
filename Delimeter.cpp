#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "Delimeter.h"
using namespace std;

Delimeter::Delimeter() //default constructor
{
    openingDelimeter = '(';
    lineNumber = 0;
}

Delimeter::Delimeter(char character, int lineNum)
{
    openingDelimeter = character;
    lineNumber = lineNum;
}

char Delimeter::getOpeningDelimeter()
{
    return openingDelimeter;
}

int Delimeter::getLineNumber()
{
    return lineNumber;
}
