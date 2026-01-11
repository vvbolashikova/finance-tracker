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
    char input[1024];

    cout << " >> ";
    cin.getline(input, 1024);

    bool isSetup = false;
    
    while (input != "exit")
    {
        char* command = toLower(input);

        trim(&command, ' ');

        if (command == "setup" && isSetup)
        {
            cout << RED << "Session already set up" << RESET << endl;
        }

        if (!isSetup and command != "setup")
        {
            cout << RED << "Set up session first!" << RESET << endl;
            continue;
        }

        if (!executeCommand(command))
        {
            cout << RED << "No such command" << RESET << endl;
        }

        if (command == "setup")
        {
            months = new Month[setupMonths];
            isSetup = true;
        }

        cout << endl << " >> ";
        cin.getline(input, 1024);
    }
}