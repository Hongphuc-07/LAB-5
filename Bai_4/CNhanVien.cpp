#include "CNhanVien.h"

CNhanVien::CNhanVien() {
    sMaNhanVien = "";
    sHoTen = "";
    iTuoi = 0;
    iSDT = 0;
    sEmail = "";
    llLuongCoBan = 0.0;
}

CNhanVien::CNhanVien(string maNV, string hoTen, int tuoi, long long luongCoBan) : sMaNhanVien(maNV), sHoTen(hoTen), iTuoi(tuoi), llLuongCoBan(luongCoBan) {
    sMaNhanVien = maNV;
    sHoTen = hoTen;
    iTuoi = tuoi;
}

CNhanVien::~CNhanVien() {
}

void CNhanVien::Nhap() {
    cout << "Nhập mã nhân viên: ";
    getline(cin, sMaNhanVien);
    cout << "Nhập họ tên: ";
    getline(cin, sHoTen);
    cout << "Nhập tuổi: ";
    cin >> iTuoi;
    cout << "Nhập số điện thoại: ";
    cin >> iSDT;
    cin.ignore();
    cout << "Nhập email: ";
    getline(cin, sEmail);
    cout << "Nhập lương cơ bản: ";
    cin >> llLuongCoBan; 
}

void CNhanVien::Xuat() {
    cout << "Mã nhân viên: " << sMaNhanVien << endl;
    cout << "Họ tên: " << sHoTen << endl;
    cout << "Tuổi: " << iTuoi << endl;
    cout << "Số điện thoại: " << iSDT << endl;
    cout << "Email: " << sEmail << endl;
    cout << "Lương cơ bản: " << llLuongCoBan << endl;
}

long long CNhanVien::TinhLuong() {
    return llLuongCoBan;
}

