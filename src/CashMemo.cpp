#include "CashMemo.h"

istream &operator>>(istream &in, CashMemo &c)
{
    cout << setw(30) << "SHOP DETAILS" << endl;
    cout << endl;
    in >> c.details;

    // cout << "Enter Date (DD MM YYYY):\n";
    in >> c.date;

    // cout << "Enter Customer Name:\n";
    cout << setw(30) << "CUSTOMER'S INFO" << endl;
    in >> c.name;
    cout << endl;

    cout << "Enter 2 Items:\n";
    for (Item &item : c.items)
    {
        in >> item;
    }

    return in;
}

ostream &operator<<(ostream &out, CashMemo &c)
{
    out << "------------------------------------------------------\n";
    out << setw(30) << c.details.getShopFirstName() << endl;
    out << setw(30) << c.details.getShopLastName() << endl;
    out << "------------------------------------------------------\n";
    out << setw(20) << c.details.getShopDescription() << endl;
    CellNumber cl = c.details.getCell();
    out << setw(25) << "Cell : " << cl << endl;
    out << endl;

    out << "No: " << c.no << setw(40) << "Date: " << c.date << "\n";
    out << "Name: " << c.name << "\n\n";

    out << "------------------------------------------------------\n";
    out << setw(8) << "Qty" << setw(20) << "Particulars" << setw(10) << "Rate" << setw(12) << "Amount\n";
    out << "------------------------------------------------------\n";

    for (Item item : c.items)
    {
        out << item;
    }

    out << "------------------------------------------------------\n";
    out << setw(48) << "Total: " << c.calculateTotal() << "\n";
    out << "------------------------------------------------------\n";
    Name signature = c.details.getSignature();
    out << "Signature: " << signature << endl;
    Address adr = c.details.getAddress();
    out << "Address : " << adr << endl;

    return out;
}
