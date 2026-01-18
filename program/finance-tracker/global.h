#pragma once

#include <iostream>
using std::cout;
using std::endl;

struct Month {
    short number;
    double income, expense;

    Month()
    {
        number = 0;
        income = 0;
        expense = 0;
    }
    Month(short number, double income, double expense)
    {
        this->number = number;
        this->income = income;
        this->expense = expense;
    }
};
