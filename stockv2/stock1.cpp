#include <iostream>
#include "stock1.h"

using namespace std;

//konstruktor
Stock::Stock()
{
    cout << "volani implicitniho konstruktoru" << endl;
    strncpy_s(company, "bezejmenna", 29);
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char* co, int n, double pr)
{
    cout << "volani konstruktoru s pouzitim " << co << endl;
    strncpy_s(company, co, 29); // zkraceni co podle compaany
    company[29] = '\0';
    if (n < 0)
    {
        cerr << "pocet akcii nemuze byt zaporny: " << company << " nastaveni shares a 0." << endl;
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    cout << "nashledanou,  " << company << "!" << endl;
}

void Stock::buy(int num, double price)
{
    if (num < 0)
    {
        cerr << "pocet akcii nemuze byt zaporny. transkace ukoncena." << endl;
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price)
{
    cerr;
    if (num < 0)
    {
        cerr << "pocet akcii nemuze byt zaporny. transakce ukoncena" << endl;
    }
    else if (num > shares)
    {
        cerr << "nemuzete prodat vic akcii nez mate. transakce ukoncena" << endl;
    }
    else
    {
        shares = shares - num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    cout << "Firma: " << company << endl << "Akcie: " << shares << endl;
    cout << "Cena akcie: " << share_val << endl;
    cout << "Celkova cena: " << total_val << endl;
}

const Stock& Stock::topval(const Stock& s)const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}