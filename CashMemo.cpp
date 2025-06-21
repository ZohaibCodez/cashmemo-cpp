#include "ShopDetails.cpp"
#include "ReceiptNo.cpp"
#include "Name.cpp"
#include "Date.cpp"
#include "Item.cpp"

#include <array>
using namespace std;

class CashMemo
{
protected:
    ShopDetails details;
    ReceiptNo no;
    Date date;
    Name name;
    array<Item, 2> items;

public:
    // Conatructors
    CashMemo() {};
    CashMemo(const ShopDetails &_details, const Date &_date, const Name &_name, const array<Item, 2> &_items) : details(_details), date(_date), name(_name), items(_items) {};
    CashMemo(const CashMemo &other) : details(other.details), no(other.no), date(other.date), items(other.items) {};

    friend istream &operator>>(istream &in, CashMemo &c);
    friend ostream &operator<<(ostream &out, CashMemo &c);

    float calculateTotal() const
    {
        float total = 0;
        for (Item item : items)
        {
            total += item.getAmount();
        }
        return total;
    }
};

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

// int main()
// {
//     CashMemo c;
//     cin >> c;
//     cout << c << endl;
//     return 0;
// }
