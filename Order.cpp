#include <bits/stdc++.h>
#include "Order.h"
#include "menu.cpp"
using namespace std;

string ORDERCODE();
void RAND_TEXT(int length, char *result);
char *TIME();

istream &operator>>(istream &is, Order &O)
{
    int count = 0;
    O.Menu(O);
NHAPMONAN:
    cout << "          Nhập Mã Món Ăn & Số Lượng: ";
    is >> O.Item >> O.amount;
    for (int i = 0; i < O.y; i++)
    {
        if (O.Item == O.ItemFood[i])
        {
            O.moneytotal = O.amount * O.PriceFood[i];
            O.Name = O.NameFood[i];
            O.Price = O.PriceFood[i];
            count++;
        }
    }
    if (count == 0)
    {
        cout << "Lỗi Không Tồn Tại. Vui Lòng Nhập Lại" << endl;
        goto NHAPMONAN;
    }
    return is;
}

void Order::Menu(Order &O)
{
    ifstream menu;
    menu.open("D:/Desktop/K21-K3/PBL2/Code/PBL2/DataFile/ThucDon.txt");
    menu >> O.y;
    // cout << "\t";
    menu >> O.x;
    for (int i = 0; i < y; i++)
    {
        menu >> O.ItemFood[i];
        // cout << "\t\t";
        menu >> O.NameFood[i];
        // cout << "\t\t";
        menu >> O.PriceFood[i];
    }
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "_____________________________THỰC ĐƠN HÔM NAY CÓ MÓN_____________________________" << endl;
    cout << endl;
    cout << left << setw(30) << "MÃ MÓN ĂN"
         << "\t\t" << left << setw(20) << "TÊN MÓN ĂN"
         << "\t\t" << left << setw(20) << "ĐƠN GIÁ" << endl;
    cout << endl;
    for (int i = 0; i < y; i++)
    {
        cout << left << setw(30) << O.ItemFood[i] << "\t\t" << left << setw(20) << O.NameFood[i] << "\t\t" << left << setw(20) << O.PriceFood[i] << endl;
    }
}

void ListOrder::FUNC_ORDER(ListOrder &l)
{
    if (l.countCreate == 0)
    {
        l.tmpTime = TIME();
        l.timeStart = std::string(l.tmpTime);
    }
CHUCNANGORDER:
    menu(func_staff, 8);
    if (choose == 1)
    {
        l.ordercode[l.countCreate] = ORDERCODE();
        l.time = TIME();
        std::string tmp = std::string(l.time);
        l.totalTime[l.countCreate] = tmp;
        l.countCreate++;
        cin >> l;
    }
    else if (choose == 2)
    {
        l.AddFood(l);
    }
    else if (choose == 3)
    {
        l.DeleteFood(l);
    }
    else if (choose == 4)
    {
        l.EditFood(l);
    }
    else if (choose == 5)
    {
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        cout << l;
    ChucNangThanhToan:
        menu(options_confirm, 2);
        if (choose == 1)
        {
            system("cls");
            cout << "Xác Nhận Thành Công" << endl;
            l.confirmBill++;
            // l.moneyConfirm += l.totalMoney;
            l.PrintBill(l);
            sleep(1.5);
            system("cls");
            goto CHUCNANGORDER;
        }
        else if (choose == 2)
        {
            system("cls");
            l.FUNC_ORDER(l);
        }
    }
    else if (choose == 6)
    {
        system("cls");
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        l.Statistical(l);
        menu(options_printTK, 2);
        if (choose == 1)
        {
            l.PrintStatistical(l);
            cout << "       In Thống Kê Hoàn Tất" << endl;
            system("cls");
            goto CHUCNANGORDER;
        }
        else if (choose == 2)
        {
            system("cls");
            l.FUNC_ORDER(l);
        }
    }
    else if (choose == 7)
    {
        system("cls");
        menu(options_end, 2);
        if (choose == 1)
        {
            l.timeEnd = TIME();
            l.PrintShift(l);
            cout << "       Ca Làm Của Bạn Đã Được Ghi Nhận Vào Hệ Thống" << endl;
            // sleep(1.5);
            system("cls");
            Perform p;
            p.TruyCap(p);
        }
        else if (choose == 2)
        {
            system("cls");
            goto CHUCNANGORDER;
        }
    }
    else if (choose == 8)
    {
        cout << "Đăng Xuất Thành Công" << endl;
        // sleep(1.5);
        system("cls");
        Perform p;
        p.TruyCap(p);
    }
}

