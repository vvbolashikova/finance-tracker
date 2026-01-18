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
* header for sorting functions
*
*/

#pragma once
#include  "global.h"

void sortByBalanceDesc(Month* months, int& monthsAdded, Month* sortedMonths);
void sortByIncomeDesc(Month* months, int& monthsAdded, Month* sortedMonths);
void sortByExpenseDesc(Month* months, int& monthsAdded, Month* sortedMonths);
void sortByNumber(Month* months, int& monthsAdded);