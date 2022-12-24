#include <bits/stdc++.h>
#include "mylib.h"
#include <conio.h>
#include <string.h>
using namespace std;
int xx = 0, yy = 0, choose = 0;
void box(int xx, int yy, int w, int h, int t_color, int b_color, char content[][90], int idx);
void boxes(int xx, int yy, int w, int h, int t_color, int b_color, char content[][90], int count);
void menu(char content[][90], int count);
void thanh_sang(int xx, int yy, int w, int h, int b_color, char content[][90], int idx);
int arrChoose[10];
int checkProcess = 0;
char Accsess[][90] = {
    "1. Đăng Nhập Nhân Viên",
    "2. Đăng Nhập Quản Lí",
    "3. Thoát"};
char func_staff[][90] = {
    "1. TẠO MỚI ĐƠN HÀNG",
    "2. THÊM MÓN ĂN ",
    "3. HỦY MÓN ĂN",
    "4. CHỈNH SỬA SỐ LƯỢNG MÓN ĂN",
    "5. XEM VÀ XÁC NHẬN HÓA ĐƠN",
    "6. THỐNG KÊ ĐƠN HÀNG",
    "7. KẾT THÚC CA LÀM VIỆC",
    "8. ĐĂNG XUẤT TÀI KHOẢN "};
char func_manage[][90] = {
    "1. THỐNG KÊ TRONG NGÀY",
    "2. In THỐNG KÊ TRONG NGÀY",
    "3. ĐĂNG XUẤT TÀI KHOẢN"};
char back[][90] = {
    "1. Quay Lại"};
char options[][90] = {
    "1. Tiếp Tục",
    "2. Quay Lại"};
char options_printTK[][90] = {
    "1. Tiếp tục",
    "2. Quay Lại"};
char options_confirm[][90] = {
    "1. Xác Nhận Đơn Hàng",
    "2. Quay Lại"};
char options_end[][90] = {
    "1. Xác Nhận Kết Thúc",
    "2. Quay Lại"};
void print(int idx, char content[][90])
{
    cout << content[idx];
}
int getChoose(int choose)
{
    return choose;
}
void menu(char content[][90], int count)
{
    ShowCur(0);
    int w = 30;
    int h = 2;
    int t_color = 11;
    int b_color = 1;
    int b_color_sang = 75;
    for (int i = 0; i < count; i++)
    {
        boxes(xx, yy, w, h, t_color, b_color, content, count);
    }
    int xp = xx;
    int yp = yy; // toạ độ thanh sáng
    bool kt = true;
    int xcu = xp, ycu = yp;
    while (true)
    {

        // in
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, content, (ycu - yy) / 2);
            xcu = xp;
            ycu = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, content, (yp - yy) / 2);
            kt = false;
        }
        // ddieeu khien di chuyen
        if (_kbhit())
        {
            char c = _getch();
            if (c == 72)
            {
                kt = true;
                if (yp != yy)
                    yp -= 2;
                else
                    yp = yy + h * (count - 1);
            }
            else if (c == 80)
            {
                kt = true;
                if (yp != yy + h * (count - 1))
                    yp += 2;
                else
                    yp = yy;
            }
            else if (c == 13)
            {
                textcolor(3);
                choose = (yp - yy) / 2 + 1;
                system("cls");
                return;
            }
        }
    }
}
void thanh_sang(int xx, int yy, int w, int h, int b_color, char content[][90], int idx)
{
    textcolor(b_color);
    for (int i = yy + 1; i <= yy + h - 1; i++)
    {
        for (int j = xx + 1; j <= xx + w - 1; j++)
        {
            gotoXY(j, i);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(xx + 1, yy + 1);
    print(idx, content);
}
void box(int xx, int yy, int w, int h, int t_color, int b_color, char content[][90], int idx)
{
    textcolor(b_color);
    for (int i = yy + 1; i <= yy + h - 1; i++)
    {
        for (int j = xx + 1; j <= xx + w - 1; j++)
        {
            gotoXY(j, i);
            cout << " ";
        }
    }
    SetColor(7);
    gotoXY(xx + 1, yy + 1);
    // cout << content;
    print(idx, content);
    textcolor(3);
    SetColor(t_color);

    if (h == 1 || w <= 1)
        return;
    for (int i = xx; i <= xx + w; i++)
    {
        gotoXY(i, yy);
        cout << "─";
        gotoXY(i, yy + h);
        cout << "─";
    }
    for (int i = yy; i <= yy + h; i++)
    {
        gotoXY(xx, i);
        cout << "│";
        gotoXY(xx + w, i);
        cout << "│";
    }
    gotoXY(xx, yy);
    cout << "┌";
    gotoXY(xx + w, yy);
    cout << "┐";
    gotoXY(xx, yy + h);
    cout << "└";
    gotoXY(xx + w, yy + h);
    cout << "┘";
    gotoXY(xx, yy + h);
    cout << endl;
}
void boxes(int xx, int yy, int w, int h, int t_color, int b_color, char content[][90], int count)
{
    for (int i = 0; i < count; i++)
    {
        box(xx, yy + i * 2, w, h, 11, 1, content, i);
        if (i != 0)
        {
            gotoXY(xx, yy + i * 2);
            cout << "├";
            gotoXY(xx + w, yy + i * 2);
            cout << "┤";
        }
    }
}
