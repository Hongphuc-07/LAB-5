#ifndef CGIAODICH_CANHO_CHUNGCU_H
#define CGIAODICH_CANHO_CHUNGCU_H
#include "CGiaoDich.h"

class CGiaoDichCanHoChungCu : public CGiaoDich {
    private:
        string sMaCan; 
        int iViTriTang; 
    public:
        CGiaoDichCanHoChungCu();
        CGiaoDichCanHoChungCu(string ma, int ngay, int thang, int nam, double donGia, double dienTich);
        ~CGiaoDichCanHoChungCu();

        void nhap() override;
        void xuat() const override;

        string getMaCan();
        void setMaCan(string maCan);
        int getViTriTang();
        void setViTriTang(int viTriTang);

        double tinhThanhTien() override;
};

#endif // CGIAODICH_CANHO_CHUNGCU_H