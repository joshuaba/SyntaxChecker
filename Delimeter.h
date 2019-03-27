#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

class Delimeter
{
    public:
        Delimeter(); //default constructor
        Delimeter(char character, int lineNum); //overloaded constructor
        char getOpeningDelimeter(); //return the openingDelimeter member variable
        int getLineNumber(); //return the line number on which the top character of the stack is located

    private:
        char openingDelimeter; //the opening delimeter found by the inputstream. Is either ( or { or [
        int lineNumber; //the line number the openingDelimeter is located 
};
