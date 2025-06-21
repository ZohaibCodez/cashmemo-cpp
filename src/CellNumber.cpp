#include "CellNumber.h"

istream &operator>>(istream &in, CellNumber &c)
{
    cout << "Enter Country Code : ";
    in >> c.countryCode;
    c.setCountryCode(c.countryCode);
    cout << "Enter Number : ";
    in >> c.no;
    c.setNo(c.no);
    return in;
}
ostream &operator<<(ostream &out, CellNumber &c)
{
    out << "+" << c.countryCode << " " << c.no;
    return out;
}

// int main()
// {
//     CellNumber cell;
//     cin >> cell;
//     cout << cell;
//     return 0;
// }