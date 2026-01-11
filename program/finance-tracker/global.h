#pragma once

#include <iostream>
using std::cout;
using std::endl;

int setupMonths = 0;

enum Months {
    JANUARY=1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

struct Month {
private:
    int number;
    double income, expense;

public:
    Month()
    {
        income = 0;
        expense = 0;
    }
    Month(double income, double expense)
    {
        this->income = income;
        this->expense = expense;
    }

    double getIncome()
    {
        return income;
    }

    void setIncome(double income)
    {
        this->income = income;
    }

    double getExpense()
    {
        return expense;
    }

    void setExpense(double expense)
    {
        this->expense = expense;
    }

    double getBalance()
    {
        return income - expense;
    }

    double getExpenseRatio()
    {
        return (expense - income) * 100;
    }

    void displayMonthInfo()
    {
        cout << "Income: " << income << endl;
        cout << "Expense: " << expense << endl;

        cout << "Balance: ";
        if (this->getBalance() > 0)
            cout << '+'; 
        cout << getBalance() << endl;

        cout << "Expense Ratio: " << getExpenseRatio() << '%' << endl;
    }

    static double getTotalIncome(Month* months, int n)
    {
        double totalIncome = 0;
        for (int i = 0; i < n; i++)
        {
            totalIncome += months[i].getIncome();
        }

        return totalIncome;
    }

    static double getTotalExpense(Month* months, int n)
    {
        double totalExpense = 0;
        for (int i = 0; i < n; i++)
        {
            totalExpense += months[i].getExpense();
        }

        return totalExpense;
    }

    static double getTotalBalance(Month* months, int n)
    {
        double totalBalance = 0;
        for (int i = 0; i < n; i++)
        {
            totalBalance += months[i].getBalance();
        }

        return totalBalance;
    }

    static double getAverageBalance(Month* months, int n)
    {
        double balance = getTotalBalance(months, n);

        return (balance / n);
    }

    static void displayMonthsTable(Month* months, int n)
    {
        /* add table */
        
        cout << "Total Income: " << getTotalIncome(months, n) << endl;
        cout << "Total Expense: " << getTotalExpense(months, n) << endl;

        int averageBalance = getAverageBalance(months, n);
        cout << "Average Balance: ";
        if (averageBalance > 0) 
            cout << '+';
        cout << averageBalance << endl;
    }

    static void forecastNMonthsAhead(Month* months, int n, int monthsAhead)
    {
        double totalBalance = getTotalBalance(months, n);
        double averageBalance = getAverageBalance(months, n);

        cout << "Current total savings: " << totalBalance << endl;
        cout << "Average monthly change: ";
        if (averageBalance > 0)
            cout << '+';
        cout << averageBalance << endl;

        if (averageBalance >= 0)
        {
            cout << "Predicted savings after " << n << " months: " << totalBalance + n * averageBalance;
        }
        else
        {
            int monthsLeft = 0;
            while (totalBalance > 0)
            {
                totalBalance += averageBalance;
                monthsLeft++;
            }
            cout << "Expected to run out of money in " << monthsLeft << " months." << endl;
        }
    }

};

Month* months = new Month[0];