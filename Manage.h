#ifndef Manage_h
#define Manage_h
#define SL 3
#include <bits/stdc++.h>
using namespace std;
class Manage
{
private:
    char qlUSERNAME[SL][50];
    char qlPASSWORD[SL][50];
    char qlUSER[SL][50];
    char qlPASS[SL][50];

public:
    void qlACCOUNT(Manage &m);
    void LoginQL(Manage &m);
};
#endif