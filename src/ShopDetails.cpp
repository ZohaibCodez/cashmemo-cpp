#include "ShopDetails.h"

istream &operator>>(istream &in, ShopDetails &s)
{
    cout << "Enter Shop First Name : ";
    if (in.peek() == '\n' || in.peek() == ' ')
        in.ignore();
    getline(in, s.shopFirstName);
    cout << "Enter Shop Last Name : ";
    if (in.peek() == '\n' || in.peek() == ' ')
        in.ignore();
    getline(in, s.shopLastName);
    cout << "Enter Shop Description : ";
    if (in.peek() == '\n' || in.peek() == ' ')
        in.ignore();
    getline(in, s.ShopDescription);
    cout << "Shop's Owner Name" << endl;
    in >> s.signature;
    cout << "CellInfo " << endl;
    in >> s.cell;
    cout << "Address Info" << endl;
    in >> s.address;
    return in;
}

ostream &operator<<(ostream &out, ShopDetails &s)
{
    out << s.getShopFirstName() << " " << s.getShopLastName() << endl;
    out << s.getShopDescription() << endl;
    out << s.signature << endl;
    CellNumber c;
    c = s.getCell();
    out << c << endl;
    out << s.address << endl;
    return out;
}

// int main()
// {
//     ShopDetails s;
//     cin >> s;
//     cout << s;
//     return 0;
// }