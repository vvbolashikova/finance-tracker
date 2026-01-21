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
* main sorting functions
*
*/

#include "global.h"
#include "months.h"
#include "sort-utils.h"

void swap(Month& month1, Month& month2)
{
    Month temp = month1;
    month1 = month2;
    month2 = temp;
}

void sortMonths(Month* months, int& monthsAdded, Month* sortedMonths, MonthComparator comp)
{
    if (months != sortedMonths)
    {
        for (int i = 0; i < monthsAdded; i++)
        {
            sortedMonths[i] = months[i];
        }
    }    

    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int targetIndex = i;

        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (comp(sortedMonths[j], sortedMonths[targetIndex]))
                targetIndex = j;
        }

        if (targetIndex != i)
            swap(sortedMonths[i], sortedMonths[targetIndex]);
    }
}