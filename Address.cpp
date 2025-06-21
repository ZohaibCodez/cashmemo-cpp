#include <iostream>
using namespace std;

class Address
{
protected:
    string street;
    string city;
    string country;

public:
    // Constructors
    Address() : street("2"), city("Lahore"), country("Pakistan") {};
    Address(string _street, string _city, string _country) : street(_street), city(_city), country(_country) {};
    Address(const Address &other) : street(other.street), city(other.city), country(other.country) {};
    // Validations
    bool isStreet(string street)
    {
        for (char c : street)
        {
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }
    bool isCity(string city)
    {
        for (char c : city)
        {
            if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
                return false;
        }
        return true;
    }
    bool isCountry(string country)
    {
        for (char c : country)
        {
            if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
                return false;
        }
        return true;
    }
    // Getters
    string getStreet() const
    {
        return this->street;
    }
    string getCity() const
    {
        return this->city;
    }
    string getCountry() const
    {
        return this->country;
    }
    // Setters
    void setStreet(string _street)
    {
        while (!isStreet(_street))
        {
            cout << "Invalid Street Number. Enter again :  ";
            cin >> _street;
        }
        this->street = _street;
    }
    void setCity(string _city)
    {
        while (!isCity(_city))
        {
            cout << "Invalid City Name. Enter again :  ";
            cin >> _city;
        }
        this->city = _city;
    }
    void setCountry(string _country)
    {
        {
            while (!isCountry(_country))
            {
                cout << "Invalid Country Name. Enter again :  ";
                cin >> _country;
            }
            this->country = _country;
        }
    }
    friend istream &operator>>(istream &in, Address &addr);
    friend ostream &operator<<(ostream &out, Address &addr);
};
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