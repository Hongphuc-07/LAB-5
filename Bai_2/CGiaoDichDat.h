#ifndef CGIAODICHDAT_H
#define CGIAODICHDAT_H
#include "CGiaoDich.h"

class CGiaoDichDat : public CGiaoDich {
    private:
        string sLoaiDat; 
    public:
        CGiaoDichDat();
        CGiaoDichDat(string ma, int ngay, int thang, int nam, double donGia, double dienTich);
        ~CGiaoDichDat();

        void nhap() override;
        void xuat() const override;

        string getLoaiDat();
        void setLoaiDat(string loaiDat);

        double tinhThanhTien() override;
};

#endif // CGIAODICHDAT_H
