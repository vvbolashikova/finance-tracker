#include "global.h"
#include "months.h"

void swap(Month& month1, Month& month2)
{
    Month temp = month1;
    month1 = month2;
    month2 = temp;
}

void sortByBalanceDesc(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (getBalance(months[j]) > getBalance(months[maxIndex]))
                maxIndex = j;
        }

        swap(months[i], months[maxIndex]);
    }
}

void sortByBalanceAsc(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (getBalance(months[j]) < getBalance(months[minIndex]))
                minIndex = j;
        }

        swap(months[i], months[minIndex]);
    }
}

void sortByIncomeDesc(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (months[j].income > months[maxIndex].income)
                maxIndex = j;
        }

        swap(months[i], months[maxIndex]);
    }
}

void sortByIncomeAsc(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (months[j].income < months[minIndex].income)
                minIndex = j;
        }

        swap(months[i], months[minIndex]);
    }
}

void sortByExpenseDesc(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (months[j].expense > months[maxIndex].expense)
                maxIndex = j;
        }

        swap(months[i], months[maxIndex]);
    }
}

void sortByExpenseAsc(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (months[j].expense < months[minIndex].expense)
                minIndex = j;
        }

        swap(months[i], months[minIndex]);
    }
}

void sortByNumber(Month* months, int& monthsAdded)
{
    for (int i = 0; i < monthsAdded - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < monthsAdded; j++)
        {
            if (months[j].number < months[minIndex].number)
                minIndex = j;
        }

        swap(months[i], months[minIndex]);
    }
}