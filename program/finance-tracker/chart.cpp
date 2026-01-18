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
* chart visualization functions
*
*/

#include <iostream>
#include <iomanip>
#include "global.h"
#include "stringlib.h"

using std::setw;
using std::endl;
using std::cout;

#define MIN_ROWS 4
#define MAX_ROWS 10

int clamp(int rows, int min, int max)
{
    if (rows < min) return min;
    if (rows > max) return max;
    return rows;
}

int calculateStep(double rawStep)
{
    if (rawStep <= 0)
        return 1;

    int magnitude = 1;
    while (rawStep >= 10)
    {
        rawStep /= 10;
        magnitude *= 10;
    }

    if (rawStep <= 1) 
        return 1 * magnitude;
    if (rawStep <= 2) 
        return 2 * magnitude;
    if (rawStep <= 5) 
        return 5 * magnitude;

    return 10 * magnitude;
}

int findMaxIncome(Month* months, int& monthsAdded)
{
    double maxIncome = 0;
    for (int i = 0; i < monthsAdded; i++)
    {
        if (months[i].income > maxIncome)
            maxIncome = months[i].income;
    }

    return maxIncome;
}

void printRows(Month* months, int& monthsAdded, int maxLevel, int step)
{
    for (int level = maxLevel; level >= step; level -= step)
    {
        cout << setw(6) << level << " | ";

        for (int i = 0; i < monthsAdded; i++)
        {
            if (months[i].income >= level)
                cout << "#    ";
            else
                cout << "     ";
        }
        cout << endl;
    }
}

void displayIncomeChart(Month* months, int& monthsAdded)
{
    const char* shortMonthNames[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    double maxIncome = findMaxIncome(months, monthsAdded);

    if (maxIncome <= 0)
    {
        cout << "No income data to display." << endl;
        return;
    }

    int targetRows = 6;
    targetRows = clamp(targetRows, MIN_ROWS, MAX_ROWS);

    double rawStep = maxIncome / targetRows;
    int step = calculateStep(rawStep);

    int rows = (int)((maxIncome + step - 1) / step);
    rows = clamp(rows, MIN_ROWS, MAX_ROWS);

    int maxLevel = rows * step;

    printRows(months, monthsAdded, maxLevel, step);

    cout << "       ";
    printChars('-', monthsAdded * 5 + 2);
    cout << endl;
    cout << "        ";

    for (int i = 0; i < monthsAdded; i++)
    {
        cout << shortMonthNames[i] << "  ";
    }

    cout << endl << endl;
}
