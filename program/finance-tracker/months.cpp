#include <iostream>
#include <iomanip>
#include "global.h"
#include "colors.h"

using std::endl;
using std::cout;
using std::setw;
using std::setprecision;
using std::right;
using std::left;


const char* shortMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
#define MONTH_W 6
#define MONEY_W 12

void printChars(char c, int n)
{
    for (int i = 0; i < n; i++)
        cout << c;
}

double getBalance(Month month)
{
    return month.income - month.expense;
}

void displayBalanceWithSign(Month month)
{
    if (month.income >= month.expense)
        cout << '+';
    cout << getBalance(month);
}

double getExpenseRatio(Month month)
{
    return (month.expense / month.income) * 100;
}

void displayMonthInfo(Month month)
{
    cout << " Income: " << month.income << endl;
    cout << " Expense: " << month.expense << endl;

    cout << " Balance: ";
    displayBalanceWithSign(month);

    cout << " Expense Ratio: " << getExpenseRatio(month) << '%' << endl;
}

double getTotalIncome(Month* months, int& monthsAdded)
{
    double totalIncome = 0;
    for (int i = 0; i < monthsAdded; i++)
    {
        totalIncome += months[i].income;
    }

    return totalIncome;
}

double getTotalExpense(Month* months, int& monthsAdded)
{
    double totalExpense = 0;
    for (int i = 0; i < monthsAdded; i++)
    {
        totalExpense += months[i].expense;
    }

    return totalExpense;
}

double getTotalBalance(Month* months, int& monthsAdded)
{
    double totalBalance = 0;
    for (int i = 0; i < monthsAdded; i++)
    {
        totalBalance += getBalance(months[i]);
    }

    return totalBalance;
}

double getAverageBalance(Month* months, int& monthsAdded)
{
    double balance = getTotalBalance(months, monthsAdded);

    return (balance / monthsAdded);
}

void printTableHeader()
{
    cout << " ";

    cout << left
        << setw(MONTH_W) << "Month" << " | "
        << right
        << setw(MONEY_W) << "Income" << " | "
        << setw(MONEY_W) << "Expense" << " | "
        << setw(MONEY_W) << "Balance"
        << endl;
}

void printTableRows(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded; i++)
    {
        double balance = getBalance(months[i]);

        cout << " ";
        cout << left
            << setw(MONTH_W) << shortMonthNames[i] << " | "
            << right
            << setw(MONEY_W) << months[i].income << " | "
            << setw(MONEY_W) << months[i].expense << " | ";

        if (balance >= 0)
            cout << '+';

        cout << setw(MONEY_W - 1) << balance << endl;
    }

    cout << " ";
    printChars('-', MONTH_W + 3 + MONEY_W * 3 + 6);
    cout << endl;
}

void displayMonthsTable(Month* months, int& monthsAdded)
{
    cout << std::fixed << std::setprecision(2);

    printTableHeader();

    cout << " ";
    printChars('-', MONTH_W + 3 + MONEY_W * 3 + 6);
    cout << endl;

    printTableRows(months, monthsAdded);

    cout << " Total Income: " << getTotalIncome(months, monthsAdded) << endl;
    cout << " Total Expense: " << getTotalExpense(months, monthsAdded) << endl;

    int averageBalance = getAverageBalance(months, monthsAdded);
    cout << " Average Balance: ";
    if (averageBalance > 0)
        cout << '+';
    cout << averageBalance << endl;
}

void forecastNMonthsAhead(Month* months, int& monthsAdded, int monthsAhead)
{
    double totalBalance = getTotalBalance(months, monthsAdded);
    double averageBalance = getAverageBalance(months, monthsAdded);

    cout << " Current total savings: " << totalBalance << endl;
    cout << " Average monthly change: ";
    if (averageBalance > 0)
        cout << '+';
    cout << averageBalance << endl;

    if (averageBalance >= 0)
    {
        cout << GREEN << " Predicted savings after " << monthsAhead << " months: ";
        cout << totalBalance + (monthsAhead * averageBalance) << RESET << endl;
    }
    else
    {
        int monthsLeft = 0;
        while (totalBalance > 0)
        {
            totalBalance += averageBalance;
            monthsLeft++;
        }
        cout << " Expected to run out of money in " << monthsLeft << " months." << endl;
    }
}