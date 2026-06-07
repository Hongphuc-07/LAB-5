#ifndef CGIAODICHNHAPHO_H
#define CGIAODICHNHAPHO_H
#include "CGiaoDich.h"

class CGiaoDichNhaPho : public CGiaoDich {
    private:
        string sLoaiNha;
        string sDiaChi; 
    public:
        CGiaoDichNhaPho();
        CGiaoDichNhaPho(string ma, int ngay, int thang, int nam, double donGia, double dienTich);
        ~CGiaoDichNhaPho();

        void nhap() override;
        void xuat() const override;

        string getLoaiNha();
        void setLoaiNha(string loaiNha);
        string getDiaChi();
        void setDiaChi(string diaChi);

        double tinhThanhTien() override;
};

#endif // CGIAODICHNHAPHO_H
