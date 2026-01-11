#include <iostream>
#include "stringlib.h"
#include "global.h"

using std::cout;
using std::cin;
using std::endl;

#define SEARCH_ARG_INDEX 7
#define SORT_ARG_INDEX 5
#define FORECAST_ARG_INDEX 9


bool isValidSortArg(char* arg)
{
    return arg == "income" || arg == "expense" || arg == "balance";
}

bool isValidMonthNumber(char* arg)
{
    if (isInteger(arg))
        return toInteger(arg) >= 1 and toInteger(arg) <= 12;
    return false;
}

bool isValidForecastArg(char* arg)
{
    return isInteger(arg);
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
        setupMonths = toInteger(arg);
        cout << "Profile created successfully.";
    }
}

void add()
{
    cout << "Enter month (1-12): ";

    char input[10];
    cin.getline(input, 10);

    char* month = input;
    trim(&month, ' ');

    if (isValidMonthNumber(month))
    {
        // months[toInteger(month) - 1];
    }

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
    // Month::forecastNMonthsAhead()

}

bool executeCommand(char* command)
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
        trim(&arg, ' ');

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
        trim(&arg, ' ');

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
        trim(&arg, ' ');

        if (isValidForecastArg(arg))
        {
            forecast(arg);
            return true;
        }
    }

    return false;
}