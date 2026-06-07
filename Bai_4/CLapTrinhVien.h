#ifndef CLAPTRINHVIEN_H
#define CLAPTRINHVIEN_H
#include "CNhanVien.h"

class CLapTrinhVien : public CNhanVien {
private:
    int iSoGioOvertime;

public:
    CLapTrinhVien();
    CLapTrinhVien(string maNV, string hoTen, int tuoi, double luongCoBan, int soGioOvertime);
    ~CLapTrinhVien();

    void Nhap() override;
    void Xuat() override;
    long long TinhLuong() override;
};

#endif // CLAPTRINHVIEN_H