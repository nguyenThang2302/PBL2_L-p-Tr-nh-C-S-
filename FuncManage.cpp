#include <bits/stdc++.h>
#include "FuncManage.h"
using namespace std;

void FuncManage::Func_Perform(FuncManage &f)
{
    menu(func_manage, 3);
    system("cls");
    if (choose == 1)
    {
        f.StaticticalDate(f);
        f.Back(f);
    }
    else if (choose == 2)
    {
        f.printStaticticalDate(f);
        f.Func_Perform(f);
    }
    else if (choose == 3)
    {
        cout << "Đăng Xuất Thành Công" << endl;
        // sleep(1.5);
        system("cls");
        Perform p;
        p.TruyCap(p);
    }
}

void FuncManage::StaticticalDate(FuncManage &f)
{
    char test[10]; // Bỏ qua các kí tự không cần thiết
    char check_1[10] = "Công:";
    char check_2[10] = "Tạo";
    char check_3[10] = "Việc:";
    char CaLam[3][20] = {"ca1_", "ca2_", "ca3_"};
    char duoiFile[5] = ".doc";
    char linkFile[3][100] = {"D:/Desktop/K21-K3/PBL2/Code/PBL2/Statistical/",
                             "D:/Desktop/K21-K3/PBL2/Code/PBL2/Statistical/",
                             "D:/Desktop/K21-K3/PBL2/Code/PBL2/Statistical/"};
    cout << "Nhập Ngày Tháng Năm Thống Kê(ddmmyy): ";
    cin >> f.time;
    strcat(f.time, duoiFile);
    for (int i = 0; i < 3; i++)
    {
        strcat(CaLam[i], f.time);
        strcat(linkFile[i], CaLam[i]);
        ifstream FILE;
        FILE.open(linkFile[i]);
        while (1)
        {
            FILE >> test;
            if (strcmp(test, check_1) == 0)
            {
                break;
            }
        }
        FILE >> f.totalBill[i];
        f.tempTotalBill += f.totalBill[i];
        while (1)
        {
            FILE >> test;
            if (strcmp(test, check_2) == 0)
            {
                break;
            }
        }
        for (; f.count < f.tempTotalBill; f.count++)
        {
            FILE >> f.STT[f.count];                 // OK
            FILE >> f.orderCode[f.count];           // OK
            FILE >> f.TotalAmountPerOrder[f.count]; // OK
            getline(FILE, f.Time[f.count]);         // OK
        }
        while (1)
        {
            FILE >> test;
            if (strcmp(test, check_3) == 0)
            {
                break;
            }
        }
        FILE >> f.totalMoney[i];
        f.tempTotalMoney += f.totalMoney[i];
    }
    system("cls");
    cout << endl
         << endl
         << endl;
    cout << "        Cửa Hàng Ăn Vặt: ITF" << endl;
    cout << "        Địa Chỉ: 56 Nguyễn Lương Bằng, Liên Chiểu, Đà Nẵng" << endl;
    cout << "        SĐT: 0363442302 - 0377884226" << endl;
    cout << endl;
    cout << "                         THỐNG KÊ HÓA ĐƠN TRONG NGÀY " << time << endl;
    cout << "   Tổng Số Hóa Đơn Xác Nhận Thành Công: " << f.tempTotalBill << endl;
    cout << left << setw(10) << "Số Thứ Tự"
         << "\t" << left << setw(10) << "Mã Đơn Hàng"
         << "\t" << left << setw(20) << "Tổng Tiền Đơn Hàng"
         << "\t" << left << setw(20) << "Thời Gian Tạo" << endl;
    for (int i = 0; i < f.count; i++)
    {
        cout << left << setw(10) << (i + 1)
             << "\t" << left << setw(10) << f.orderCode[i]
             << "\t" << left << setw(0) << f.TotalAmountPerOrder[i]
             << "\t" << left << setw(20) << f.Time[i] << endl;
    }
    cout << "   Tổng Doanh Thu Trong Ngày: " << f.tempTotalMoney << endl;
    cout << endl;
}

void FuncManage::Back(FuncManage &f)
{
    menu(back, 1);
    if (choose == 1)
    {
        system("cls");
        f.Func_Perform(f);
    }
}

void FuncManage::printStaticticalDate(FuncManage &f)
{
    ofstream StatisticalDate;
    char linkFile[60] = "D:/Desktop/K21-K3/PBL2/Code/PBL2/StaticticalDate/";
    strcat(linkFile, f.getTime());
    StatisticalDate.open(linkFile);
    StatisticalDate << "        Cửa Hàng Ăn Vặt: ITF" << endl;
    StatisticalDate << "        Địa Chỉ: 56 Nguyễn Lương Bằng, Liên Chiểu, Đà Nẵng" << endl;
    StatisticalDate << "        SĐT: 0363442302 - 0377884226" << endl;
    StatisticalDate << endl;
    StatisticalDate << "                         THỐNG KÊ HÓA ĐƠN ĐƠN HÀNG TRONG NGÀY " << f.getTime() << endl;
    StatisticalDate << "   Tổng Số Hóa Đơn Xác Nhận Thành Công: " << f.tempTotalBill << endl;
    StatisticalDate << left << setw(10) << "Số Thứ Tự"
                    << "\t" << left << setw(10) << "Mã Đơn Hàng"
                    << "\t" << left << setw(20) << "Tổng Tiền Đơn Hàng"
                    << "\t" << left << setw(20) << "Thời Gian Tạo" << endl;
    for (int i = 0; i < f.count; i++)
    {
        StatisticalDate << left << setw(10) << (i + 1)
                        << "\t" << left << setw(10) << f.orderCode[i]
                        << "\t" << left << setw(0) << f.TotalAmountPerOrder[i]
                        << "\t" << left << setw(20) << f.Time[i] << endl;
    }
    StatisticalDate << "   Tổng Doanh Thu Trong Ngày: " << f.tempTotalMoney << endl;
    StatisticalDate.close();
    cout << "       In Thành Công" << endl;
    // sleep(2);
}