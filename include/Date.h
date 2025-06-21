#pragma once
#include <iostream>

using namespace std;

class Date
{
protected:
    int day, month, year;
    bool isValidDate(int d, int m, int y)
    {
        if (m < 1 || m > 12 || d < 1)
            return false;
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)))
        {
            daysInMonth[1] = 29;
        }
        return d <= daysInMonth[m - 1];
    }

public:
    // Constructors
    Date() : day(15), month(3), year(2024) {};
    Date(int _day, int _month, int _year)
    {
        while (!isValidDate(_day, _month, _year))
        {
            cout << "IInvalid date! Enter again (DD MM YYYY): ";
            cin >> _day >> _month >> _year;
        }
        day = _day;
        month = _month;
        year = _year;
    };
    Date(const Date &other) : day(other.day), month(other.month), year(other.year) {};
    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    // Setters
    void setDay(int d)
    {
        if (isValidDate(d, month, year))
            day = d;
        else
            cout << "Invalid day!\n";
    }

    void setMonth(int m)
    {
        if (isValidDate(day, m, year))
            month = m;
        else
            cout << "Invalid month!\n";
    }

    void setYear(int y)
    {
        if (isValidDate(day, month, y))
            year = y;
        else
            cout << "Invalid year!\n";
    }
    friend istream &operator>>(istream &in, Date &date);
    friend ostream &operator<<(ostream &out, Date &date);
}; 