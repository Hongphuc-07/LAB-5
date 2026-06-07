#ifndef CNHANVIENVP_H
#define CNHANVIENVP_H
#include "CNhanVien.h"

class CNhanVienVP : public CNhanVien {
    private:
        int iSoNgayLamViec;
    public:
        CNhanVienVP();
        void nhap() override;
        void tinhLuong() override;
        void xuat() const override;
};

#endif
