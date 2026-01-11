#include <iostream>

#define ASCII_CASE_DIFF 'a' - 'A'

using std::cout;
using std::cin;
using std::endl;

double pow(double base, int power)
{
    double result = 1;
    while (power > 0)
    {
        result *= base;
        power--;
    }
    return result;
}

void trim(char** arg, char c)
{
    char* p = *arg;

    while (*p++);
        p--;

    while (c == *--p)
        *p = 0;

    while (c == *(*arg)++);
        (*arg)--;
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

char* toLower(char* str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' and str[i] <= 'Z')
            str[i] += ASCII_CASE_DIFF;
        i++;
    }
    return str;
}

bool isDigit(char symbol)
{
    return symbol >= '0' and symbol <= '9';
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
        if (!isDigit(str[len]))
            return false;
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