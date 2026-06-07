#include "CKhachHangThanThiet.h"

CKhachHangThanThiet::CKhachHangThanThiet():CKhachHang() {}

CKhachHangThanThiet::CKhachHangThanThiet(const string& hoTen, int soLuong, double donGia, int sonamthanthiet)
    :CKhachHang(hoTen, soLuong, donGia){}

CKhachHangThanThiet::~CKhachHangThanThiet(){}

void CKhachHangThanThiet::DocTuFile(ifstream& file) {
    CKhachHang::DocTuFile(file);
    file >> iSoNamThanThiet;
}

void CKhachHangThanThiet::XuatRaFile(ofstream& file) const {
    CKhachHang::XuatRaFile(file);
}

double CKhachHangThanThiet::TinhThanhTien() const {
    double KhuyenMai = iSoNamThanThiet * 0.05;
    if (KhuyenMai >= 0.5 ) KhuyenMai = 0.5;

    double thanhTien = getSoLuong() * getDonGia() ;
    return thanhTien * KhuyenMai + (thanhTien * 0.1);
}