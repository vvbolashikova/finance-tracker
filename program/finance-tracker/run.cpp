/**
*
* Solution to course project # 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Victoria Bolashikova
* @idnumber 6MI0600688
* @compiler VC
*
* main program loop
*
*/

#include <iostream>
#include "stringlib.h"
#include "command-processor.h"
#include "global.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

void runProgram()
{
    Month* months = nullptr;

    int setupMonths = 0;
    int monthsAdded = 0;

    cout << " >> ";

    char input[1024];
    cin.getline(input, 1024);

    bool isSetup = false;

    while (compareStrings(input, "exit") != 0)
    {
        toLower(input);

        char* command = input;

        bool isCommandSetup = !(compareStrings(command, "setup"));

        trim(&command, ' ');

        if (isCommandSetup && isSetup)
        {
            cout << RED << " Session has already been set up." << RESET << endl;
        }
        else if (!isCommandSetup && !isSetup)
        {
            cout << RED << " Session must be set up first." << RESET << endl;
        }
        else if (!executeCommand(command, months, setupMonths, monthsAdded))
        {
            cout << RED << " No such command." << RESET << endl;
        }

        if (isCommandSetup)
        {
            delete[] months;
            months = new Month[setupMonths];
            isSetup = true;
        }

        cout << " >> ";
        cin.getline(input, 1024);
    }

    delete[] months;
}