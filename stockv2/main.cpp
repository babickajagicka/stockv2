#include <iostream>
#include "stock1.h"

using namespace std;

const int STKS = 4;

int main()
{
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);

// create an array of initialized object
    Stock stocks[STKS] =
    {
        Stock("nanosmart", 12, 20.0),
        Stock("bofoo objects", 200, 2.0),
        Stock("monolithic obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout << " Drzitel akcii: " << endl;
    int st;
    for (st = 0; st < STKS; st++)
        stocks[st].show();


    Stock top = stocks[0];
    for (st = 1; st < STKS; st++)
        top = top.topval(stocks[st]);
    cout << "\nNejvetsi akcionar:\n";
    top.show();

    return 0;
}