#include <iostream>
#include "stringlib.h"
#include "command-processor.h"
#include "global.h"
#include "colors.h"

using std::cin;
using std::cout;
using std::endl;

int main()
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
            cout << RED << " Session already set up." << RESET << endl;
        }
        else if (!isCommandSetup && !isSetup)
        {
            cout << RED << " Set up session first." << RESET << endl;
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