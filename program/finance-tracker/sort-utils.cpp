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
* comparators for sorting
*
*/

#include "global.h"

bool compareByIncomeAsc(const Month& a, const Month& b)
{
    return a.income < b.income;
}

bool compareByIncomeDesc(const Month& a, const Month& b)
{
    return a.income > b.income;
}

bool compareByExpenseAsc(const Month& a, const Month& b)
{
    return a.expense < b.expense;
}

bool compareByExpenseDesc(const Month& a, const Month& b)
{
    return a.expense > b.expense;
}

bool compareByBalanceAsc(const Month& a, const Month& b)
{
    return (a.income - a.expense) < (b.income - b.expense);
}

bool compareByBalanceDesc(const Month& a, const Month& b)
{
    return (a.income - a.expense) > (b.income - b.expense);
}

bool compareByNumberAsc(const Month& a, const Month& b)
{
    return a.number < b.number;
}