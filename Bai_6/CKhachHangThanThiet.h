#ifndef CKHACHHANGTHANTHIET_H
#define CKHACHHANGTHANTHIET_H

#include "CKhachHang.h"

class CKhachHangThanThiet : public CKhachHang {
    private:
    int iSoNamThanThiet;
    public:
        CKhachHangThanThiet();
        CKhachHangThanThiet(const string& hoTen, int soLuong, double donGia, int sonamthanthiet);
        ~CKhachHangThanThiet();

        void DocTuFile(ifstream& file) override;
        void XuatRaFile(ofstream& file) const override;
        double TinhThanhTien() const override;
};

#endif // CKHACHHANGTHANTHIET_H