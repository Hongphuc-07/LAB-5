#ifndef CKHACHHANGBINHTHUONG_H
#define CKHACHHANGBINHTHUONG_H

#include "CKhachHang.h"

class CKhachHangBinhThuong : public CKhachHang {
public:
    CKhachHangBinhThuong();
    CKhachHangBinhThuong(const string& hoTen, int soLuong, double donGia);
    ~CKhachHangBinhThuong();

    void DocTuFile(ifstream& file) override;
    void XuatRaFile(ofstream& file) const override;
    double TinhThanhTien() const override;
};

#endif // CKHACHHANGBINHTHUONG_H