#ifndef CKIEMCHUNGVIEN_H
#define CKIEMCHUNGVIEN_H
#include "CNhanVien.h"

class CKiemChungVien : public CNhanVien {
private:
    int iSoloi;

public:
    CKiemChungVien();
    CKiemChungVien(string maNV, string hoTen, int tuoi, long long luongCoBan, int soLoi);
    ~CKiemChungVien();

    void Nhap() override;
    void Xuat() override;
    long long TinhLuong() override;
};

#endif // CKIEMCHUNGVIEN_H