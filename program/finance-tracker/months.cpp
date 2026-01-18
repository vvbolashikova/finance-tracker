#include <iostream>
#include "global.h"

using std::endl;
using std::cout;


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
    cout << "Income: " << month.income << endl;
    cout << "Expense: " << month.expense << endl;

    cout << "Balance: ";
    displayBalanceWithSign(month);

    cout << "Expense Ratio: " << getExpenseRatio(month) << '%' << endl;
}

double getTotalIncome(Month* months, int n)
{
    double totalIncome = 0;
    for (int i = 0; i < n; i++)
    {
        totalIncome += months[i].income;
    }

    return totalIncome;
}

double getTotalExpense(Month* months, int n)
{
    double totalExpense = 0;
    for (int i = 0; i < n; i++)
    {
        totalExpense += months[i].expense;
    }

    return totalExpense;
}

double getTotalBalance(Month* months, int n)
{
    double totalBalance = 0;
    for (int i = 0; i < n; i++)
    {
        totalBalance += getBalance(months[i]);
    }

    return totalBalance;
}

double getAverageBalance(Month* months, int n)
{
    double balance = getTotalBalance(months, n);

    return (balance / n);
}

void displayMonthsTable(Month* months, int n)
{
    /* add table */

    cout << "Total Income: " << getTotalIncome(months, n) << endl;
    cout << "Total Expense: " << getTotalExpense(months, n) << endl;

    int averageBalance = getAverageBalance(months, n);
    cout << "Average Balance: ";
    if (averageBalance > 0)
        cout << '+';
    cout << averageBalance << endl;
}

void forecastNMonthsAhead(Month* months, int n, int monthsAhead)
{
    double totalBalance = getTotalBalance(months, n);
    double averageBalance = getAverageBalance(months, n);

    cout << "Current total savings: " << totalBalance << endl;
    cout << "Average monthly change: ";
    if (averageBalance > 0)
        cout << '+';
    cout << averageBalance << endl;

    if (averageBalance >= 0)
    {
        cout << "Predicted savings after " << n << " months: " << totalBalance + n * averageBalance;
    }
    else
    {
        int monthsLeft = 0;
        while (totalBalance > 0)
        {
            totalBalance += averageBalance;
            monthsLeft++;
        }
        cout << "Expected to run out of money in " << monthsLeft << " months." << endl;
    }
}