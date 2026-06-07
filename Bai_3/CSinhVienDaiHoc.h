#ifndef CSINHVIENDAIHOC_H
#define CSINHVIENDAIHOC_H

#include "CSinhVien.h"

class CSinhVienDaiHoc : public CSinhVien {
    private:
        string sTenLuanVan;
        int iDiemLuanVan;
    public:
        CSinhVienDaiHoc();
        CSinhVienDaiHoc(int mssv, const string& hoten, double diemtb, const string& tenluanvan, int diemluanvan);
        ~CSinhVienDaiHoc();

        void Nhap() override;
        void Xuat() const override;

        void SetTenLuanVan(const string& tenluanvan);
        string GetTenLuanVan() const;

        void SetDiemLuanVan(int diemluanvan);
        int GetDiemLuanVan() const;

        bool KiemTraTotNghiep() const override;
};

#endif // CSINHVIENDAIHOC_H
