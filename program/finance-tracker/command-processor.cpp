#include <iostream>
#include "stringlib.h"
#include "global.h"
#include "months.h"
#include "colors.h"
#include "sort.h"

using std::cout;
using std::cin;
using std::endl;

#define SEARCH_ARG_INDEX 7
#define SORT_ARG_INDEX 5
#define FORECAST_ARG_INDEX 9

const char* monthNames[12] = { "January", "February", "March", "April", "May", "June", 
                                "July", "August", "September", "October", "November", "December" };

void displayInvalidArgMessage(const char* command)
{
    cout << RED << "Invalid argument(s) for command <" << command << ">." << RESET << endl;
}

void clearInputStream()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

bool isValidMonthName(char* arg)
{
    const char* lowercaseMonths[24] = {"january", "february", "march", "april", "may", "june",
                                "july", "august", "september", "october", "november", "december" };
    for (int i = 0; i < 12; i++)
    {
        if (strcmp(arg, lowercaseMonths[i]) == 0)
            return true;
    }
    
    return false;
}

bool isValidSortArg(char* arg)
{
    return compareStrings(arg, "income") == 0 ||
        compareStrings(arg, "expense") == 0 ||
        compareStrings(arg, "balance") == 0;
}

bool isValidMonthNumber(char* arg)
{
    if (!isInteger(arg))
        return false;

    int value = toInteger(arg);
    return value >= 1 && value <= 12;
}

bool isValidForecastArg(char* arg)
{
    return isInteger(arg);
}

void displaySubtractionResultWithSign(double num1, double num2)
{
    if (num1 >= num2)
        cout << '+';
    cout << num1 - num2;
}

void setup(int& setupMonths)
{
    cout << " Enter number of months (1-12): ";

    char input[10];
    char* arg = input;

    while (true)
    {
        cin.getline(input, 10);
        clearInputStream();

        arg = input;
        trim(&arg, ' ');

        if (isValidMonthNumber(arg))
            break;

        cout << RED << " Number of months must be between 1 and 12." << RESET << endl;
        cout << " Enter number of months (1-12): ";
    }

    setupMonths = toInteger(arg);
    cout << YELLOW << " Profile created successfully." << RESET << endl << endl;
}

int readMonth()
{
    char monthStr[10];
    char* month = monthStr;

    while (true)
    {
        cin.getline(monthStr, 10);
        clearInputStream();

        month = monthStr;
        trim(&month, ' ');

        if (isValidMonthNumber(month))
            break;

        cout << RED << " The month must be a number between 1 and 12. " << RESET << endl;
        cout << " Enter month (1-12): ";
    }

    return toInteger(month);
}

double readIncome()
{
    char incomeStr[10];
    char* income = incomeStr;

    while (true)
    {
        cin.getline(incomeStr, 10);
        clearInputStream();

        income = incomeStr;
        trim(&income, ' ');

        if (isDouble(income))
            break;

        cout << RED << " Income must be a valid number." << RESET << endl;
        cout << " Enter income: ";
    }

    return toDouble(income);
}

double readExpense()
{
    char expenseStr[10];
    char* expense = expenseStr;

    while (true)
    {
        cin.getline(expenseStr, 10);
        clearInputStream();

        expense = expenseStr;
        trim(&expense, ' ');

        if (isDouble(expense))
            break;

        cout << RED << " Expense must be a valid number." << RESET << endl;
        cout << " Enter expense: ";
    }

    return toDouble(expense);
}

void add(Month* months, int& monthsAdded)
{
    cout << " Enter month (1-12): ";
    short month = readMonth();

    cout << " Enter income: ";
    double income = readIncome();

    cout << " Enter expense: ";
    double expense = readExpense();

    months[monthsAdded].number = month;
    months[monthsAdded].income = income;
    months[monthsAdded].expense = expense;

    cout << YELLOW << " Balance for " << monthNames[month-1] << ": ";
    displaySubtractionResultWithSign(income, expense);
    cout << RESET << endl;

    monthsAdded++;

    cout << YELLOW << " Data for " << monthNames[month - 1] << " has been saved successfully.";
    cout << RESET << endl << endl;

    sortByNumber(months, monthsAdded);
}

void report(Month* months, int &monthsAdded)
{
    displayMonthsTable(months, monthsAdded);
}

void chart()
{

}

void search(char* arg, Month* months, int& monthsAdded)
{
    bool found = false;
    int index = 0;
    for (int i = 0; i < monthsAdded; i++)
    {
        if (months[i].number == monthToNumber(arg))
        {
            found = true;
            index = i;
            break;
        }
    }
    if (found)
    {

    }
}

void sort(char* arg)
{

}

void forecast(char* arg, Month* months, int &monthsAdded)
{
    int monthsAhead = toInteger(arg);
    forecastNMonthsAhead(months, monthsAdded, monthsAhead);
}

//void help()
//{
//    cout << "Command list:" << endl;
//}

bool executeCommand(char* command, Month* months, int& setupMonths, int& monthsAdded)
{
    if (compareStrings(command, "setup") == 0)
    {
        setup(setupMonths);
        return true;
    }
    else if (compareStrings(command, "add") == 0)
    {
        add(months, monthsAdded);
        return true;
    }
    else if (compareStrings(command, "report") == 0)
    {
        report(months, monthsAdded);
        return true;
    }
    else if (compareStrings(command, "chart") == 0)
    {
        chart();
        return true;
    }
    else if (stringStartsWith(command, "search "))
    {
        int len = strlen(command);
        char* arg = substring(command, SEARCH_ARG_INDEX, len);
        trim(&arg, ' ');
        toLower(arg);

        if (isValidMonthNumber(arg) || isValidMonthName(arg))
        {
            search(arg);
        }
        else
        {
            displayInvalidArgMessage("search");
        }
    }
    else if (stringStartsWith(command, "sort "))
    {
        int len = strlen(command);
        char* arg = substring(command, SORT_ARG_INDEX, len);
        trim(&arg, ' ');

        if (isValidSortArg(arg))
        {
            sort(arg);
        }
        else
        {
            displayInvalidArgMessage("sort");
        }

        delete[] arg;
        return true;

    }
    else if (stringStartsWith(command, "forecast "))
    {
        int len = strlen(command);
        char* arg = substring(command, FORECAST_ARG_INDEX, len);
        trim(&arg, ' ');

        if (isValidForecastArg(arg))
        {
            forecast(arg, months, monthsAdded);
        }
        else
        {
            displayInvalidArgMessage("forecast");
            cout << "forecast <monthsAhead>" << endl;
        }
        delete[] arg;
        return true;
    }
    else if (compareStrings(command, "cls") == 0)
    {
        cout << "\033[2J\033[H";
        return true;
    }

    /*else if (compareStrings(command, "help") == 0)
    {
        help();
    }*/

    return false;
}

/*
void displayForecastFormat()
{
    cout << " forecast <monthsAhead>" << endl;
}

void displaySortFormat()
{
    cout << " sort <criteria> <order>" << endl;
    cout << " criteria: income / expense / balance" << endl;
    cout << " order: asc / desc" << endl;
}

void displaySearchFormat()
{
    cout << " search <month>" << endl;
    cout << " month: January-December | Jan-Dec| 1-12" << endl;
}

void displayCommandFormat(const char* command)
{
    if (compareStrings(command, "forecast"))
    {

    }
}

*/