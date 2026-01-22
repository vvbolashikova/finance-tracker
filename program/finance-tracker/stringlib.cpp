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
* string and character processing functions
*
*/

#include <iostream>
#include <cmath>

#define ASCII_CASE_DIFF 'a' - 'A'

using std::cout;
using std::cin;
using std::endl;

void printChars(char c, int n)
{
    for (int i = 0; i < n; i++)
        cout << c;
}

void trim(char** str, char c)
{
    if (!str || !*str) 
        return;

    char* s = *str;

    while (*s == c)
        s++;

    if (*s == '\0')
    {
        *str = s;
        return;
    }

    char* end = s;
    while (*end != '\0')
        end++;

    end--;

    while (end > s && *end == c)
    {
        *end = '\0';
        end--;
    }

    *str = s;
}

bool stringStartsWith(const char* str, const char* substr)
{
    int i = 0;
    while (substr[i] != '\0')
    {
        if (str[i] != substr[i])
            return false;
        i++;
    }

    return true;
}

int compareStrings(const char* s1, const char* s2) 
{
    while (*s1 && (*s1 == *s2)) 
    {
        s1++;
        s2++;
    }

    return (unsigned char)*s1 - (unsigned char)*s2;
}

char* toLower(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ASCII_CASE_DIFF;
        i++;
    }
    return str;
}

bool isDigit(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

int strlen(char* str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char* substring(char* str, int startIndex, int len)
{
    char* substr = new char[len + 1];
    for (int i = 0; i < len; i++)
    {
        substr[i] = *(str + startIndex + i);
    }
    substr[len] = '\0';
    return substr;
}

bool isInteger(char* str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (!isDigit(str[i]))
        {
            return false;
        }   
    }
    return true;
}

int toInteger(char* str)
{
    int num = 0;

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        num *= 10;
        num += str[i] - '0';
    }
    return num;
}

bool isDouble(char* str)
{
    int len = strlen(str);
    bool metPoint = false;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '.' && !metPoint)
        {
            metPoint = true;
            continue;
        }
        if (str[i] == '.' && metPoint)
        {
            return false;
        }
        if (!isDigit(str[i]) && str[i] != '.')
        {
            return false;
        }
    }
    return true;
}

double toDouble(char* str)
{
    int len = strlen(str);

    double result = 0;

    bool metPoint = false;
    int afterPoint = 1;

    for (int i = 0; i < len; i++)
    {
        if (isDigit(str[i]) && !metPoint)
        {
            result = result * 10 + (str[i] - '0');
        }

        if (isDigit(str[i]) && metPoint)
        {
            result += pow(0.1, afterPoint) * (str[i] - '0');
            afterPoint++;
        }

        if (str[i] == '.')
            metPoint = true;

        if (!isDigit(str[i]) && str[i] != '.')
            break;
    }
    return result;
}

void concatStrings(char* dest, const char* src) 
{
    unsigned len = strlen(dest);
    int i = 0;
    while (src[i] != '\0') 
    {
        dest[len++] = src[i];
        i++;
    }
    dest[len] = '\0';
}