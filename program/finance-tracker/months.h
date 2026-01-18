#pragma once

#include "global.h"

double getBalance(Month month);
double getExpenseRatio(Month month);
void displayMonthInfo(Month month);
double getTotalIncome(Month* months, int n);
double getTotalExpense(Month* months, int n);
double getTotalBalance(Month* months, int n);
double getAverageBalance(Month* months, int n);
void displayMonthsTable(Month* months, int n);
void forecastNMonthsAhead(Month* months, int n, int monthsAhead);