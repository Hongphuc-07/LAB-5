#ifndef CNHANVIEN_H
#define CNHANVIEN_H
#include <iostream>
#include <string>
using namespace std;

class CNhanVien {
protected:
    string sMaNhanVien;
    string sHoTen;
    int iTuoi;
    int iSDT;
    string sEmail;
    long long llLuongCoBan;

public:
    CNhanVien();
    CNhanVien(string maNV, string hoTen, int tuoi, long long luongCoBan);
    virtual ~CNhanVien();

    virtual void Nhap();
    virtual void Xuat();
    virtual long long TinhLuong();
};

#endif // CNHANVIEN_H