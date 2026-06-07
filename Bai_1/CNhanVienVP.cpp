#include "CNhanVienVP.h"

CNhanVienVP::CNhanVienVP() : CNhanVien(), iSoNgayLamViec(0) {}

void CNhanVienVP::nhap() {
    CNhanVien::nhap();
    cout << "Nhập số ngày làm việc: ";
    cin >> iSoNgayLamViec;
}

void CNhanVienVP::tinhLuong() {
    llLuong = iSoNgayLamViec * 100000;
}

void CNhanVienVP::xuat() const {
    CNhanVien::xuat();
    cout << "Số ngày làm việc: " << iSoNgayLamViec << endl
         << "Tổng lương: " << llLuong << endl;
}
