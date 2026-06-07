#ifndef CGIAODICH_H
#define CGIAODICH_H
#include <string>
#include <iostream>
using namespace std;
class CGiaoDich {
protected:
    string sMaGiaoDich;
    int iNgay, iThang, iNam; 
    double dDonGia;
    double dDienTich;

public:
    CGiaoDich();
    CGiaoDich(string ma, int ngay, int thang, int nam, double donGia, double dienTich);
    virtual ~CGiaoDich();
    virtual void nhap();
    virtual void xuat() const;

    virtual double tinhThanhTien() = 0;

    string getMaGiaoDich();
    void setMaGiaoDich(string ma);
    int getNgayGiaoDich();
    void setNgayGiaoDich(int ngay);
    int getThangGiaoDich();
    void setThangGiaoDich(int thang);
    int getNamGiaoDich();
    void setNamGiaoDich(int nam);
    double getDonGia();
    void setDonGia(double donGia);
    double getDienTich();
    void setDienTich(double dienTich); 
};

#endif // CGIAODICH_H