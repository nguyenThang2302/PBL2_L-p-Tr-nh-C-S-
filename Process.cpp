#include <bits/stdc++.h>
#include "Process.h"
#include "Perform.cpp"
#include "Present.cpp"
#include "Introduce.cpp"
using namespace std;

void Process::process()
{
    system("cls");
    Present present;
    // present.ABOUT_INFORMATION();
    cout << "Nhấn Phím Bất Kì Để Bắt Đầu Chương Trình" << endl;
    system("pause");
    system("cls");
    Introduce introduce;
    // introduce.Run_Introduce(introduce);
    // sleep(3);
    system("cls");
    Perform p;
    p.TruyCap(p);
}