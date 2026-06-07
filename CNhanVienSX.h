#ifndef CNHANVIENSANXUAT_H
#define CNHANVIENSANXUAT_H

#include "CNhanVien.h"

class CNhanVienSX : public CNhanVien {
private:
    long long llLuongCanBan;
    int iSoSanPham;

public:
    CNhanVienSX();
    void nhap() override;
    void tinhLuong() override;
    void xuat() const override;
};

#endif
