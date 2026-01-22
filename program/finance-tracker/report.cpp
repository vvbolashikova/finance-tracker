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
* report display functions
*
*/

#include <iostream>
#include <iomanip>
#include "global.h"
#include "colors.h"
#include "stringlib.h"
#include "months.h"

using std::endl;
using std::cout;
using std::setw;
using std::setprecision;
using std::right;
using std::left;

#define MONTH_W 6
#define MONEY_W 12

const char* shortMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

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
            << setw(MONTH_W) << shortMonthNames[months[i].number - 1] << " | "
            << right
            << setw(MONEY_W) << months[i].income << " | "
            << setw(MONEY_W) << months[i].expense << " | ";

        printBalance(balance, MONEY_W - 2);
        cout << endl;
    }

    cout << " ";
    printChars('-', MONTH_W + 3 + MONEY_W * 3 + 6);
    cout << endl << endl;
}

void printMonthsTable(Month* months, int& monthsAdded)
{
    cout << std::fixed << std::setprecision(2);
    printTableHeader();

    cout << " ";
    printChars('-', MONTH_W + 3 + MONEY_W * 3 + 6);
    cout << endl;

    printTableRows(months, monthsAdded);
}

void displayMonthsReport(Month* months, int& monthsAdded)
{
    cout << endl;
    printMonthsTable(months, monthsAdded);

    cout << " Total Income: " << getTotalIncome(months, monthsAdded) << endl;
    cout << " Total Expense: " << getTotalExpense(months, monthsAdded) << endl;

    int averageBalance = getAverageBalance(months, monthsAdded);
    cout << " Average Balance: ";
    printBalance(averageBalance, 0);
    cout << endl << endl;
}