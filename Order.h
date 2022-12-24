#ifndef Order_h
#define Order_h
#include <bits/stdc++.h>
using namespace std;
class Order : public Staff
{
private:
    int ItemFood[101];  // mã món ăn từ file
    int Item;           // mã món ăn từ người dùng chọn
    int amount;         // số lượng món ăn từ người dùng chọn
    int PriceFood[101]; // giá mỗi món ăn rừ file
    int Price;
    char NameFood[101][50]; // Tên món ăn từ file
    string Name;
    int moneytotal; // tổng tiền mỗi món ăn
    int y, x;

public:
    Order()
    {
    }
    int getItem()
    {
        return Item;
    }
    void setItem(int Item)
    {
        this->Item = Item;
    }
    int getPriceFood(int i)
    {
        return PriceFood[i - 1];
    }
    string getName()
    {
        return Name;
    }
    void setName(string Name)
    {
        this->Name = Name;
    }
    int getPrice()
    {
        return Price;
    }
    void setPrice(int Price)
    {
        this->Price = Price;
    }
    int getAmount()
    {
        return amount;
    }
    void setAmount(int amount)
    {
        this->amount = amount;
    }
    int getMoneyTotal()
    {
        return moneytotal;
    }
    void setMoneyTotal(int moneytotal)
    {
        this->moneytotal = moneytotal;
    }
    int getY()
    {
        return y;
    }
    void setY(int y)
    {
        this->y = y;
    }
    // Khai báo nguyên mãu hàm của lớp ORDER
    friend istream &operator>>(istream &is, Order &O); // Nhập Món Ăn
    friend ostream &operator<<(ostream &os, Order &O); // Xuất Món Ăn
    void Menu(Order &O);                               // Hàm Đọc Menu Từ File
    int MoneyTotal(Order &O);
};
class ListOrder : public Order
{
private:
    int n;
    int countCreate;       // Tổng Số Đơn Hàng Được Tạo
    int FoodTotal;         // Tổng Số Lần Nhập Món
    int billtotal[101];    // Tổng Tiền Mỗi Đơn Hàng
    int totalMoney;        // Tổng Tiền Tất Cả Hóa Đơn
    string ordercode[101]; // Thống Kê Mã Đơn Hàng
    string totalTime[101]; // Thống Kê Thời Gian Tạo Đơn
    Order *ptrOder;        // Con Trỏ Order
    char *time;            // Lấy Thời Gian Lúc Tạo Đơn
    char *timeEnd;         // Thời Gian Nhân Viên Kết Thúc Ca Làm Việc
    char *tmpTime;         // Thời Gian Trung Gian
    string timeStart;      // Thời Gian Nhân Viên Bắt Đầu Ca Làm Việc
    int confirmBill;       // Số Hóa Đơn Được Xác Nhận Thành Công
    int moneyConfirm;      // Tổng Tiến Tất Cả Các Đơn Hàng Sau Khi Xác Nhận Thành Công

public:
    ListOrder() : countCreate(0), confirmBill(0), moneyConfirm(0)
    {
    }
    ~ListOrder()
    {
        delete[] ptrOder;
    }

    friend istream &operator>>(istream &is, ListOrder &l); // Tạo Mới Đơn Hàng
    friend ostream &operator<<(ostream &os, ListOrder &l); // Xem Hóa Đơn và Thanh Toán
    void FUNC_ORDER(ListOrder &l);                         // Hàm Thực Hiện Các Chức Năng
    void MENU();                                           // Hàm Hiển Thị Menu
    void AddFood(ListOrder &l);                            // Hàm Thêm Món Ăn Mới
    void DeleteFood(ListOrder &l);                         // Hàm Xóa Món Ăn Đã Chọn
    void EditFood(ListOrder &l);                           // Hàm Chỉnh Sửa Số Lượng Món Ăn Đã Chọn
    void Statistical(ListOrder &l);                        // Hàm Thống Kê Doanh Thu Của Ca Làm
    void PrintBill(ListOrder &l);                          // Hàm In Hóa Đơn Thanh Toán
    void PrintStatistical(ListOrder &l);                   // Hàm In Thống Kê Doanh Thu Ca Làm
    void PrintShift(ListOrder &l);                         // Hàm In Ca Làm
};
#endif