void ListOrder::Statistical(ListOrder &l)
{
    cout << "______________________________________________________________THỐNG KÊ HÓA ĐƠN______________________________________________________________" << endl;
    cout << endl;
    cout << "   Tổng Số Hóa Đơn Xác Nhận Thành Công: " << l.confirmBill << endl;
    cout << left << setw(30) << "Số Thứ Tự"
         << "\t" << left << setw(30) << "Mã Đơn Hàng"
         << "\t" << left << setw(30) << "Tổng Tiền Đơn Hàng"
         << "\t" << left << setw(30) << "Thời Gian Tạo Đơn" << endl;
    for (int i = 0; i < l.confirmBill; i++)
    {
        cout << left << setw(30) << (i + 1)
             << "\t" << left << setw(30) << l.ordercode[i]
             << "\t" << left << setw(30) << l.billtotal[i]
             << "\t" << left << setw(30) << l.totalTime[i] << endl;
    }
    cout << "   Tổng Doanh Thu Ca Làm Việc: " << l.totalMoney << endl;
    cout << "_____________________________________________________________________________________________________________________________________________" << endl;
}

void ListOrder::EditFood(ListOrder &l)
{
    int count = 0;
    int EditFood;
    int EditAmount;
    int EditMoneyTotal;
    cout << l;
    while (1)
    {
    CHINHSUAMONAN:
        cout << "Nhập Item Món Ăn Muốn Chỉnh Sửa (hoặc 0 Để Quay Lại): ";
        cin >> EditFood;
        if (EditFood == 0)
        {
            system("cls");
            l.FUNC_ORDER(l);
        }
        else
        {
            for (int i = 0; i < l.FoodTotal; i++)
            {
                if (EditFood == l.ptrOder[i].getItem())
                {
                    count++;
                    cout << "   Nhập Số Lượng Món Ăn Muốn Thay Đổi: ";
                    cin >> EditAmount;
                    EditMoneyTotal = EditAmount * l.ptrOder[i].getPriceFood(EditFood);
                    l.ptrOder[i].setAmount(EditAmount);
                    l.ptrOder[i].setMoneyTotal(EditMoneyTotal);
                }
            }
            if (count == 0)
            {
                cout << "Lỗi Không Tồn Tại. Vui Lòng Nhập Lại" << endl;
                goto CHINHSUAMONAN;
            }
            else
            {
                cout << "  Chỉnh Sửa Thành Công" << endl;
            }
        }
    }
}

void ListOrder::DeleteFood(ListOrder &l)
{
    int count = 0;
    int DeleleItem;
    cout << l;
    while (1)
    {
    XOAMONAN:
        cout << "   Chọn Item Món Ăn Mà Bạn Muốn Hủy (hoặc 0 Để Quay Lại): ";
        cin >> DeleleItem;
        if (DeleleItem == 0)
        {
            system("cls");
            l.FUNC_ORDER(l);
        }
        else
        {
            for (int i = 0; i < l.FoodTotal; i++)
            {
                if (DeleleItem == l.ptrOder[i].getItem())
                {
                    count++;
                    // Vi Tri Xoa = j;
                    for (int j = i; j < l.FoodTotal; j++)
                    {
                        l.ptrOder[j] = l.ptrOder[j + 1];
                    }
                    l.FoodTotal--;
                }
            }
            if (count == 0)
            {
                cout << "Lỗi Không Tồn Tại. Vui Lòng Nhập Lại" << endl;
            }
            else
            {
                cout << "   Đã Hủy Item: " << DeleleItem << endl;
            }
        }
    }
}

void ListOrder::AddFood(ListOrder &l)
{
    Order AddOrder;
    int choiceAdd;
ChucNangThem:
    cin >> AddOrder;
    l.FoodTotal = l.FoodTotal + 1;
    l.ptrOder[l.FoodTotal - 1] = AddOrder;
    menu(options, 2);
    if (choose == 1)
    {
        goto ChucNangThem;
    }
    else if (choose == 2)
    {
        l.FUNC_ORDER(l);
    }
}

istream &operator>>(istream &is, ListOrder &l)
{
    l.FoodTotal = 0;
    l.n = 100;
    int choiceNhap;
    l.ptrOder = new Order[l.n];
    cout << endl;
ChucNangNhap:
    is >> l.ptrOder[l.FoodTotal];
    l.FoodTotal++;
    menu(options, 2);
    while (1)
    {
        system("cls");
        if (choose == 1)
        {
            // is >> l.ptrOder[l.FoodTotal];
            // l.FoodTotal++;
            goto ChucNangNhap;
        }
        if (choose == 2)
        {
            l.FUNC_ORDER(l);
        }
    }
    return is;
}

