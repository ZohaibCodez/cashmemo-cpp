#pragma once
#include "ShopDetails.h"
#include "ReceiptNo.h"
#include "Name.h"
#include "Date.h"
#include "Item.h"
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
        for (const auto& item : items)
        {
            total += item.getAmount();
        }
        return total;
    }
}; 