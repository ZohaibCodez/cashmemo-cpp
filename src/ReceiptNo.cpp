#include <iostream>
#include "ReceiptNo.h"

using namespace std;

ostream &operator<<(ostream &out, const ReceiptNo &r)
{
    out << r.receiptNumber;
    return out;
}
int ReceiptNo::lastReceiptNo = 1000;
