#include "CNhanVien.h"
#include "CNhanVienSX.h"
#include "CNhanVienVP.h"
#include <iostream>
#include <ctime> 

using namespace std;

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    CNhanVien** dsNhanVien = new CNhanVien*[n];

    // NHẬP DANH SÁCH
    for (int i = 0; i < n; ++i) {
        int loai;
        cout << "Nhap loai nhan vien (1: San xuat, 2: Van phong): ";
        cin >> loai;

        if (loai == 1) {
            dsNhanVien[i] = new CNhanVienSX();
        } else if (loai == 2) {
            dsNhanVien[i] = new CNhanVienVP();
        } else {
            cout << "Loai nhan vien khong hop le. Vui long nhap lai." << endl;
            --i; 
            continue;
        }

        dsNhanVien[i]->nhap();
        dsNhanVien[i]->tinhLuong();
    }

    // XUẤT DANH SÁCH
    cout << "\nDanh sach nhan vien:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nNhan vien " << (i + 1) << ":\n";
        dsNhanVien[i]->xuat();
    }

    // TÍNH TỔNG LƯƠNG 
    long long tongLuong = 0;
    for (int i = 0; i < n; ++i) {
        tongLuong += dsNhanVien[i]->getLuong();
    }
    cout << "\nTong luong cong ty phai tra: " << tongLuong << endl;
    
    // TÌM NHÂN VIÊN SẢN XUẤT CÓ LƯƠNG THẤP NHẤT 
    long long minLuong = -1; 
    int idxMinLuongSX = -1; // Lưu vị trí nhân viên SX tìm thấy

    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<CNhanVienSX*>(dsNhanVien[i])) {
            // Nếu là nhân viên SX đầu tiên tìm thấy HOẶC tìm thấy người có lương thấp hơn
            if (idxMinLuongSX == -1 || dsNhanVien[i]->getLuong() < minLuong) {
                minLuong = dsNhanVien[i]->getLuong();
                idxMinLuongSX = i;
            }
        }
    }

    cout << "\nNhan vien san xuat co luong thap nhap:\n";
    if (idxMinLuongSX != -1) {
        cout << dsNhanVien[idxMinLuongSX]->getHoTen() << " voi muc luong " << minLuong << endl;
    } else {
        cout << "(Khong co nhan vien san xuat nao trong danh sach)" << endl;
    }

    // TÌM NHÂN VIÊN VĂN PHÒNG CÓ TUỔI CAO NHẤT (NĂM SINH NHỎ NHẤT) 
    int minNamSinh = -1; 
    int idxMaxTuoiVP = -1; // Lưu vị trí nhân viên VP tìm thấy

    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<CNhanVienVP*>(dsNhanVien[i])) {
            // Tuổi cao nhất tương ứng với Năm sinh NHỎ nhất
            if (idxMaxTuoiVP == -1 || dsNhanVien[i]->getNamSinh() < minNamSinh) {
                minNamSinh = dsNhanVien[i]->getNamSinh();
                idxMaxTuoiVP = i;
            }
        }
    }

    cout << "\nNhan vien van phong co tuoi cao nhat:\n";
    if (idxMaxTuoiVP != -1) {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int namHienTai = now->tm_year + 1900; 
        cout << dsNhanVien[idxMaxTuoiVP]->getHoTen() << " " << (namHienTai - minNamSinh) << " tuoi" << endl;
    } else {
        cout << "(Khong co nhan vien van phong nao trong danh sach)" << endl;
    }

    // GIẢI PHÓNG BỘ NHỚ ĐỘNG 
    for (int i = 0; i < n; ++i) {
        delete dsNhanVien[i];
    }
    delete[] dsNhanVien;

    return 0;
}