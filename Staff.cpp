#include <bits/stdc++.h>
#include <unistd.h>
#include "Staff.h"
#include "Order.cpp"
using namespace std;

void Staff::nvACCOUNT(Staff &s)
{
    ifstream nvACCOUNT;
    nvACCOUNT.open("D:/Desktop/K21-K3/PBL2/Code/PBL2/DataFile/ACNhanVien.txt");
    for (int i = 0; i < 5; i++)
    {
        nvACCOUNT >> s.nvUSERNAME[i];
        nvACCOUNT >> s.nvPASSWORD[i];
    }
}

void Staff::LoginNV(Staff &s)
{
    s.nvACCOUNT(s);
    int checkUSER = 3;
    int checkPASS = 3;
    while (1)
    {
        system("cls");
        int count = 0;
        fflush(stdin);
        cout << "Tên Tài Khoản: ";
        cin >> s.nvUSER[checkUSER];
        fflush(stdin);
        cout << "Mật Khẩu: ";
        cin >> s.nvPASS[checkPASS];
        for (int i = 0; i < 5; i++)
        {
            if (strcmp(s.nvUSER[checkUSER], s.nvUSERNAME[i]) == 0 && strcmp(s.nvPASS[checkPASS], s.nvPASSWORD[i]) == 0)
            {
                cout << "Đăng Nhập Thành Công" << endl;
                // sleep(3);
                system("cls");
                ListOrder List;
                List.FUNC_ORDER(List);
            }
            else
            {
                count++;
            }
        }
        if (count == 5)
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
}