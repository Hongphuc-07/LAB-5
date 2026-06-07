#include "CGiaoDichNhaPho.h"

CGiaoDichNhaPho::CGiaoDichNhaPho() : CGiaoDich(), sLoaiNha(""), sDiaChi("") {}

CGiaoDichNhaPho::CGiaoDichNhaPho(string ma, int ngay, int thang, int nam, double donGia, double dienTich)
    : CGiaoDich(ma, ngay, thang, nam, donGia, dienTich), sLoaiNha(""), sDiaChi("") {}

CGiaoDichNhaPho::~CGiaoDichNhaPho() {}

void CGiaoDichNhaPho::nhap() {
    CGiaoDich::nhap();
    cout << "Nhập loại nhà (cp: Cao cấp, t: Thường): ";
    cin >> sLoaiNha;
    cout << "Nhập địa chỉ: ";
    cin.ignore(); // Consume the newline character left by cin >> sLoaiNha;
    getline(cin, sDiaChi);
}

void CGiaoDichNhaPho::xuat() const {
    CGiaoDich::xuat();
    cout << "Loại nhà: ";
    if (sLoaiNha == "cp") {
        cout << "Cao cấp" << endl;
    } else {
        cout << "Thường" << endl;
    }   
    cout << "Địa chỉ: " << sDiaChi << endl;
}

string CGiaoDichNhaPho::getLoaiNha() { return sLoaiNha; }

void CGiaoDichNhaPho::setLoaiNha(string loaiNha) { sLoaiNha = loaiNha; }

string CGiaoDichNhaPho::getDiaChi() { return sDiaChi; }

void CGiaoDichNhaPho::setDiaChi(string diaChi) { sDiaChi = diaChi; }

double CGiaoDichNhaPho::tinhThanhTien() {
    if (sLoaiNha == "cp") {
        return dDienTich * dDonGia;
    } else {
        return dDienTich * dDonGia * 0.9;
    }
}

