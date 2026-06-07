#include "CGiaoDich.h"
#include "CGiaoDichDat.h"
#include "CGiaoDichNhaPho.h"
#include "CGiaoDichCanHoChungCu.h"
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Nhập số lượng giao dịch: ";
    cin >> n;

    // Khởi tạo mảng con trỏ quản lý danh sách giao dịch (Tính đa hình)
    CGiaoDich** dsGiaoDich = new CGiaoDich*[n];
    
    // NHẬP DANH SÁCH GIAO DỊCH
    for (int i = 0; i < n; ++i) {
        int loai;
        cout << "Nhập loại giao dịch (1: Đất, 2: Nhà phố, 3: Căn hộ chung cư): ";
        cin >> loai;

        // Khởi tạo đối tượng tương ứng với loại giao dịch được chọn
        if (loai == 1) {
            dsGiaoDich[i] = new CGiaoDichDat();
        } else if (loai == 2) {
            dsGiaoDich[i] = new CGiaoDichNhaPho();
        } else if (loai == 3) {
            dsGiaoDich[i] = new CGiaoDichCanHoChungCu();
        } else {
            cout << "Loại giao dịch không hợp lệ. Vui lòng nhập lại." << endl;
            --i; // Giảm chỉ số vòng lặp để nhập lại cho vị trí hiện tại
            continue;
        }

        dsGiaoDich[i]->nhap();
    }

    // XUẤT DANH SÁCH GIAO DỊCH VÀ THÀNH TIỀN
    cout << "\nDanh sách giao dịch:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nGiao dịch " << (i + 1) << ":\n";
        dsGiaoDich[i]->xuat();
        cout << "Thành tiền: " << dsGiaoDich[i]->tinhThanhTien() << endl;
    }

    // ĐẾM TỔNG SỐ LƯỢNG TỪNG LOẠI GIAO DỊCH
    cout << "\nTổng số lượng từng loại giao dịch:\n";
    int countDat = 0, countNhaPho = 0, countCanHoChungCu = 0;
    
    for (int i = 0; i < n; ++i) {
        // Sử dụng dynamic_cast để kiểm tra kiểu dữ liệu thực tế tại vùng nhớ
        if (dynamic_cast<CGiaoDichDat*>(dsGiaoDich[i])) {
            countDat++;
        } else if (dynamic_cast<CGiaoDichNhaPho*>(dsGiaoDich[i])) {
            countNhaPho++;
        } else if (dynamic_cast<CGiaoDichCanHoChungCu*>(dsGiaoDich[i])) {
            countCanHoChungCu++;
        }
    }
    cout << "Giao dịch đất: " << countDat << endl;
    cout << "Giao dịch nhà phố: " << countNhaPho << endl;
    cout << "Giao dịch căn hộ chung cư: " << countCanHoChungCu << endl;

    // TÍNH TRUNG BÌNH THÀNH TIỀN CỦA GIAO DỊCH CĂN HỘ CHUNG CƯ
    cout << "\nTrung bình thành tiền của giao dịch Căn hộ chung cư: \n";
    double tongThanhTienCanHoChungCu = 0;
    int dem = 0; // Biến đếm số lượng căn hộ chung cư phục vụ cho phép tính trung bình cộng

    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<CGiaoDichCanHoChungCu*>(dsGiaoDich[i])) {
            tongThanhTienCanHoChungCu += dsGiaoDich[i]->tinhThanhTien();
            dem++;
        }
    }

    // Kiểm tra điều kiện để tránh lỗi chia cho 0 (Division by Zero)
    if (dem > 0) {
        cout << "Trung bình thành tiền: " << tongThanhTienCanHoChungCu / dem << endl;
    } else {
        cout << "Không có giao dịch nào thuộc loại Căn hộ chung cư." << endl;
    }

    // TÌM GIAO DỊCH NHÀ PHỐ CÓ THÀNH TIỀN LỚN NHẤT
    cout << "\nGiao dịch Nhà phố có thành tiền lớn nhất: \n";
    double maxThanhTienNhaPho = 0;
    int indexMaxNhaPho = -1; // Lưu vị trí của giao dịch nhà phố đắt nhất được tìm thấy

    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<CGiaoDichNhaPho*>(dsGiaoDich[i])) {
            double thanhTien = dsGiaoDich[i]->tinhThanhTien();
            // Cập nhật nếu tìm thấy giao dịch nhà phố có thành tiền cao hơn mốc hiện tại
            if (thanhTien > maxThanhTienNhaPho) {
                maxThanhTienNhaPho = thanhTien;
                indexMaxNhaPho = i;
            }
        }
    }
    
    if (indexMaxNhaPho != -1) {
        dsGiaoDich[indexMaxNhaPho]->xuat();
        cout << "Thành tiền: " << maxThanhTienNhaPho << endl;
    } else {
        cout << "Không có giao dịch nào thuộc loại Nhà phố." << endl;
    }

    // LỌC GIAO DỊCH THEO MỐC THỜI GIAN (THÁNG 12 NĂM 2024)
    cout << "\nDanh sách giao dịch của tháng 12 năm 2024:\n";
    bool found = false; // Cờ hiệu kiểm tra xem có tồn tại ít nhất 1 giao dịch thỏa điều kiện không

    for (int i = 0; i < n; ++i) {
        if (dsGiaoDich[i]->getThangGiaoDich() == 12 && dsGiaoDich[i]->getNamGiaoDich() == 2024) {
            dsGiaoDich[i]->xuat();
            cout << "Thành tiền: " << dsGiaoDich[i]->tinhThanhTien() << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Không có giao dịch nào thuộc tháng 12 năm 2024." << endl;
    }
    
    // GIẢI PHÓNG BỘ NHỚ ĐỘNG
    for (int i = 0; i < n; ++i) {
        delete dsGiaoDich[i]; // Giải phóng từng đối tượng giao dịch cụ thể
    }
    delete[] dsGiaoDich; // Giải phóng mảng các con trỏ

    return 0;
}