#include <iostream>
#include "stringlib.h"
#include "command-processor.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

//#define BLACK   "\033[30m"
//#define GREEN   "\033[32m"
//#define YELLOW  "\033[33m"
//#define BLUE    "\033[34m"
//#define MAGENTA "\033[35m"
//#define CYAN    "\033[36m"
//#define WHITE   "\033[37m"

using std::cin;
using std::cout;
using std::endl;

struct Month {
private:
    double income, expense;

public:
    Month(double income, double expense)
    {
        this->income = income;
        this->expense = expense;
    }
};

int main()
{
    char str[15] = "12343.3456";

    cout << toDouble(str);

    /*char input[1024];

    cout << " >> ";
    cin.getline(input, 1024);

    bool isSetup = false;
    
    while (input != "exit")
    {
        char* command = toLower(input);

        trim(&command, ' ');

        if (!isSetup and command != "setup")
        {
            cout << RED << "Set up session first!" << RESET << endl;
            continue;
        }

        if (!identifyCommand(command))
        {
            cout << RED << "No such command" << RESET << endl;
        }

        if (command == "setup")
            isSetup = true;

        cout << " >> ";
        cin.getline(input, 1024);
    }*/
}