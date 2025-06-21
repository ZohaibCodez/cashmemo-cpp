#include "Address.h"

istream &operator>>(istream &in, Address &addr)
{
    cout << "Street No : ";
    in >> addr.street;
    addr.setStreet(addr.street);
    cout << "City : ";
    in >> addr.city;
    addr.setCity(addr.city);
    cout << "Country : ";
    in >> addr.country;
    addr.setCountry(addr.country);
    return in;
}
ostream &operator<<(ostream &out, Address &addr)
{
    out << "Street # " << addr.street << ", " << addr.city << ", " << addr.country << endl;
    return out;
}