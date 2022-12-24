#ifndef Staff_h
#define Staff_h
// #define SL 5
#include <bits/stdc++.h>
using namespace std;
class Staff
{
private:
    char nvUSERNAME[5][50]; // Tài Khoản Từ FILE
    char nvPASSWORD[5][50]; // Mật Khẩu Từ FILE
    char nvUSER[5][50];     // Tài Khoản Từ Người Dùng
    char nvPASS[5][50];     // Mật Khẩu Từ Người Dùng
    char *start;            // Thời Gian Mà Nhân Viên Bắt Đầu Ca Làm Việc

public:
    void nvACCOUNT(Staff &s);
    void LoginNV(Staff &s);
};
#endif