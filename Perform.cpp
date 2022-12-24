#include <bits/stdc++.h>
#include "Perform.h"
#include "Staff.cpp"
#include "Manage.cpp"
using namespace std;

void Perform::TruyCap(Perform &p)
{
    menu(Accsess, 3);
    if (choose == 1)
    {
        Staff s;
        s.LoginNV(s);
    }
    else if (choose == 2)
    {
        Manage m;
        m.LoginQL(m);
    }
    else if (choose == 3)
    {
    }
}