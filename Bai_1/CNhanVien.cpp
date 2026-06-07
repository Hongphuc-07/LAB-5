#include "CNhanVien.h"

CNhanVien::CNhanVien() : sHoTen(""), iNgay(1), iThang(1), iNamSinh(2000), llLuong(0) {}

CNhanVien::~CNhanVien() {}

void CNhanVien::nhap() { 
    cin.ignore();
    cout << "Nhập họ tên: ";
    getline(cin, sHoTen);
    cout << "Nhập ngày, tháng, năm sinh (cách nhau khoảng trắng): ";
    cin >> iNgay >> iThang >> iNamSinh;
}

void CNhanVien::xuat() const {
    string sNgaySinh = to_string(iNgay) + "/" + to_string(iThang) + "/" + to_string(iNamSinh);
    
    cout << "Họ và tên: " << sHoTen << endl
         << "Ngày sinh: " << sNgaySinh << endl;
}
long long CNhanVien::getLuong() const { return llLuong; } 
int CNhanVien::getNamSinh() const { return iNamSinh; }
string CNhanVien::getHoTen() const { return sHoTen; }

