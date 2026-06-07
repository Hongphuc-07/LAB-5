#ifndef CNHANVIEN_H
#define CNHANVIEN_H

#include <string>
#include <iostream>
using namespace std;

class CNhanVien {
protected:
    string sHoTen;
    int iNgay, iThang, iNamSinh;
    long long llLuong;

public:
    CNhanVien();
    virtual ~CNhanVien();

    virtual void nhap();
    virtual void xuat() const;
    virtual void tinhLuong() = 0;

    long long getLuong() const;
    int getNamSinh() const;
    string getHoTen() const;
};

#endif
