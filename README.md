# Finance Tracker

## Overview

**Finance Tracker** is a C++ CLI application designed to help users track and analyze their monthly financial data.  
It allows users to enter income and expenses for each month and then explore their finances through **reports, charts, forecasts, and sorting tools**.

The application focuses on clear console output, structured data handling, and user-friendly interaction through text commands.

---

## Purpose

The purpose of this application is to implement real-world features such as reporting, forecasting, and data visualization in a console environment
This project demonstrates how meaningful financial insights can be generated without a graphical interface, using only ASCII output.

---

## Features

The finance tracker offers the following features:
  - Entering income and expense data for specific months
  - Formatted table showing income, expense and balance by month.
  - Summary statistics - total income, total expense, average balance.
  - ASCII-based charts that visualize monthly income.
  - Predict future savings based on historical average balance, supports forecasting multiple months ahead
  - Warns the user if savings are projected to run out
  - Sorting months based on income, expense or balance in ascending or descending format.

---

## Commands

| Command | Description |
|--------|------------|
| `setup` | Initialize a new financial session |
| `add` | Add income and expense for a month |
| `report` | Display financial report |
| `chart` | Show income chart |
| `forecast <N>` | Forecast finances N months ahead |
| `sort <type> <order>` | Sort months by income, expense, or balance |
| `cls` | Clear the console |
| `exit` | Exit the application |

