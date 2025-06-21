#include "Name.h"

istream &operator>>(istream &in, Name &name)
{
    string f, m, l;
    do
    {
        cout << "Enter first name: ";
        in >> f;
    } while (!name.isValidName(f));

    cout << "Enter middle name: (or '-' to skip)";
    in >> m;
    if (m == "-" || name.isValidName(m))
    {
        name.middle = (m == "-" ? "" : m);
    }

    do
    {
        cout << "Enter last name: ";
        in >> l;
    } while (!name.isValidName(l));

    name.first = f;
    name.last = l;
    return in;
}

ostream &operator<<(ostream &out, Name &name)
{
    if (name.middle != "")
        out << name.first << " " << name.middle << " " << name.last;
    else
        out << name.first << " " << name.last;
    return out;
}

// int main()
// {
//     Name n1;
//     cout << "Default name: " << n1 << endl;

//     Name n2("Muhammad", "Zohaib", "Khan");
//     cout << "Parameterized name: " << n2 << endl;

//     Name n3;
//     cin >> n3;
//     cout << "Entered name: " << n3 << endl;

//     return 0;
// }