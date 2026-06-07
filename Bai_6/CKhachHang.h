#ifndef CKHACHHANG_H
#define CKHACHHANG_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class CKhachHang {
private:
    string sHoTen;
    int iSoLuong;
    double dDonGia;

public:
    CKhachHang();
    CKhachHang(const string& hoTen, int soLuong, double donGia);
    ~CKhachHang();
    virtual void DocTuFile(ifstream& file);
    virtual void XuatRaFile(ofstream& file) const;
    virtual double TinhThanhTien() const;

    string getHoTen() const;
    int getSoLuong() const;
    double getDonGia() const;

};

#endif // CKHACHHANG_H