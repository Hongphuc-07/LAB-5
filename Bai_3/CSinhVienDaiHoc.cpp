#include "CSinhVienDaiHoc.h"

CSinhVienDaiHoc::CSinhVienDaiHoc() : CSinhVien(), sTenLuanVan(""), iDiemLuanVan(0) {}

CSinhVienDaiHoc::CSinhVienDaiHoc(int mssv, const string& hoten, double diemtb, const string& tenluanvan, int diemluanvan)
    : CSinhVien(mssv, hoten, diemtb), sTenLuanVan(tenluanvan), iDiemLuanVan(diemluanvan) {}

CSinhVienDaiHoc::~CSinhVienDaiHoc() {}

void CSinhVienDaiHoc::Nhap() {
    CSinhVien::Nhap();
    cout << "Nhập Tên Luận Văn: ";
    cin.ignore(); 
    getline(cin, sTenLuanVan);
    cout << "Nhập Điểm Luận Văn: ";
    cin >> iDiemLuanVan;
}

void CSinhVienDaiHoc::Xuat() const {
    CSinhVien::Xuat();
    cout << "Tên Luận Văn: " << sTenLuanVan << endl;
    cout << "Điểm Luận Văn: " << iDiemLuanVan << endl;
}

void CSinhVienDaiHoc::SetTenLuanVan(const string& tenluanvan) {
    sTenLuanVan = tenluanvan;
}

string CSinhVienDaiHoc::GetTenLuanVan() const {
    return sTenLuanVan;
}

void CSinhVienDaiHoc::SetDiemLuanVan(int diemluanvan) {
    iDiemLuanVan = diemluanvan;
}

int CSinhVienDaiHoc::GetDiemLuanVan() const {
    return iDiemLuanVan;
}

bool CSinhVienDaiHoc::KiemTraTotNghiep() const {
    if ((iTongSoTinChi >= 170) && (dDiemTB >= 5.0) && (iDiemLuanVan >= 5)) {
        return true;
    }
    return false;
}

