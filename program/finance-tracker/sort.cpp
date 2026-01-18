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
* sorting functions
*
*/

#include "global.h"
#include "months.h"

void swap(Month& month1, Month& month2)
{
    Month temp = month1;
    month1 = month2;
    month2 = temp;
}

void sortByBalanceDesc(Month* months, int& monthsAdded, Month* sortedMonths)
{
    for (int i = 0; i < monthsAdded; i++)
    {
        sortedMonths[i] = months[i];
    }

    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (getBalance(sortedMonths[j]) > getBalance(sortedMonths[maxIndex]))
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(sortedMonths[i], sortedMonths[maxIndex]);
    }
}

void sortByIncomeDesc(Month* months, int& monthsAdded, Month* sortedMonths)
{
    for (int i = 0; i < monthsAdded; i++)
    {
        sortedMonths[i] = months[i];
    }

    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (sortedMonths[j].income > sortedMonths[maxIndex].income)
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(sortedMonths[i], sortedMonths[maxIndex]);
    }
}

void sortByExpenseDesc(Month* months, int& monthsAdded, Month* sortedMonths)
{
    for (int i = 0; i < monthsAdded; i++)
    {
        sortedMonths[i] = months[i];
    }

    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (sortedMonths[j].expense > sortedMonths[maxIndex].expense)
                maxIndex = j;
        }
        if (maxIndex != i)
            swap(sortedMonths[i], sortedMonths[maxIndex]);
    }
}

void sortByNumber(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (months[j].number < months[minIndex].number)
                minIndex = j;
        }

        swap(months[i], months[minIndex]);
    }
}