ostream &operator<<(ostream &os, ListOrder &l)
{
    l.totalMoney = 0;
    l.billtotal[l.countCreate - 1] = 0;
    os << "        Cửa Hàng Ăn Vặt: ITF" << endl;
    os << "        Địa Chỉ: 56 Nguyễn Lương Bằng, Liên Chiểu, Đà Nẵng" << endl;
    os << "        SĐT: 0363442302 - 0377884226" << endl;
    os << endl;
    os << "                                                     HÓA ĐƠN THANH TOÁN ĐƠN HÀNG                                                        " << endl;
    os << "        Mã Đơn Hàng: " << l.ordercode[l.countCreate - 1] << endl;
    os << "        Thời Gian Tạo Đơn: " << l.time << endl;
    os << left << setw(30) << "Item"
       << "\t"
       << left << setw(30) << "Tên Món"
       << "\t"
       << left << setw(30) << "Đơn Giá"
       << "\t"
       << left << setw(30) << "Số Lượng"
       << "\t"
       << left << setw(30) << "Thành Tiền" << endl;
    for (int i = 0; i < l.FoodTotal; i++)
    {
        os << left << setw(30) << l.ptrOder[i].getItem() // OK
           << "\t"
           << left << setw(30) << l.ptrOder[i].getName() // OK
           << "\t"
           << left << setw(30) << l.ptrOder[i].getPrice() // OK
           << "\t"
           << left << setw(30) << l.ptrOder[i].getAmount() // OK
           << "\t"
           << left << setw(30) << l.ptrOder[i].getMoneyTotal() << endl; // OK
        l.billtotal[l.countCreate - 1] += l.ptrOder[i].getMoneyTotal();
    }
    for (int i = 0; i < l.confirmBill + 1; i++)
    {
        l.totalMoney += l.billtotal[i];
    }
    cout << "_________________________________________________" << endl;
    cout << "        Thành Tiền        : " << l.billtotal[l.countCreate - 1] << " VNĐ" << endl;
    cout << "        Phí Dịch Vụ:      : " << 0 << endl;
    cout << "        VAT               : " << 0 << endl;
    cout << "_________________________________________________" << endl;
    cout << "        Tổng Tiền Đơn Hàng: " << l.billtotal[l.countCreate - 1] << " VNĐ" << endl;
    os << "                                                      Cám Ơn Quý Khách. Hẹn Gặp Lại!                                                   " << endl;
    os << "_______________________________________________________________________________________________________________________________________" << endl;
    return os;
}

void ListOrder::PrintBill(ListOrder &l)
{
    ofstream bill;
    char linkFile[60] = "D:/Desktop/K21-K3/PBL2/Code/PBL2/Bill/";
    std::string str(l.ordercode[l.countCreate - 1]);
    char *tenFile = new char[str.length()];
    strcpy(tenFile, str.c_str());
    char duoiFile[5] = ".doc";
    strcat(tenFile, duoiFile);
    strcat(linkFile, tenFile);
    bill.open(linkFile);
    l.billtotal[l.countCreate - 1] = 0;
    bill << "        Cửa Hàng Ăn Vặt: ITF" << endl;
    bill << "        Địa Chỉ: 56 Nguyễn Lương Bằng, Liên Chiểu, Đà Nẵng" << endl;
    bill << "        SĐT: 0363442302 - 0377884226" << endl;
    bill << endl;
    bill << "                         HÓA ĐƠN THANH TOÁN ĐƠN HÀNG" << endl;
    bill << "        Mã Đơn Hàng: " << l.ordercode[l.countCreate - 1] << endl;
    bill << "        Thời Gian Tạo Đơn: " << l.time << endl;
    bill << left << setw(10) << "Item"
         << "\t"
         << left << setw(20) << "Tên Món"
         << "\t"
         << left << setw(10) << "Đơn Giá"
         << "\t"
         << left << setw(10) << "Số Lượng"
         << "\t"
         << left << setw(10) << "Thành Tiền" << endl;
    for (int i = 0; i < l.FoodTotal; i++)
    {
        bill << left << setw(10) << l.ptrOder[i].getItem() // OK
             << "\t"
             << left << setw(20) << l.ptrOder[i].getName() // OK
             << "\t"
             << left << setw(10) << l.ptrOder[i].getPrice() // OK
             << "\t"
             << left << setw(10) << l.ptrOder[i].getAmount() // OK
             << "\t"
             << left << setw(10) << l.ptrOder[i].getMoneyTotal() << endl; // OK
        l.billtotal[l.countCreate - 1] += l.ptrOder[i].getMoneyTotal();
    }
    bill << "_________________________________________________" << endl;
    bill << "        Thành Tiền        : " << l.billtotal[l.countCreate - 1] << " VNĐ" << endl;
    bill << "        Phí Dịch Vụ:      : " << 0 << endl;
    bill << "        VAT               : " << 0 << endl;
    bill << "_________________________________________________" << endl;
    bill << "        Tổng Tiền Đơn Hàng: " << l.billtotal[l.countCreate - 1] << " VNĐ" << endl;
    bill << "                         Cám Ơn Quý Khách. Hẹn Gặp Lại!" << endl;
}

