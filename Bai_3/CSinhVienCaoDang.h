#ifndef CSINHVIENCAODANG_H
#define CSINHVIENCAODANG_H

#include "CSinhVien.h"

class CSinhVienCaoDang : public CSinhVien {
    private:
        int iDiemThiTotNghiep;
    public:
        CSinhVienCaoDang();
        CSinhVienCaoDang(int mssv, const string& hoten, double diemtb, int diemtn);
        ~CSinhVienCaoDang();

        void Nhap() override;
        void Xuat() const override;

        void SetDiemThiTotNghiep(int diemtn);
        int GetDiemThiTotNghiep() const;

        bool KiemTraTotNghiep() const override;
};

#endif // CSINHVIENCAODANG_H