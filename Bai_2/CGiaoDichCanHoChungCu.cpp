#include "CGiaoDichCanHoChungCu.h"

CGiaoDichCanHoChungCu::CGiaoDichCanHoChungCu() : CGiaoDich(), sMaCan(""), iViTriTang(0) {}

CGiaoDichCanHoChungCu::CGiaoDichCanHoChungCu(string ma, int ngay, int thang, int nam, double donGia, double dienTich)
    : CGiaoDich(ma, ngay, thang, nam, donGia, dienTich), sMaCan(""), iViTriTang(0) {}

CGiaoDichCanHoChungCu::~CGiaoDichCanHoChungCu() {}

void CGiaoDichCanHoChungCu::nhap() {
    CGiaoDich::nhap();
    cout << "Nhập mã căn hộ: ";
    cin >> sMaCan;
    cout << "Nhập vị trí tầng: ";
    cin >> iViTriTang;
}

void CGiaoDichCanHoChungCu::xuat() const {
    CGiaoDich::xuat();
    cout << "Mã căn hộ: " << sMaCan << endl
         << "Vị trí tầng: " << iViTriTang << endl;
}

string CGiaoDichCanHoChungCu::getMaCan() { return sMaCan; }

void CGiaoDichCanHoChungCu::setMaCan(string maCan) { sMaCan = maCan; }

int CGiaoDichCanHoChungCu::getViTriTang() { return iViTriTang; }

void CGiaoDichCanHoChungCu::setViTriTang(int viTriTang) { iViTriTang = viTriTang; }

double CGiaoDichCanHoChungCu::tinhThanhTien() {
    if (iViTriTang == 1 ) {
        return dDienTich * dDonGia * 2;
    } else if (iViTriTang > 1 && iViTriTang < 15) {
        return dDienTich * dDonGia * 1.2;
    } else {
        return dDienTich * dDonGia;
    }
}