void ListOrder::PrintStatistical(ListOrder &l)
{
    ofstream Statistical;
    char linkFile[60] = "D:/Desktop/K21-K3/PBL2/Code/PBL2/Statistical/";
    char tenFile[10];
    cout << "Tên File Thống Kê (CaLàm_NgàyThángNăm <=> Ví du: ca1_19112022): ";
    cin >> tenFile;
    char duoiFile[5] = ".doc";
    strcat(tenFile, duoiFile);
    strcat(linkFile, tenFile);
    Statistical.open(linkFile);
    Statistical << "        Cửa Hàng Ăn Vặt: ITF" << endl;
    Statistical << "        Địa Chỉ: 56 Nguyễn Lương Bằng, Liên Chiểu, Đà Nẵng" << endl;
    Statistical << "        SĐT: 0363442302 - 0377884226" << endl;
    Statistical << endl;
    Statistical << "                         THỐNG KÊ HÓA ĐƠN ĐƠN HÀNG" << endl;
    Statistical << "   Tổng Số Hóa Đơn Xác Nhận Thành Công: " << l.confirmBill << endl;
    Statistical << left << setw(10) << "Số Thứ Tự"
                << "\t" << left << setw(10) << "Mã Đơn Hàng"
                << "\t" << left << setw(20) << "Tổng Tiền Đơn Hàng"
                << "\t" << left << setw(20) << "Thời Gian Tạo" << endl;
    for (int i = 0; i < l.confirmBill; i++)
    {
        Statistical << left << setw(10) << (i + 1)
                    << "\t" << left << setw(10) << l.ordercode[i]
                    << "\t" << left << setw(20) << l.billtotal[i]
                    << "\t" << left << setw(20) << l.totalTime[i];
    }
    Statistical << "   Tổng Doanh Thu Ca Làm Việc: " << l.totalMoney << endl;
}

void ListOrder::PrintShift(ListOrder &l)
{
    ofstream Shift;
    char linkFile[60] = "D:/Desktop/K21-K3/PBL2/Code/PBL2/Shift/";
    char tenFile[10];
    cout << "Nhập Mã Nhân Viên Để Xác Nhận: ";
    cin >> tenFile;
    char duoiFile[5] = ".doc";
    strcat(tenFile, duoiFile);
    strcat(linkFile, tenFile);
    Shift.open(linkFile);
    Shift << "        Cửa Hàng Ăn Vặt: ITF" << endl;
    Shift << "        Địa Chỉ: 56 Nguyễn Lương Bằng, Liên Chiểu, Đà Nẵng" << endl;
    Shift << "        SĐT: 0363442302 - 0377884226" << endl;
    Shift << endl;
    Shift << "                         THỐNG KÊ CA LÀM VIỆC" << endl;
    Shift << "   Mã Nhân Viên:                        " << tenFile << endl;
    Shift << "   Tổng Số Hóa Đơn Xác Nhận Thành Công: " << l.confirmBill << endl;
    Shift << "   Thời Gian Bắt Đầu Ca Làm Viêc:       " << l.timeStart << endl;
    Shift << "   Thời Gian Kết Thúc Ca Làm Việc:      " << l.timeEnd << endl;
    Shift << "   Tổng Doanh Thu Ca Làm Việc: " << l.totalMoney << endl;
}

void RAND_TEXT(int length, char *result)
{
    int i, rand_int;
    char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz&quot";
    for (int i = 0; i < length; i++)
    {
        result[i] = char_set[rand() % sizeof(char_set)];
    }
    result[length] = 0;
}

string ORDERCODE()
{
    int length = 6;
    char result[length + 1];
    srand(time(NULL));
    RAND_TEXT(length, result);
    return result;
}

char *TIME()
{
    time_t now = time(0);
    char *dt = ctime(&now);
    return dt;
}