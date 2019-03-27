#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "SyntaxCheckerNew.h"

using namespace std;

int main(int argc, char **argv)
{

    string nameOfInputFile; //variable for the name of the input file passed in as a command-line argument
    bool runAgain = false; //boolean condition. Set to true if the user decides they want to input another file to be checked

    if (argc > 1)
    {
        nameOfInputFile = argv[1];

            SyntaxChecker sc(nameOfInputFile); // create a new instance of SyntaxChecker with the name of the inputFile as an argument
            sc.checkSyntax(); //check the syntax of the inputfile
            if(sc.getFoundErrorValue() == false) //if the input file did not contain an error
            {
                cout << "Would you like to check the syntax of another file? (Y/N)" << endl;
                char answer;
                cin >> answer;
                if (answer == 'Y' || answer == 'y')
                {
                    runAgain = true;
                }
                else //this block is run if the user types in anything other than 'Y' or 'y' (the user does not want to input another file)
                {
                    cout << "Thanks for checking your syntax!" << endl;
                    exit(0); //exit the program if the user does not want to pass in an input file
                }
            }

            while(runAgain) //this block is run as long as the user decides to pass in more input files to be checked
            {
                cout << "What is the name of the new input file?" << endl;
                string newInputFile;
                cin >> newInputFile;
                SyntaxChecker newsc(newInputFile); //create a new instance of SyntaxChecker
                newsc.checkSyntax(); //check the syntax of newInputFile

                if(sc.getFoundErrorValue() == false) //if there was no error in the input file
                {
                    cout << "Would you like to check the syntax of another file? (Y/N)" << endl;
                    char answer; //a char variable storing the user's answer
                    cin >> answer; //read in the user's answer from the keyboard
                    if (answer == 'Y' || answer == 'y')
                    {
                        runAgain = true;
                    }
                    else
                    {
                        cout << "Thanks for checking your syntax!" << endl;
                        exit(0); //if the user types anything other than 'Y' or 'y' (the user does not want to pass in another file), exit the program
                    }
                }
            }
    }

    else //this block is run if the user does nt pass in an input file as a command line argument the first time the user runs the program
    {
        cout << "You need to input the name of a file as a command-line argument. Try again!" << endl;
    }

    return 0;
}
