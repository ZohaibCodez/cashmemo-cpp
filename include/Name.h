#pragma once
#include <iostream>
#include <string>

using namespace std;

class Name
{
protected:
    string first, middle, last;
    bool isValidName(const string &name)
    {
        if (name.empty())
            return false;
        for (char x : name)
        {
            if (!(x >= 'a' && x <= 'z') && !(x >= 'A' && x <= 'Z'))
                return false;
        }
        return true;
    }

public:
    // Constructors:
    Name() : first(""), middle(""), last("") {};
    Name(string _first, string _middle, string _last)
    {
        while (!isValidName(_first))
        {
            cout << "Invalid first name! Enter again: ";
            cin >> _first;
        }
        if (middle == "-" || !isValidName(_middle))
        {
            _middle = "";
        }
        while (!isValidName(_last))
        {
            cout << "Invalid _last name! Enter again: ";
            cin >> _last;
        }

        first = _first;
        middle = _middle;
        last = _last;
    }
    Name(string _first, string _last)
    {
        while (!isValidName(_first))
        {
            cout << "Invalid first name! Enter again: ";
            cin >> _first;
        }
        while (!isValidName(_last))
        {
            cout << "Invalid _last name! Enter again: ";
            cin >> _last;
        }

        first = _first;
        last = _last;
    }
    Name(const Name &other) : first(other.first), middle(other.middle), last(other.last) {};
    // Getters
    string getFirst() const { return first; }
    string getMiddle() const { return middle; }
    string getLast() const { return last; }
    // Setters
    void setFirst(const string &f)
    {
        if (isValidName(f))
            first = f;
        else
            cout << "Invalid First Name ." << endl;
    }
    void setMiddle(const string &m)
    {
        if (m == "-" || isValidName(m))
            middle = (m == "-" ? "" : m);
        else
            cout << "Invalid Middle Name ." << endl;
    }
    void setLast(const string &l)
    {
        if (isValidName(l))
            last = l;
        else
            cout << "Invalid Last Name ." << endl;
    }
    friend istream &operator>>(istream &in, Name &name);
    friend ostream &operator<<(ostream &out, Name &name);
}; 