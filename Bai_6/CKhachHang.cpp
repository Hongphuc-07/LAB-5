#include "CKhachHang.h"

CKhachHang::CKhachHang() : sHoTen(""), iSoLuong(0), dDonGia(0.0) {}

CKhachHang::CKhachHang(const string& hoTen, int soLuong, double donGia)
    : sHoTen(hoTen), iSoLuong(soLuong), dDonGia(donGia) {}

CKhachHang::~CKhachHang() {}

void CKhachHang::DocTuFile(ifstream& file) {
    getline(file, sHoTen);
    file >> iSoLuong >> dDonGia;
    file.ignore();
}

void CKhachHang::XuatRaFile(ofstream& file) const {
    file << sHoTen << endl;
    file << TinhThanhTien() << endl;
}

double CKhachHang::TinhThanhTien() const {
    return 0.0;
}

string CKhachHang::getHoTen() const {
    return sHoTen;
}


int CKhachHang::getSoLuong() const {
    return iSoLuong;
}

double CKhachHang::getDonGia() const {
    return dDonGia;
}