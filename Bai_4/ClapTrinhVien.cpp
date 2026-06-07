#include "CLapTrinhVien.h"

CLapTrinhVien::CLapTrinhVien() : CNhanVien() {
    iSoGioOvertime = 0;
}

CLapTrinhVien::CLapTrinhVien(string maNV, string hoTen, int tuoi, double luongCoBan, int soGioOvertime)
    : CNhanVien(maNV, hoTen, tuoi, luongCoBan) {
    iSoGioOvertime = soGioOvertime;
}

CLapTrinhVien::~CLapTrinhVien() {
}

void CLapTrinhVien::Nhap() {
    CNhanVien::Nhap();
    cout << "Nhập số giờ overtime: ";
    cin >> iSoGioOvertime;
}

void CLapTrinhVien::Xuat() {
    CNhanVien::Xuat();
    cout << "Số giờ overtime: " << iSoGioOvertime << endl;
}

long long CLapTrinhVien::TinhLuong() {
    double luongOvertime = iSoGioOvertime * 200000; 
    return CNhanVien::TinhLuong() + luongOvertime;
}

