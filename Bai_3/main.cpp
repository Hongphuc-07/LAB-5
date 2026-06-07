#include "CSinhVien.h"
#include "CSinhVienDaiHoc.h"
#include "CSinhVienCaoDang.h"
#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Nhập số lượng sinh viên: ";
    cin >> n;

    // Khởi tạo mảng con trỏ quản lý danh sách sinh viên (Áp dụng tính đa hình)
    CSinhVien** dsSinhVien = new CSinhVien*[n];

    // NHẬP DANH SÁCH SINH VIÊN
    for (int i = 0; i < n; ++i) {
        int loai;
        cout << "Nhập loại sinh viên (1: Đại học, 2: Cao đẳng): ";
        cin >> loai;

        // Khởi tạo đối tượng tương ứng dựa trên loại sinh viên được chọn
        if (loai == 1) {
            dsSinhVien[i] = new CSinhVienDaiHoc();
        } else if (loai == 2) {
            dsSinhVien[i] = new CSinhVienCaoDang();
        } else {
            cout << "Loại sinh viên không hợp lệ. Vui lòng nhập lại." << endl;
            --i; // Giảm chỉ số vòng lặp để nhập lại cho vị trí hiện tại
            continue;
        }

        dsSinhVien[i]->Nhap();
    }

    // XUẤT TOÀN BỘ DANH SÁCH VÀ TRẠNG THÁI TỐT NGHIỆP
    cout << "\nDanh sách sinh viên:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nSinh viên " << (i + 1) << ":\n";
        dsSinhVien[i]->Xuat();
        
        // Gọi phương thức thuần ảo KiemTraTotNghiep() được override ở các lớp con
        if (dsSinhVien[i]->KiemTraTotNghiep()) {
            cout << "Đủ điều kiện tốt nghiệp." << endl;
        } else {
            cout << "Chưa đủ điều kiện tốt nghiệp." << endl;
        }
    }

    // LỌC DANH SÁCH SINH VIÊN ĐỦ ĐIỀU KIỆN TỐT NGHIỆP
    cout << "\nDanh sách sinh viên đủ điều kiện tốt nghiệp:\n";
    for (int i = 0; i < n; ++i) {
        if (dsSinhVien[i]->KiemTraTotNghiep()) {
            cout << "\nSinh viên " << (i + 1) << ":\n";
            dsSinhVien[i]->Xuat();
        }
    }

    // LỌC DANH SÁCH SINH VIÊN CHƯA ĐỦ ĐIỀU KIỆN TỐT NGHIỆP (TẤT CẢ CÁC HỆ)
    bool CoSinhVienChuaTotNghiep = false; // Cờ hiệu kiểm tra sự tồn tại của sinh viên chưa tốt nghiệp
    cout << "\nDanh sách sinh viên chưa đủ điều kiện tốt nghiệp:\n";
    for (int i = 0; i < n; ++i) {
        if (!dsSinhVien[i]->KiemTraTotNghiep()) {
            cout << "\nSinh viên " << (i + 1) << ":\n";
            dsSinhVien[i]->Xuat();
            CoSinhVienChuaTotNghiep = true; // Dựng cờ khi tìm thấy ít nhất một trường hợp thỏa điều kiện
        }
    }
    if (!CoSinhVienChuaTotNghiep) {
        cout << "Không có sinh viên nào chưa đủ điều kiện tốt nghiệp." << endl;
    }

    // TÌM SINH VIÊN ĐẠI HỌC CÓ ĐIỂM TRUNG BÌNH CAO NHẤT
    CSinhVienDaiHoc* svDaiHocMax = nullptr; // Con trỏ lưu vết sinh viên đại học xuất sắc nhất
    for (int i = 0; i < n; ++i) {
        // Ép kiểu động để lọc và làm việc riêng với thuộc tính của lớp CSinhVienDaiHoc
        CSinhVienDaiHoc* svDaiHoc = dynamic_cast<CSinhVienDaiHoc*>(dsSinhVien[i]);
        if (svDaiHoc) {
            // Cập nhật nếu đây là SV đại học đầu tiên HOẶC có điểm TB lớn hơn mốc max hiện tại
            if (!svDaiHocMax || svDaiHoc->GetDiemTB() > svDaiHocMax->GetDiemTB()) {
                svDaiHocMax = svDaiHoc;
            }
        }
    }

    if (svDaiHocMax) {
        cout << "\nSinh viên đại học có điểm trung bình cao nhất:\n";
        svDaiHocMax->Xuat();
    }
    
    // TÌM SINH VIÊN CAO ĐẲNG CÓ ĐIỂM THI TỐT NGHIỆP CAO NHẤT
    CSinhVienCaoDang* svCaoDangMax = nullptr; // Con trỏ lưu vết sinh viên cao đẳng xuất sắc nhất
    for (int i = 0; i < n; i++) {
        CSinhVienCaoDang* svCaoDang = dynamic_cast<CSinhVienCaoDang*>(dsSinhVien[i]);
        if (svCaoDang) {
            // Cập nhật nếu đây là SV cao đẳng đầu tiên HOẶC có điểm thi tốt nghiệp lớn hơn mốc max hiện tại
            if (!svCaoDangMax || svCaoDang->GetDiemThiTotNghiep() > svCaoDangMax->GetDiemThiTotNghiep()) {
                svCaoDangMax = svCaoDang;
            }
        }
    }

    if (svCaoDangMax) {
        cout << "\nSinh viên cao đẳng có điểm thi tốt nghiệp cao nhất:\n";
        svCaoDangMax->Xuat();
    }

    // LỌC DANH SÁCH SINH VIÊN CAO ĐẲNG CHƯA TỐT NGHIỆP
    bool CoSinhVienCaoDangChuaTotNghiep = false; // Cờ hiệu kiểm tra riêng cho hệ Cao đẳng
    cout << "\nDanh sách sinh viên cao đẳng chưa đủ điều kiện tốt nghiệp:\n";
    for (int i = 0; i < n; ++i) {
        CSinhVienCaoDang* svCaoDang = dynamic_cast<CSinhVienCaoDang*>(dsSinhVien[i]);
        // Điều kiện kết hợp: Phải là hệ Cao đẳng VÀ phải trượt tốt nghiệp
        if (svCaoDang && !svCaoDang->KiemTraTotNghiep()) {
            cout << "\nSinh viên " << (i + 1) << ":\n";
            svCaoDang->Xuat();
            CoSinhVienCaoDangChuaTotNghiep = true;
        }
    }
    if (!CoSinhVienCaoDangChuaTotNghiep) {
        cout << "Không có sinh viên cao đẳng nào chưa đủ điều kiện tốt nghiệp." << endl;
    }

    // LỌC DANH SÁCH SINH VIÊN ĐẠI HỌC CHƯA TỐT NGHIỆP
    bool CoSinhVienDaiHocChuaTotNghiep = false; // Cờ hiệu kiểm tra riêng cho hệ Đại học
    cout << "\nDanh sách sinh viên đại học chưa đủ điều kiện tốt nghiệp: \n";
    for (int i = 0; i < n; ++i){
        CSinhVienDaiHoc* svDaiHoc = dynamic_cast<CSinhVienDaiHoc*>(dsSinhVien[i]);
        // Điều kiện kết hợp: Phải là hệ Đại học VÀ phải trượt tốt nghiệp
        if (svDaiHoc && !svDaiHoc->KiemTraTotNghiep()) {
            cout << "\nSinh viên " << (i + 1) << ":\n";
            svDaiHoc->Xuat();
            CoSinhVienDaiHocChuaTotNghiep = true;
        }
    }
    if (!CoSinhVienDaiHocChuaTotNghiep) {
        cout << "Không có sinh viên đại học nào chưa đủ điều kiện tốt nghiệp." << endl;
    }

    // GIẢI PHÓNG BỘ NHỚ ĐỘNG
    for (int i = 0; i < n; ++i) {
        delete dsSinhVien[i]; // Giải phóng vùng nhớ của từng đối tượng sinh viên cụ thể
    }
    delete[] dsSinhVien; // Giải phóng mảng quản lý các con trỏ

    return 0;
}