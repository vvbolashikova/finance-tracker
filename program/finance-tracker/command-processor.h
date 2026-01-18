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
* header for command processing
*
*/

#pragma once
#include "global.h"

void clearInputStream();
bool executeCommand(char* command, Month* months, int& setupMonths, int& monthsAdded);