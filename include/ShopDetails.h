#pragma once
#include <iostream>
#include <string>
#include "Address.h"
#include "Name.h"
#include "CellNumber.h"

using namespace std;

class ShopDetails
{
protected:
    string shopFirstName;
    string shopLastName;
    string ShopDescription;
    CellNumber cell;
    Address address;
    Name signature;

public:
    // Constructors
    ShopDetails() : shopFirstName("MOBILO"), shopLastName("MOBILE CITY"), ShopDescription("DEALS IN ALL KINDS OF MOBILE SETS & ACCESSORIES"), cell(CellNumber("92", "3210777102")), address(Address("2", "Lahore", "Pakistan")), signature(Name("Shop", "Owner")) {};
    // Getters
    string getShopFirstName() const
    {
        return this->shopFirstName;
    }
    string getShopLastName() const
    {
        return this->shopLastName;
    }
    string getShopDescription() const
    {
        return this->ShopDescription;
    }
    CellNumber getCell() const
    {
        return this->cell;
    }
    Address getAddress() const
    {
        return this->address;
    }
    Name getSignature() const
    {
        return this->signature;
    }
    // Setters
    void setShopFirstName(string name)
    {
        this->shopFirstName = name;
    }
    void setShopLastName(string name)
    {
        this->shopLastName = name;
    }
    void setShopMotto(string motto)
    {
        this->ShopDescription = motto;
    }
    void setCellNumber(CellNumber cell)
    {
        this->cell = cell;
    }
    void setAddress(Address address)
    {
        this->address = address;
    }
    void setSignature(Name _signature)
    {
        this->signature = _signature;
    }
    friend istream &operator>>(istream &in, ShopDetails &s);
    friend ostream &operator<<(ostream &out, ShopDetails &s);
}; 