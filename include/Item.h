#pragma once
#include <iostream>
#include <iomanip>
#include <string>

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