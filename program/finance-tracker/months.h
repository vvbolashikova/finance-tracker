#pragma once

#include "global.h"

double getBalance(Month month);
double getExpenseRatio(Month month);
void displayMonthInfo(Month month);
double getTotalIncome(Month* months, int& monthsAdded);
double getTotalExpense(Month* months, int& monthsAdded);
double getTotalBalance(Month* months, int& monthsAdded);
double getAverageBalance(Month* months, int& monthsAdded);
void displayMonthsTable(Month* months, int& monthsAdded);
void forecastNMonthsAhead(Month* months, int& monthsAdded, int monthsAhead);