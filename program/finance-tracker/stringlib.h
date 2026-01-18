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
* header for string and character processing functions
*
*/

#pragma once

void trim(char** arg, char c);
bool stringStartsWith(const char* str, const char* substr);
char* toLower(char* str);
char* substring(char* str, int startIndex, int len);
bool isDigit(char symbol);
bool isInteger(char* str);
int toInteger(char* str);
bool isDouble(char* str);
double toDouble(char* str);
int compareStrings(const char* s1, const char* s2);
void printChars(char c, int n);