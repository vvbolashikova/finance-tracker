#include <iostream>
#include "stringlib.h"
#include "global.h"
#include "months.h"
#include "colors.h"

using std::cout;
using std::cin;
using std::endl;

#define SEARCH_ARG_INDEX 7
#define SORT_ARG_INDEX 5
#define FORECAST_ARG_INDEX 9

const char* monthNames[12] = { "January", "February", "March", "April", "May", "June", 
                                "July", "August", "September", "October", "November", "December" };

void clearInputStream()
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}

bool isValidSortArg(char* arg)
{
    return strcmp(arg, "income") == 0 ||
        strcmp(arg, "expense") == 0 ||
        strcmp(arg, "balance") == 0;
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
    cout << YELLOW << " Profile created successfully." << RESET << endl;
}


void add(Month* months, int& monthsAdded)
{
    cout << " Enter month (1-12): ";

    char monthStr[10];
    cin.getline(monthStr, 10);

    char* month = monthStr;
    trim(&month, ' ');

    while (!isValidMonthNumber(month))
    {
        cout << RED << " The month must be a number between 1 and 12. " << RESET << endl;
        cout << " Enter month (1-12): ";
        cin.getline(monthStr, 10);
        month = monthStr;
        trim(&month, ' ');
    }

    char incomeStr[10];
    cout << " Enter income: ";
    cin.getline(incomeStr, 10);
    char* income = incomeStr;
    
    while (!isDouble(income))
    {
        cout << RED << " Income must be a valid number." << RESET << endl;
        cout << " Enter income: ";
        cin.getline(incomeStr, 10);
        income = incomeStr;
    }

    char expenseStr[10];
    cout << " Enter expense: ";
    cin.getline(expenseStr, 10);

    char* expense = expenseStr;;
    while (!isDouble(expense))
    {
        cout << RED << " Expense must be a valid number." << RESET<< endl;
        cout << " Enter expense: ";
        cin.getline(expenseStr, 10);
        expense = expenseStr;
    }

    int monthInd = toInteger(month) - 1;

    double incomeNum = toDouble(income);
    double expenseNum = toDouble(expense);

    months[monthInd].income = incomeNum;
    months[monthInd].expense = expenseNum;

    cout << YELLOW << " Balance for " << monthNames[monthInd] << " = ";
    displaySubtractionResultWithSign(incomeNum, expenseNum);
    cout << RESET << endl;

    monthsAdded++;
}

void report(Month* months, int &monthsAdded)
{
    displayMonthsTable(months, monthsAdded);
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

void forecast(char* arg, Month* months, int &setupMonths)
{
    int monthsAhead = toInteger(arg);
    forecastNMonthsAhead(months, setupMonths, monthsAhead);
}

bool executeCommand(char* command, Month* months, int& setupMonths, int& monthsAdded)
{
    if (strcmp(command, "setup") == 0)
    {
        setup(setupMonths);
        return true;
    }

    if (strcmp(command, "add") == 0)
    {
        add(months, monthsAdded);
        return true;
    }

    if (strcmp(command, "report") == 0)
    {
        report(months, monthsAdded);
        return true;
    }

    if (strcmp(command, "chart") == 0)
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
            delete[] arg;
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
            delete[] arg;
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
            forecast(arg, months, setupMonths);
            delete[] arg;
            return true;
        }
    }

    if (strcmp(command, "cls") == 0)
    {
        cout << "\033[2J\033[H";
        return true;
    }

    return false;
}