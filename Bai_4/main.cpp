#include "CNhanVien.h"
#include "CLapTrinhVien.h"
#include "CKiemChungVien.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Nhập số lượng nhân viên: ";
    cin >> n;
    cin.ignore(); // Xóa bộ nhớ đệm để tránh trôi lệnh khi nhập chuỗi ở các bước sau

    // Khởi tạo mảng con trỏ quản lý danh sách nhân viên (Áp dụng tính đa hình)
    CNhanVien** dsNhanVien = new CNhanVien*[n];

    // NHẬP DANH SÁCH NHÂN VIÊN
    for (int i = 0; i < n; ++i) {
        int loai;
        cout << "Nhập loại nhân viên (1: Lập trình viên, 2: Kiểm chứng viên): ";
        cin >> loai;
        cin.ignore(); // Xóa bộ nhớ đệm sau khi nhập số loại

        // Khởi tạo đối tượng tương ứng dựa trên loại nhân viên được chọn
        if (loai == 1) {
            dsNhanVien[i] = new CLapTrinhVien();
        } else if (loai == 2) {
            dsNhanVien[i] = new CKiemChungVien();
        } else {
            cout << "Loại nhân viên không hợp lệ. Vui lòng nhập lại." << endl;
            --i; // Giảm chỉ số vòng lặp để nhập lại cho vị trí hiện tại
            continue;
        }

        dsNhanVien[i]->Nhap();
    }

    // XUẤT DANH SÁCH NHÂN VIÊN VÀ LƯƠNG
    cout << "\nDanh sách nhân viên:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nNhân viên " << (i + 1) << ":\n";
        dsNhanVien[i]->Xuat();
        cout << "Lương: " << dsNhanVien[i]->TinhLuong() << endl;
    }

    // TÍNH VÀ LỌC NHÂN VIÊN THEO MỨC LƯƠNG TRUNG BÌNH
    long long MucLuongTB = 0.0;
    for (int i = 0; i < n; ++i) {
        MucLuongTB += dsNhanVien[i]->TinhLuong();
    }
    MucLuongTB /= n;
    cout << "\nMức lương trung bình: " << MucLuongTB << endl;

    cout << "\nDanh sách nhân viên có mức lương thấp hơn mức trung bình:\n";
    for (int i = 0; i < n; ++i) {
        if (dsNhanVien[i]->TinhLuong() < MucLuongTB) {
            cout << "\nNhân viên " << (i + 1) << ":\n";
            dsNhanVien[i]->Xuat();
        }
    }

    // TÌM NHÂN VIÊN CÓ MỨC LƯƠNG CAO NHẤT (TOÀN CÔNG TY)
    cout << "\nNhân viên có mức lương cao nhất:\n";
    CNhanVien* NVCaoNhat = dsNhanVien[0]; // Giả định nhân viên đầu tiên có lương cao nhất
    for (int i = 1; i < n; ++i) {
        if (dsNhanVien[i]->TinhLuong() > NVCaoNhat->TinhLuong()) {
            NVCaoNhat = dsNhanVien[i]; // Cập nhật con trỏ chỉ đến nhân viên có lương cao hơn
        }
    }
    NVCaoNhat->Xuat();

    // TÌM NHÂN VIÊN CÓ MỨC LƯƠNG THẤP NHẤT (TOÀN CÔNG TY)
    cout << "\nNhân viên có mức lương thấp nhất:\n";
    CNhanVien* NVThapNhat = dsNhanVien[0]; // Giả định nhân viên đầu tiên có lương thấp nhất
    for (int i = 1; i < n; ++i) {
        if (dsNhanVien[i]->TinhLuong() < NVThapNhat->TinhLuong()) {
            NVThapNhat = dsNhanVien[i]; // Cập nhật con trỏ chỉ đến nhân viên có lương thấp hơn
        }
    }
    NVThapNhat->Xuat();

    // TÌM LẬP TRÌNH VIÊN CÓ MỨC LƯƠNG CAO NHẤT
    cout << "\nNhân viên lập trình viên có mức lương cao nhất:\n";
    CLapTrinhVien* NVCaoNhatLapTrinh = nullptr; // Con trỏ lưu vết lập trình viên xuất sắc nhất
    for (int i = 0; i < n; ++i) {
        // Ép kiểu động để lọc ra các đối tượng thuộc lớp CLapTrinhVien
        CLapTrinhVien* lapTrinhVien = dynamic_cast<CLapTrinhVien*>(dsNhanVien[i]);
        if (lapTrinhVien) {
            // Cập nhật nếu đây là LTV đầu tiên tìm thấy HOẶC có lương cao hơn mốc max hiện tại
            if (!NVCaoNhatLapTrinh || lapTrinhVien->TinhLuong() > NVCaoNhatLapTrinh->TinhLuong()) {
                NVCaoNhatLapTrinh = lapTrinhVien;
            }
        }
    }
    if (NVCaoNhatLapTrinh) {
        NVCaoNhatLapTrinh->Xuat();
    } else {
        cout << "Không có nhân viên lập trình viên nào." << endl;
    }

    // TÌM KIỂM CHỨNG VIÊN CÓ MỨC LƯƠNG THẤP NHẤT
    cout << "\nNhân viên kiểm chứng viên có mức lương Thấp nhất:\n";
    CKiemChungVien* NVThapNhatKiemChung = nullptr; // Con trỏ lưu vết kiểm chứng viên có lương thấp nhất
    for (int i = 0; i < n; ++i) {
        // Ép kiểu động để lọc ra các đối tượng thuộc lớp CKiemChungVien
        CKiemChungVien* kiemChungVien = dynamic_cast<CKiemChungVien*>(dsNhanVien[i]);
        if (kiemChungVien) {
            // Cập nhật nếu đây là KCV đầu tiên tìm thấy HOẶC có lương thấp hơn mốc min hiện tại
            if (!NVThapNhatKiemChung || kiemChungVien->TinhLuong() < NVThapNhatKiemChung->TinhLuong()) {
                NVThapNhatKiemChung = kiemChungVien;
            }
        }
    }
    if (NVThapNhatKiemChung) {
        NVThapNhatKiemChung->Xuat();
    } else {
        cout << "Không có nhân viên kiểm chứng viên nào." << endl;
    }

    // GIẢI PHÓNG BỘ NHỚ ĐỘNG
    for (int i = 0; i < n; ++i) {
        delete dsNhanVien[i]; // Giải phóng từng vùng nhớ đối tượng nhân viên cụ thể
    }
    delete[] dsNhanVien; // Giải phóng mảng quản lý các con trỏ

    return 0;
}