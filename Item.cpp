#include <iostream>
#include <iomanip>
// #include <cstdlib>
using namespace std;

class Item
{
protected:
    int quantity;
    string particular;
    float rate;
    float amount;

public:
    // Constructors
    Item() : quantity(0), rate(0.0), amount(0.0) {};
    Item(int _quantity, string _particular, float _rate)
    {
        setQuantity(_quantity);
        setParticular(_particular);
        setRate(_rate);
    };
    // Getters
    int getQuantity() const { return quantity; }
    string getParticular() const { return particular; }
    float getRate() const { return rate; }
    float getAmount() const { return amount; }
    // Setters
    void setQuantity(int q)
    {
        while (q <= 0)
        {
            cout << "Invalid quantity! Enter again: ";
            cin >> q;
        }
        quantity = q;
        updateAmount();
    }
    void setParticular(string p)
    {
        while (p.empty())
        {
            cout << "Invalid name! Enter again: ";
            cin >> p;
        }
        particular = p;
    }
    void setRate(float r)
    {
        while (!(r > 0))
        {
            cout << "Invalid rate! Enter again: ";
            cin >> r;
        }
        rate = r;
        updateAmount();
    }
    void updateAmount() { amount = quantity * rate; }

    friend istream &operator>>(istream &in, Item &item);
    friend ostream &operator<<(ostream &out, Item &item);
};
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