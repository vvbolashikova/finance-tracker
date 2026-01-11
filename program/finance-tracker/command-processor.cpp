#include <iostream>
#include "stringlib.h"

using std::cout;
using std::cin;
using std::endl;

#define SEARCH_ARG_INDEX 7
#define SORT_ARG_INDEX 5
#define FORECAST_ARG_INDEX 9


bool isValidSortArg(char* arg)
{
    return true;
}

bool isValidMonthNumber(char* arg)
{
    return toInteger(arg) >= 1 and toInteger(arg) <= 12;
}

bool isValidForecastArg(char* arg, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (!isDigit(arg[i]))
            return false;
    }
    return true;
}

void setup()
{
    cout << "Enter number of months: ";

    char input[10];
    cin.getline(input, 10);

    char* arg = input;
    trim(&arg, ' ');

    if (isValidMonthNumber(arg))
    {
        cout << "Profile created successfully.";
    }
}

void add()
{
    cout << "Enter month (1-12): ";

    int month;
    cin >> month;

    int income;
    cout << "Enter income: ";
    cout << "Enter expense: ";
}

void report()
{

}

void chart()
{

}

void search(char* arg)
{

}

void sort(char* arg)
{

}

void forecast(char* arg)
{
    int monthsAhead = toInteger(arg);
}

bool identifyCommand(char* command)
{
    if (command == "setup")
    {
        setup();
        return true;
    }

    if (command == "add")
    {
        add();
        return true;
    }

    if (command == "report")
    {
        report();
        return true;
    }

    if (command == "chart")
    {
        chart();
        return true;
    }

    if (stringStartsWith(command, "search "))
    {
        int len = strlen(command);
        char* arg = substring(command, SEARCH_ARG_INDEX, len);

        if (isValidMonthNumber(arg))
        {
            search(arg);
            return true;
        }
    }

    if (stringStartsWith(command, "sort "))
    {
        int len = strlen(command);
        char* arg = substring(command, SORT_ARG_INDEX, len);

        if (isValidSortArg(arg))
        {
            sort(arg);
            return true;
        }
    }

    if (stringStartsWith(command, "forecast "))
    {
        int len = strlen(command);
        char* arg = substring(command, FORECAST_ARG_INDEX, len);

        if (isValidForecastArg(arg, len - FORECAST_ARG_INDEX))
        {
            forecast(arg);
            return true;
        }
    }

    return false;
}