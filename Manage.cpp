#include <bits/stdc++.h>
#include <unistd.h>
#include "Manage.h"
#include "FuncManage.h"
#include "FuncManage.cpp"
using namespace std;

void Manage::qlACCOUNT(Manage &m)
{
    ifstream qlACCOUNT;
    qlACCOUNT.open("D:/Desktop/K21-K3/PBL2/Code/PBL2/DataFile/ACQuanLy.txt");
    for (int i = 0; i < 2; i++)
    {
        qlACCOUNT >> m.qlUSERNAME[i];
        qlACCOUNT >> m.qlPASSWORD[i];
    }
}

void Manage::LoginQL(Manage &m)
{
    m.qlACCOUNT(m);
    int checkUSER = 3;
    int checkPASS = 3;
    int check = 1;
    while (check)
    {
        system("cls");
        int count = 0;
        fflush(stdin);
        cout << "Tên Tài Khoản: ";
        cin >> m.qlUSER[checkUSER];
        fflush(stdin);
        cout << "Mật Khẩu: ";
        cin >> m.qlPASS[checkPASS];
        for (int i = 0; i < 2; i++)
        {
            if (strcmp(m.qlUSER[checkUSER], m.qlUSERNAME[i]) == 0 && strcmp(m.qlPASS[checkPASS], m.qlPASSWORD[i]) == 0)
            {
                cout << "Đăng Nhập Thành Công" << endl;
                // sleep(3);
                system("cls");
                goto FUNCMANAGE;
                break;
            }
            else
            {
                count++;
            }
        }
        if (count == 2)
        {
            cout << "Đăng Nhập Thất Bại" << endl;
            checkUSER--;
            checkPASS--;
            cout << "Bạn Còn " << checkUSER << " lượt đăng nhập" << endl;
            // sleep(2);
        }
        if (checkUSER == 0)
        {
            system("cls");
            cout << "Truy Cập Bị Chặn" << endl;
            break;
        }
    }
FUNCMANAGE:
    FuncManage f;
    f.Func_Perform(f);
}