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
* month-related calculations
*
*/

#include <iostream>
#include <iomanip>
#include "global.h"
#include "colors.h"
#include "stringlib.h"

using std::endl;
using std::cout;
using std::setw;
using std::setprecision;
using std::right;
using std::left;

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

    cout << endl << " Expense Ratio: " << getExpenseRatio(month) << '%' << endl;
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