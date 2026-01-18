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
* header for month functions
*
*/

#pragma once

double getBalance(Month month);
double getExpenseRatio(Month month);
void displayMonthInfo(Month month);
double getTotalIncome(Month* months, int& monthsAdded);
double getTotalExpense(Month* months, int& monthsAdded);
double getTotalBalance(Month* months, int& monthsAdded);
double getAverageBalance(Month* months, int& monthsAdded);
void displayMonthsReport(Month* months, int& monthsAdded);
void forecastNMonthsAhead(Month* months, int& monthsAdded, int monthsAhead);
void printMonthsTable(Month* months, int& monthsAdded);