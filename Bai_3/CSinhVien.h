#ifndef CSINHVIEN_H
#define CSINHVIEN_H
#include <string>
#include <iostream>
using namespace std;

class CSinhVien {
protected:
    int iMSSV;
    string sHoTen;
    string sDiaChi;
    int iTongSoTinChi;
    double dDiemTB;

public:
    CSinhVien();
    CSinhVien(int mssv, const std::string& hoten, double diemtb);
    virtual ~CSinhVien();

    virtual void Nhap();
    virtual void Xuat() const;

    void SetMSSV(int mssv);
    int GetMSSV() const;

    void SetHoTen(const std::string& hoten);
    string GetHoTen() const;

    void SetDiaChi(const std::string& diachi);
    string GetDiaChi() const;

    void SetDiemTB(double diemtb);
    double GetDiemTB() const;

    void SetTongSoTinChi(int tongsotinchi);
    int GetTongSoTinChi() const;

    virtual bool KiemTraTotNghiep() const = 0;

};

#endif // CSINHVIEN_H