#ifndef FuncManage_h
#define FuncManage_h
#include <string.h>
using namespace std;
class FuncManage
{
private:
    int totalBill[3];             // Tổng Số Hóa Đơn Của Mỗi Ca Làm
    int STT[101];                 // Số Thứ Tự Hóa Đơn
    string orderCode[101];        // Mã Đơn Hàng
    int TotalAmountPerOrder[101]; // Tổng tiền mỗi đơn hàng
    string Time[101];             // Thời gian tạo các đơn hàng
    int totalMoney[3];            // Tổng tiền tất cả các đơn hàng
    int count;                    // Tổng Hóa Đơn Trong Tất Cả Các Ca
    int tempTotalBill;            // Tổng Hóa Đơn Tất Cả Hóa Đơn
    int tempTotalMoney;           // Tổng Tền Tất Cả Hóa Đơn
    char time[8];                 // Thời Gian Thống Kê

public:
    FuncManage() : count(0), tempTotalBill(0), tempTotalMoney(0)
    {
    }
    char *getTime()
    {
        return time;
    }
    void Func_Perform(FuncManage &f);
    void StaticticalDate(FuncManage &f);
    void Back(FuncManage &f);
    void printStaticticalDate(FuncManage &f);
};
#endif