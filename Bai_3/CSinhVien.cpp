#include "CSinhVien.h"

CSinhVien::CSinhVien() : iMSSV(0), sHoTen(""), sDiaChi(""), iTongSoTinChi(0), dDiemTB(0.0) {}

CSinhVien::CSinhVien(int mssv, const std::string& hoten, double diemtb)
    : iMSSV(mssv), sHoTen(hoten), sDiaChi(""), iTongSoTinChi(0), dDiemTB(diemtb) {}

CSinhVien::~CSinhVien() {}

void CSinhVien::Nhap() {
    cout << "Nhập MSSV: ";
    cin >> iMSSV;
    cin.ignore(); 
    cout << "Nhập Họ Tên: ";
    getline(cin, sHoTen);
    cout << "Nhập Địa Chỉ: ";
    getline(cin, sDiaChi);
    cout << "Nhập Điểm TB: ";
    cin >> dDiemTB;
    cout << "Nhập Tổng Số Tín Chỉ: ";
    cin >> iTongSoTinChi;
}

void CSinhVien::Xuat() const {
    cout << "MSSV: " << iMSSV << endl;
    cout << "Họ Tên: " << sHoTen << endl;
    cout << "Địa Chỉ: " << sDiaChi << endl;
    cout << "Điểm TB: " << dDiemTB << endl;
    cout << "Tổng Số Tín Chỉ: " << iTongSoTinChi << endl;
}

void CSinhVien::SetMSSV(int mssv) {
    iMSSV = mssv;
}

int CSinhVien::GetMSSV() const {
    return iMSSV;
}

void CSinhVien::SetHoTen(const std::string& hoten) {
    sHoTen = hoten;
}
string CSinhVien::GetHoTen() const {
    return sHoTen;
}
void CSinhVien::SetDiaChi(const std::string& diachi) {
    sDiaChi = diachi;
}

string CSinhVien::GetDiaChi() const {
    return sDiaChi;
}

void CSinhVien::SetDiemTB(double diemtb) {
    dDiemTB = diemtb;
}

double CSinhVien::GetDiemTB() const {
    return dDiemTB;
}

void CSinhVien::SetTongSoTinChi(int tongsotinchi) {
    iTongSoTinChi = tongsotinchi;
}

int CSinhVien::GetTongSoTinChi() const {
    return iTongSoTinChi;
}

bool CSinhVien::KiemTraTotNghiep() const {
    return false;
}