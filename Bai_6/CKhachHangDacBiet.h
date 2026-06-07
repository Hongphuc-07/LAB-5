#ifndef CKHACHHANGDACBIET_H
#define CKHACHHANGDACBIET_H

#include "CKhachHang.h"

class CKhachHangDacBiet : public CKhachHang {
    public:
        CKhachHangDacBiet();
        CKhachHangDacBiet(const string& hoTen, int soLuong, double donGia);
        ~CKhachHangDacBiet();

        void DocTuFile(ifstream& file) override;
        void XuatRaFile(ofstream& file) const override;
        double TinhThanhTien() const override;


};

#endif // CKHACHHANGDACBIET_H