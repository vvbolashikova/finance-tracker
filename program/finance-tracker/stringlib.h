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