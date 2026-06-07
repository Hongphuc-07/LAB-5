#include "CKhachHangBinhThuong.h"

CKhachHangBinhThuong::CKhachHangBinhThuong() : CKhachHang() {}

CKhachHangBinhThuong::CKhachHangBinhThuong(const string& hoTen, int soLuong, double donGia)
    : CKhachHang(hoTen, soLuong, donGia) {}

CKhachHangBinhThuong::~CKhachHangBinhThuong() {}

void CKhachHangBinhThuong::DocTuFile(ifstream& file) {
    CKhachHang::DocTuFile(file);
}

void CKhachHangBinhThuong::XuatRaFile(ofstream& file) const {
    CKhachHang::XuatRaFile(file);
}

double CKhachHangBinhThuong::TinhThanhTien() const {
    double thanhTien = getSoLuong() * getDonGia();
    return thanhTien + (thanhTien * 0.1);
}

