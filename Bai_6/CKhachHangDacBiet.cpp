#include "CKhachHangDacBiet.h"

CKhachHangDacBiet::CKhachHangDacBiet() : CKhachHang() {}

CKhachHangDacBiet::CKhachHangDacBiet(const string& hoTen, int soLuong, double donGia)
    : CKhachHang(hoTen, soLuong, donGia) {}

CKhachHangDacBiet::~CKhachHangDacBiet() {}

void CKhachHangDacBiet::DocTuFile(ifstream& file) {
    CKhachHang::DocTuFile(file);
}

void CKhachHangDacBiet::XuatRaFile(ofstream& file) const {
    CKhachHang::XuatRaFile(file);
}

double CKhachHangDacBiet::TinhThanhTien() const {
    double thanhTien = getSoLuong() * getDonGia();
    return thanhTien * 0.5 + (thanhTien * 0.1);
}

