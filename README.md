# Finance Tracker

## Overview

**Finance Tracker** is a C++ text-command-based console application designed to help users track and analyze their monthly financial data.  
It allows users to enter income and expenses for each month and then explore their finances through **reports, charts, forecasts, and sorting tools**.

The application focuses on clear console output, structured data handling, and user-friendly interaction through text commands.

---

## Purpose

The purpose of this application is to implement real-world features such as reporting, forecasting, and data visualization in a console environment
This project demonstrates how meaningful financial insights can be generated without a graphical interface, using only ASCII output.

---

## Features

### Session Setup
- Initialize a financial profile with a selected number of months (1–12). Each month stores its income and expense.

---

### Add Monthly Data
- Enter income and expense values for specific months
- Input is validated to prevent invalid or malformed data
- Balances are calculated automatically

---

### Reports
- Display a formatted table showing income, expense and balance by month.
- Includes summary statistics: total income, total expense, average balance.

---

### Charts
- ASCII-based charts that visualize monthly income, with dynamically scaled Y-axis based on the highest income value
- Clean, readable layout that adapts to user data

---

### Forecasting
- Predict future savings based on historical average balance, supports forecasting multiple months ahead
- Warns the user if savings are projected to run out

---

### Sorting
- Sort months based on income, expense or balance.
- Enables different views of the same financial dataset

## Commands

| Command | Description |
|--------|------------|
| `setup` | Initialize a new financial session |
| `add` | Add income and expense for a month |
| `report` | Display financial report |
| `chart` | Show income chart |
| `forecast <N>` | Forecast finances N months ahead |
| `sort <type>` | Sort months by income, expense, or balance |
| `cls` | Clear the console |
| `exit` | Exit the application |
