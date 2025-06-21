#include <iostream>
using namespace std;
#include "Date.h"

istream &operator>>(istream &in, Date &date)
{
    int _day, _month, _year;
    do
    {
        cout << "Enter date (DD MM YYYY): ";
        in >> _day >> _month >> _year;
    } while (!date.isValidDate(_day, _month, _year));
    date.day = _day;
    date.month = _month;
    date.year = _year;
    return in;
}

ostream &operator<<(ostream &out, Date &date)
{
    out << date.day << "-" << date.month << "-" << date.year;
    return out;
}

// int main()
// {
//     Date d1;
//     cout << "Default date: " << d1 << endl;

//     Date d2(15, 3, 2024);
//     cout << "Parameterized date: " << d2 << endl;

//     Date d3;
//     cin >> d3;
//     cout << "Entered date: " << d3 << endl;

//     return 0;
// }