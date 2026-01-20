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
* header for sorting comparators
*
*/

#pragma once
#include "global.h"

typedef bool (*MonthComparator)(const Month&, const Month&);
bool compareByIncomeDesc(const Month& a, const Month& b);
bool compareByIncomeAsc(const Month& a, const Month& b);
bool compareByExpenseDesc(const Month& a, const Month& b);
bool compareByExpenseAsc(const Month& a, const Month& b);
bool compareByBalanceDesc(const Month& a, const Month& b);
bool compareByBalanceAsc(const Month& a, const Month& b);
bool compareByNumberAsc(const Month& a, const Month& b);