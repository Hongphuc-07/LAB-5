#include "CGiaoDichDat.h"

CGiaoDichDat::CGiaoDichDat() : CGiaoDich(), sLoaiDat("") {}

CGiaoDichDat::CGiaoDichDat(string ma, int ngay, int thang, int nam, double donGia, double dienTich)
    : CGiaoDich(ma, ngay, thang, nam, donGia, dienTich), sLoaiDat("") {}

CGiaoDichDat::~CGiaoDichDat() {}

void CGiaoDichDat::nhap() {
    CGiaoDich::nhap();
    cout << "Nhập loại đất (A, B, C): ";
    cin >> sLoaiDat;
}

void CGiaoDichDat::xuat() const {
    CGiaoDich::xuat();
    cout << "Loại đất: " << sLoaiDat << endl;
}

string CGiaoDichDat::getLoaiDat() { return sLoaiDat; }

void CGiaoDichDat::setLoaiDat(string loaiDat) { sLoaiDat = loaiDat; }

double CGiaoDichDat::tinhThanhTien() {
    if (sLoaiDat == "A") { 
        return dDienTich * dDonGia * 1.5;
    } else { // loại B và C
        return dDienTich * dDonGia;
    }
}