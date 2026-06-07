#include "CNhanVienSX.h"

CNhanVienSX::CNhanVienSX() : CNhanVien(), llLuongCanBan(0), iSoSanPham(0) {}

void CNhanVienSX::nhap() {
    CNhanVien::nhap();
    cout << "Nhập lương căn bản: ";
    cin >> llLuongCanBan;
    cout << "Nhập số sản phẩm: ";
    cin >> iSoSanPham;
}

void CNhanVienSX::tinhLuong() {
    llLuong = llLuongCanBan * iSoSanPham * 5000;
}

void CNhanVienSX::xuat() const {
    CNhanVien::xuat();
    cout << "Lương căn bản: " << llLuongCanBan << endl
         << "Số sản phẩm: " << iSoSanPham << endl
         << "Tổng lương: " << llLuong << endl;
}