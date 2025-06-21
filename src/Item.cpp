#include "Item.h"

istream &operator>>(istream &in, Item &item)
{
    cout << "Enter particular: ";
    in.ignore();
    getline(in, item.particular);
    item.setParticular(item.particular);
    cout << "Enter quantity: ";
    in >> item.quantity;
    item.setQuantity(item.quantity);
    cout << "Enter rate: ";
    in >> item.rate;
    item.setRate(item.rate);
    item.updateAmount();
    return in;
}
ostream &operator<<(ostream &out, Item &item)
{
    out << setw(8) << item.quantity
        << setw(20) << item.particular
        << setw(10) << fixed << setprecision(2) << item.rate
        << setw(12) << item.amount << endl;
    return out;
}

// int main()
// {
//     Item i1;
//     cin >> i1;
//     cout << i1;
//     Item i2;
//     cin >> i2;
//     cout << i2;
// }