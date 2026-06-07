#include "CSinhVienCaoDang.h"

CSinhVienCaoDang::CSinhVienCaoDang() : CSinhVien(), iDiemThiTotNghiep(0) {}

CSinhVienCaoDang::CSinhVienCaoDang(int mssv, const string& hoten, double diemtb, int diemtn)
    : CSinhVien(mssv, hoten, diemtb), iDiemThiTotNghiep(diemtn) {}

CSinhVienCaoDang::~CSinhVienCaoDang() {}

void CSinhVienCaoDang::Nhap() {
    CSinhVien::Nhap();
    cout << "Nhập Điểm Thi Tốt Nghiệp: ";
    cin >> iDiemThiTotNghiep;
}

void CSinhVienCaoDang::Xuat() const {
    CSinhVien::Xuat();
    cout << "Điểm Thi Tốt Nghiệp: " << iDiemThiTotNghiep << endl;
}

void CSinhVienCaoDang::SetDiemThiTotNghiep(int diemtn) {
    iDiemThiTotNghiep = diemtn;
}

int CSinhVienCaoDang::GetDiemThiTotNghiep() const {
    return iDiemThiTotNghiep;
}

bool CSinhVienCaoDang::KiemTraTotNghiep() const {
    if ((iTongSoTinChi >= 120) && (dDiemTB >= 5.0) && (iDiemThiTotNghiep >= 5)) {
        return true;
    }
    return false;
}

