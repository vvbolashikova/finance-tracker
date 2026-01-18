#pragma once

#include <iostream>
using std::cout;
using std::endl;

struct Month {

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
};
