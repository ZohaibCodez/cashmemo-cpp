#pragma once
#include <iostream>
#include <string>

using namespace std;

class CellNumber
{
protected:
    string countryCode;
    string no;

public:
    // Constructors
    CellNumber() : countryCode("92"), no("3210777102") {};
    CellNumber(string _countryCode, string _no) : countryCode(_countryCode), no(_no) {};
    // Validations
    bool isValidCountryCode(const string &code)
    {
        if (code.length() < 1 || code.length() > 3)
            return false;
        for (char c : code)
        {
            if (c < '0' || c > '9')
                return false;
        }
        return true;
    }
    bool isValidCountryNumber(const string &number)
    {
        for (char c : number)
        {
            if (c < '0' || c > '9')
                return false;
        }
        if (number.length() <= 9 || number.length() >= 15)
            return false;
        return true;
    }
    // Getters
    string getCountryCode() const
    {
        return this->countryCode;
    }
    string getNo() const
    {
        return this->no;
    }
    // Setters
    void setCountryCode(string _countryCode)
    {
        while (!isValidCountryCode(_countryCode))
        {
            cout << "Invalid Country code. Enter again : ";
            cin >> _countryCode;
        }
        this->countryCode = _countryCode;
    }
    void setNo(string _no)
    {
        while (!isValidCountryNumber(_no))
        {
            cout << "Invalid Number. Enter Again : ";
            cin >> _no;
        }
        this->no = _no;
    }
    // Operator Overloading
    friend istream &operator>>(istream &in, CellNumber &c);
    friend ostream &operator<<(ostream &out, CellNumber &c);
}; 