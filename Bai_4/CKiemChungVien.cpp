#include "CKiemChungVien.h"

CKiemChungVien::CKiemChungVien() : CNhanVien() {
    iSoloi = 0;
}

CKiemChungVien::CKiemChungVien(string maNV, string hoTen, int tuoi, long long luongCoBan, int soLoi)
    : CNhanVien(maNV, hoTen, tuoi, luongCoBan) {
    iSoloi = soLoi;
}

CKiemChungVien::~CKiemChungVien() {
}

void CKiemChungVien::Nhap() {
    CNhanVien::Nhap();
    cout << "Nhập số lỗi: ";
    cin >> iSoloi;
}

void CKiemChungVien::Xuat() {
    CNhanVien::Xuat();
    cout << "Số lỗi: " << iSoloi << endl;
}

long long CKiemChungVien::TinhLuong() {
    long long tienPhat = iSoloi * 50000; 
    return CNhanVien::TinhLuong() + tienPhat;
}


