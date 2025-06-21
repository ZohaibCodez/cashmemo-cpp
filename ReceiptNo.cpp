#include <iostream>
using namespace std;


class ReceiptNo
{
protected:
    int receiptNumber;
    static int lastReceiptNo;

public:
    // Constructors
    ReceiptNo()
    {
        receiptNumber = ++lastReceiptNo;
    };
    ReceiptNo(const ReceiptNo &other) : receiptNumber(other.receiptNumber) {};
    // Getters
    int getReceiptNumber() const
    {
        return this->receiptNumber;
    }
    friend ostream &operator<<(ostream &out, const ReceiptNo &r);
};
ostream &operator<<(ostream &out, const ReceiptNo &r)
{
    out << r.receiptNumber;
    return out;
}
int ReceiptNo::lastReceiptNo = 1000;