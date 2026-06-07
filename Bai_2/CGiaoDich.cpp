#include "CGiaoDich.h"

CGiaoDich::CGiaoDich() : sMaGiaoDich(""), iNgay(0), iThang(0), iNam(0), dDonGia(0), dDienTich(0) {}

CGiaoDich::CGiaoDich(string ma, int ngay, int thang, int nam, double donGia, double dienTich)
    : sMaGiaoDich(ma), iNgay(ngay), iThang(thang), iNam(nam), dDonGia(donGia), dDienTich(dienTich) {}

CGiaoDich::~CGiaoDich() {}

void CGiaoDich::nhap() {
    cout << "Nhập mã giao dịch: ";
    cin >> sMaGiaoDich;
    cout << "Nhập ngày giao dịch: ";
    cin >> iNgay;
    cout << "Nhập tháng giao dịch: ";
    cin >> iThang;
    cout << "Nhập năm giao dịch: ";
    cin >> iNam;
    cout << "Nhập đơn giá: ";
    cin >> dDonGia;
    cout << "Nhập diện tích: ";
    cin >> dDienTich;
}

void CGiaoDich::xuat() const {
    cout << "Mã giao dịch: " << sMaGiaoDich << endl
         << "Ngày giao dịch: " << iNgay << "/" << iThang << "/" << iNam << endl
         << "Đơn giá: " << dDonGia << endl
         << "Diện tích: " << dDienTich << endl;
}

string CGiaoDich::getMaGiaoDich() { return sMaGiaoDich; }

void CGiaoDich::setMaGiaoDich(string ma) { sMaGiaoDich = ma; }

int CGiaoDich::getNgayGiaoDich() { return iNgay; }

void CGiaoDich::setNgayGiaoDich(int ngay) { iNgay = ngay; }

int CGiaoDich::getThangGiaoDich() { return iThang; }

void CGiaoDich::setThangGiaoDich(int thang) { iThang = thang; }

int CGiaoDich::getNamGiaoDich() { return iNam; }

void CGiaoDich::setNamGiaoDich(int nam) { iNam = nam; }

double CGiaoDich::getDonGia() { return dDonGia; }

void CGiaoDich::setDonGia(double donGia) { dDonGia = donGia; }

double CGiaoDich::getDienTich() { return dDienTich; }

void CGiaoDich::setDienTich(double dienTich) { dDienTich = dienTich; }

